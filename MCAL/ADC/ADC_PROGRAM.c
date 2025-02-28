/*
@Author : Abdullah waheed
@brief  : ADC Driver for atmega32
@date   : 1/11/2023
*/

#include "MCAL/ADC/ADC_INTERFACE.h"

void INIT_ADC(uint8 ref)
{
	BIT_SET(ADCSRA,ADEN) ; /* ENABLE ADC MODULE */
	BIT_SET(ADCSRA,ADPS0); /* SET PRESCALER TO 2     --- THAT MEANS ADC MODULE FREQ WILL BE F_CPU/PRESCALER  -> F_CPU/2 */
	ADMUX  |= ref ;  /*   SELECT reference  for ADC */
}
uint16 ADC_READ(ADC_CHANNEL channel)
{
	ADMUX &= (7<<5);
	ADMUX |= channel ; /* SELECT CHANNEL YOU WANT TO READ FROM */
	BIT_SET(ADCSRA,ADSC) ; /* START CONVERSATION */
	while(!(1   &  (ADCSRA>>ADIF)));	/* WAIT UNTIL FINISH */
	uint16 result ; /* VARIABLE TO STORE RESULT OF ADC */
	result = ADCL ;
	result |= (ADCH<<8);
	ADMUX =  0 ;
	return result ;
}

