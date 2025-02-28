
/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 2 - 2023   @ ***********************/
/**************** @ FILE   : TWI_PROGRAM.C   @ ***********************/
/**************** @ BRIEF  :      TWI        @ ***********************/
/*********************************************************************/

#include "LIB/BITMATH.h"
#include "MCAL/I2C/I2C_INTERFACE.h"

void TWI_INIT(uint8 addr)
{
    TWBR = 32 ;
    TWSR = 0 ;
    TWCR  = (1<<TWCR_TWEN) ;
	if (addr)
	{
		TWAR = addr << 1  ;
	}
}

void TWI_START() 
{
     TWCR = (1<<TWCR_TWEN) | (1<<TWCR_TWSTA) |(1<<TWCR_TWINT ) ;
}
void TWI_STOP()
{
	TWCR = (1 << TWSTO) | (1 << TWINT) | (1 << TWEN); // Send stop condition
	while (TWCR & (1 << TWSTO)); // Wait for stop condition to be transmitted
}
void TWI_WAIT_FLAG() 
{
	while(!BIT_GET(TWCR,TWCR_TWINT)) ;

}
void TWI_CLR_FLAG()
{
	TWCR = (1<<TWCR_TWEN) | (1<<TWCR_TWINT)   ;

}
void TWI_SLAVE_SET_ADD(uint8 addr)
{
	TWAR = addr ;
}
void TWI_SEND_ADD(uint8 addr)
{
	   TWDR = addr << 1 ; 
}
void TWI_MASTER_SEND_DATA(uint8 addr, uint8 data)
{

   TWI_START();
   TWI_WAIT_FLAG();
   TWI_SEND_ADD(addr) ;
   TWI_CLR_FLAG() ;
   TWI_WAIT_FLAG();
   TWDR = data ; 
   TWI_CLR_FLAG() ;
   TWI_WAIT_FLAG();
   TWI_STOP();
   
}

uint8 TWI_MSR_READ_DATA(uint8 addr ) 
{
	TWI_START();
	while (!(TWCR & (1 << TWINT))); // Wait for completion
	TWDR = (addr << 1) | 0x01; // Load slave address and R/W bit
	TWDR |= 1 ;
	TWCR = (1 << TWINT) | (1 << TWEN); // Send address
	while (!(TWCR & (1 << TWINT))); // Wait for completion
	uint8 x = TWDR ;
	TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT) ;
	TWI_STOP();
	return x ;
}
