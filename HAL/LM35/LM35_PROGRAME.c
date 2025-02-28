/*
 * LM35_PROGRAME.c
 *
 * Created: 10/23/2024 9:11:07 PM
 *  Author: Eng_A
 */ 
#include "HAL/LM35/LM35_INTERFACE.h"

void LM35_INIT(void ) 
{
	INIT_ADC(INT_REF) ;
}
uint16 LM35_GET_READ (ADC_CHANNEL CHANNEL) 
{
	uint16 DATA = ADC_READ(CHANNEL) ;
	return (((DATA*5UL)/1024.0)/0.01) ; 
}