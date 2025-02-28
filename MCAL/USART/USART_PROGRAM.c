#include "MCAL/USART/USART_PRIVATE.h"
#include "MCAL/USART/USART_INTERFACE.h"
#include "LIB/STD_TYPES.h"
#include "util\delay.h"


void USART_INIT(uint16 BAUD)												 
{		
	BIT_SET(UCSRA,1); /* SET U2X DOUBLE TX SPEED */ 					 
	BIT_SET(UCSRB,7); /* ENBALE INT FOR RX       */		
	uint16 UBRR = 0 ;				 					   					 					 
	UBRR =  12 ;
	/*UBRR = (uint16)((1000000/(9600*8))-1);*/
	UBRRL = UBRR ;														 
	UBRRH = (UBRR>>8) ;
	UCSRC |= (1<<7) | (1<<2) | (1<<1) ;		
	BIT_SET(UCSRB,4); /* ENABLE RX               */
	BIT_SET(UCSRB,3); /* ENABLE TX               */														 
																		 
}																		 

void USART_SEND_CHAR(uint8 CHAR)
{
	
	UDR = CHAR ;
	while (!BIT_GET(UCSRA,6));
}

void USART_SEND_STR(uint8* STR) 
{
	uint8 i = 0 ;
	while(STR[i] != '\0')
	{
		USART_SEND_CHAR(STR[i++]);
		_delay_us(100);
	}
	USART_SEND_CHAR('\r');
}


uint8 USART_RECIVE_CHAR() 
{
		while (!BIT_GET(UCSRA,6));
		return UDR ;

}