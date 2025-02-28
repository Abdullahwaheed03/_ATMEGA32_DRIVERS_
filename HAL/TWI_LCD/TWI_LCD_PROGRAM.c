
#include "HAL/TWI_LCD/TWI_LCD_INTERFACE.h"
#include "HAL/TWI_LCD/TWI_LCD_PRIVATE.h"



void TWI_LCD_CMD(uint8 ADDR,uint8 CMD)
{
	TWI_MASTER_SEND_DATA(ADDR,(CMD & 0XF0) | (1<<3));
	_delay_ms(1);
	TWI_MASTER_SEND_DATA(ADDR,(CMD & 0XF0));
	TWI_MASTER_SEND_DATA(ADDR,((CMD & 0x0F)<<4)|(1<<3));
	_delay_ms(1);
	TWI_MASTER_SEND_DATA(ADDR,((CMD & 0X0F)<<4));
}

void TWI_LCD_INIT(uint8 ADDR)
{
	TWI_INIT(0);
	TWI_LCD_CMD(ADDR,RETURN_HOME);
	TWI_LCD_CMD(ADDR,LCD_4BIT_MODE);
	TWI_LCD_CMD(ADDR,LCD_DISPLAY_ON_CURSOR_ON);
	TWI_LCD_CMD(ADDR,LCD_CLR) ;
	TWI_LCD_CMD(ADDR,CURSOR_BLINK);
}



void TWI_LCD_WRITE_CHAR(uint8 ADDR,uint8 DATA)
{
		TWI_MASTER_SEND_DATA(ADDR,(DATA & 0XF0) | (1<<3) |(1<<1));
		TWI_MASTER_SEND_DATA(ADDR,(DATA & 0XF0));
		TWI_MASTER_SEND_DATA(ADDR,((DATA & 0x0F)<<4)|(1<<3) |  (1<<1) );
		TWI_MASTER_SEND_DATA(ADDR,((DATA & 0X0F)<<4)|(1<<1) );
}

void TWI_LCD_WRITE_STR(uint8 ADDR,uint8 *DATA)
{
   for(uint8 temp = 0 ; DATA[temp] != '\0' ; temp++)
   TWI_LCD_WRITE_CHAR(ADDR,DATA[temp]);
}

void TWI_LCD_WRITE_NUM(uint8 ADDR,sint16 DATA)
{

		char data[10] ;
		itoa(DATA,data,10);
		TWI_LCD_WRITE_STR(ADDR,data) ;

}


void TWI_LCD_SET_CURSOR(uint8 ADDR, uint8 ROW , uint8 COLOM)
{
		switch (ROW)
		{
			case 0 : TWI_LCD_CMD(ADDR,0X80 + COLOM) ; break;
			case 1 : TWI_LCD_CMD(ADDR,0XC0 + COLOM) ; break;
			case 2 : TWI_LCD_CMD(ADDR,0X94 + COLOM) ; break;
			case 3 : TWI_LCD_CMD(ADDR,0XD4 + COLOM) ; break;
		}
}