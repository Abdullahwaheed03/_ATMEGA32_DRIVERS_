/*
 * ADC_PRIVATE.h
 *
 * Created: 10/23/2024 8:52:05 PM
 *  Author: Eng_A
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define  ADMUX   (*((volatile uint8*)0X27))
#define  ADCSRA  (*((volatile uint8*)0X26))
#define  ADCH    (*((volatile uint8*)0X25))
#define  ADCL    (*((volatile uint8*)0X24))


#endif /* ADC_PRIVATE_H_ */