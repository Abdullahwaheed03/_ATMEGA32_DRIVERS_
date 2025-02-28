/*
 * TIMERS_INTERFACE.h
 *
 * Created: 1/21/2025 12:26:53 AM
 *  Author: Eng_A
 */ 


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#include "MCAL/DIO/DIO_INTERFACE.h"
#include "MCAL/TIMERS/TIMERS_PRIVATE.h"
#include "MCAL/TIMERS/TIMERS_CONFIG.h"
#include "MCAL/GIE/GIE_INTERFACE.h"

#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"


void TIMER0_INIT(TIMER_CONFIG *CONF) ;

void TIMER0_SET_COUNTER(uint8 value) ;

void TIMER0_SET_COMPARE(uint8 value ) ;

void TIMER0_DEINIT(void) ;

void TIMER0_SET_CALLBACK( void (*ptr)(void) );

uint32 TIMER0_TIME(void);

void SW_COUNTER0();




void TIMER1_INIT(TIMER1_CONFIG *CONF) ;

void TIMER1_SET_COUNTER(uint16 value) ;

void TIMER1_SET_COMPARE_A(uint16 value ) ;

void TIMER1_SET_COMPARE_B(uint16 value ) ;

void TIMER1_DEINIT(void) ;

void TIMER1_SET_CALLBACK( void (*ptr)(void) );



void TIMER2_INIT(TIMER_CONFIG *CONF) ;

void TIMER2_SET_COUNTER(uint8 value) ;

void TIMER2_SET_COMPARE(uint8 value ) ;

void TIMER2_DEINIT(void) ;

void TIMER2_SET_CALLBACK( void (*ptr)(void) );

uint32 TIMER2_TIME(void);

void SW_COUNTER2();


void WD_TIMER_ON(WD_TIMER_CLK CLK) ;

void WD_TIMER_OFF() ;


#endif /* TIMERS_INTERFACE_H_ */