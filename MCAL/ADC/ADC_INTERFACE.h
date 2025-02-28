
/*
@Author : Abdullah waheed
@brief  : ADC Driver for atmega32
@date   : 1/11/2023

*/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/****************** START OF  INC SECTION ************************/
#include "LIB/BITMATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/ADC/ADC_CONFIG.h"
#include "MCAL/ADC/ADC_PRIVATE.h"
/****************** END  OF  INC SECTION ************************/


void INIT_ADC(uint8 ref);

uint16 ADC_READ(ADC_CHANNEL channel);











#endif /* ADC_INTERFACE_H_ */