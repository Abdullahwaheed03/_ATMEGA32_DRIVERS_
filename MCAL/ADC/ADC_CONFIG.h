/*
 * ADC_CONFIG.h
 *
 * Created: 10/23/2024 8:51:57 PM
 *  Author: Eng_A
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


#define EXT_REF 0
#define INT_REF 0XC0



typedef enum 
{
	 A0,
	 A1,
	 A2,
	 A3,
	 A4,
	 A5,
	 A6,
	 A7
	}ADC_CHANNEL;









/**************** ADMUX BITS **************/
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4


#define ADLAR 5

#define REFS0 6
#define REFS1 7


/************ ADCSRA BITS ***************/

#define ADPS0  0
#define ADPS1  1
#define ADPS2  2


#define ADIE   3
#define ADIF   4 
#define ADATE  5
#define ADSC   6

#define ADEN   7





#endif /* ADC_CONFIG_H_ */