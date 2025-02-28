/*
 * LM35_INTERFACE.h
 *
 * Created: 10/23/2024 9:10:51 PM
 *  Author: Eng_A
 */ 


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#include "MCAL/ADC/ADC_INTERFACE.h"


void LM35_INIT(void ) ;
uint16 LM35_GET_READ (ADC_CHANNEL CHANNEL) ;

#endif /* LM35_INTERFACE_H_ */