#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "LIB/STD_TYPES.h"



void USART_INIT(uint16 BAUD);

void USART_SEND_CHAR(uint8 CHAR);

void USART_SEND_STR(uint8* STR) ;

uint8* USART_RECIVE_STR() ;

uint8 USART_RECIVE_CHAR() ;

#endif /* USART_INTERFACE_H_ */
