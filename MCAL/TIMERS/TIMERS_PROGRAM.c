/*
 * TIMERS_PROGRAM.c
 *
 * Created: 1/21/2025 12:27:38 AM
 *  Author: Eng_A
 */ 

#include "MCAL/TIMERS/TIMERS_INTERFACE.h"
#include "MCAL/DIO/DIO_PRIVATE.h"

static uint32 counter0 = 0 ;
static uint32 counter2 = 0 ;

void (*TIMER0_CALLBACK_PTR) (void)  = NULL_PTR ;
void (*TIMER1_CALLBACK_PTR) (void)  = NULL_PTR ;
void (*TIMER2_CALLBACK_PTR) (void)  = NULL_PTR ;

void TIMER0_INIT(TIMER_CONFIG *CONF) 
{
	
     if ( CONF->MODE == PWM || CONF->MODE == PWM_PHASE_CORRECT)
	 { 
		 BIT_CLR(TCCR0,7) ;
	 }
	 else 
	 {
		 BIT_SET(TCCR0,7) ;
	 }
	 switch (CONF->MODE)
	 {
		 case OV_MODE : BIT_CLR(TCCR0,3) ; BIT_CLR(TCCR0,6) ; TIMSK &= ~(3<<0); BIT_SET(TIMSK,0);  break ; 
		 case PWM_PHASE_CORRECT : BIT_CLR(TCCR0,3) ; BIT_SET(TCCR0,6) ; break ; 
		 case CTC : BIT_SET(TCCR0,3) ; BIT_CLR(TCCR0,6) ; TIMSK &= ~(3<<0); BIT_SET(TIMSK,1); break ; 
		 case PWM : BIT_SET(TCCR0,3) ; BIT_SET(TCCR0,6) ; break ; 
	 }
	 
	 TCCR0 &= ~7;
	 TCCR0 |= CONF->CLOCK ;
	 
	 switch(CONF->STATE)
	 {
		 case NC : TCCR0 &= ~(3 << 4) ; break ; 
		 case TGL :  TCCR0 &= ~(3 << 4) ; BIT_SET(TCCR0,4) ;   DIO_ENUM_SET_PIN_DIR(PORTB,PIN3,OUTPUT); break ; 
		 case CLEAR  :  TCCR0 &= ~(3 << 4) ; BIT_SET(TCCR0,5);     DIO_ENUM_SET_PIN_DIR(PORTB,PIN3,OUTPUT); break ;
		 case SET :  TCCR0 |= (3 << 4) ;    DIO_ENUM_SET_PIN_DIR(PORTB,PIN3,OUTPUT); break ; 
	 }
	 
}

void TIMER0_SET_COUNTER(uint8 value) {
	TCNT0 = value ;
}

void TIMER0_SET_COMPARE(uint8 value ) 
{
	OCR0 = value ; 
}

void TIMER0_DEINIT(void) 
{
	OCR0 = 0 ;
	TCNT0 = 0 ;
	TCCR0 = 0 ;
	TIMSK &= ~(3<<0); 
}



uint32 TIMER0_TIME(void)
{
	static bool FLAG = FALSE ;
    
    if (FLAG == FALSE )
	{
		GIE_VID_ENABLE();
		TIMER_CONFIG TIME = {CTC,CPU_CLK,NC} ;
		TIMER0_INIT(&TIME); 
		TIMER0_CALLBACK_PTR = SW_COUNTER0 ; 
		TIMER0_SET_COMPARE(249) ;
		FLAG = TRUE ;
	}
	
	return counter0/4 ; 
}

void SW_COUNTER0()
{
	counter0++ ; 
}


void TIMER0_SET_CALLBACK( void (*ptr)(void) )
{
	TIMER0_CALLBACK_PTR = ptr ;
	
}









void TIMER1_INIT(TIMER1_CONFIG *CONF) 
{
	TCCR1A = 0 ;
	TCCR1B = 0 ;
	switch(CONF->MODE)
	{
		case OV_MODE : TIMSK |= (1<<2); break ;
		case CTC :TIMSK |= (1<<3); TIMSK |= (1<<4);  BIT_SET(TCCR1B,3) ; break ;
		case PWM :  TCCR1A |= (3<<0) ; TCCR1B |=(1<<3) ; break ;
	}
	
    
    switch (CONF -> CHANNELS )
    {
		case NONE : break ; 
	    case OC1A : BIT_SET(DDRD_,5); break ;
	    case OC1B : BIT_SET(DDRD_,4); break ;
	    case BOTH : DDRD_ |= (3<<4); break ;
	    
    }
    switch (CONF -> STATE_1)
    {
	    case NC : TCCR1A &= ~(3 << 6) ; break ;
	    case TGL :  TCCR1A &= ~(3 << 6) ; BIT_SET(TCCR1A,6) ;   break ;
	    case CLEAR  :  TCCR1A &= ~(3 << 6) ; BIT_SET(TCCR1A,7);      break ;
	    case SET :  TCCR1A |= (3 << 6) ;     break ;
    }
    switch (CONF -> STATE_2)
    {
	    case NC : TCCR1A &= ~(3 << 4) ; break ;
	    case TGL :  TCCR1A &= ~(3 << 4) ; BIT_SET(TCCR1A,4) ;   break ;
	    case CLEAR  :  TCCR1A &= ~(3 << 4) ; BIT_SET(TCCR1A,5);      break ;
	    case SET :  TCCR1A |= (3 << 4) ;     break ;
    }
    
	TCCR1B &= ~(7<<0) ;
	TCCR1B |= (CONF -> CLOCK<<0) ;
	
}


void TIMER1_SET_COUNTER(uint16 value) 
{
	TCNT1 = value ;
}

void TIMER1_SET_COMPARE_A(uint16 value ) 
{
	OCR1A  = value ;
}

void TIMER1_SET_COMPARE_B(uint16 value )
{
	OCR1B  = value ;
}

void TIMER1_DEINIT(void) 
{
	TCCR1A = 0 ;
	TCCR1B = 0 ;
	TCNT1 = 0 ; 
	OCR1A = 0 ;
	OCR1B = 0 ;
	ICR1 = 0 ;
	TIMSK &= ~(15<<2); 
}

void TIMER1_SET_CALLBACK( void (*ptr)(void) )
{
		TIMER1_CALLBACK_PTR = ptr ;
}












void TIMER2_INIT(TIMER_CONFIG *CONF)
{
	
	if ( CONF->MODE == PWM || CONF->MODE == PWM_PHASE_CORRECT)
	{
		BIT_CLR(TCCR2,7) ;
	}
	else
	{
		BIT_SET(TCCR2,7) ;
	}
	switch (CONF->MODE)
	{
		case OV_MODE :           BIT_CLR(TCCR2,3) ; BIT_CLR(TCCR2,6) ; TIMSK &= ~(3<<6); BIT_SET(TIMSK,6); break ;
		case PWM_PHASE_CORRECT : BIT_CLR(TCCR2,3) ; BIT_SET(TCCR2,6) ;                                     break ;
		case CTC :               BIT_SET(TCCR2,3) ; BIT_CLR(TCCR2,6) ; TIMSK &= ~(3<<6); BIT_SET(TIMSK,7); break ;
		case PWM :               BIT_SET(TCCR2,3) ; BIT_SET(TCCR2,6) ;                                     break ;
	}
	
	TCCR2 &= ~7;
	TCCR2 |= CONF->CLOCK ;
	
	switch(CONF->STATE)
	{
		case NC :      TCCR2 &= ~(3 << 4) ; break ;
		case TGL :      TCCR2 &= ~(3 << 4) ;    BIT_SET(TCCR2,4) ;    DIO_ENUM_SET_PIN_DIR(PORTD,PIN7,OUTPUT); break ;
		case CLEAR  :  TCCR2 &= ~(3 << 4) ; BIT_SET(TCCR2,5);     DIO_ENUM_SET_PIN_DIR(PORTD,PIN7,OUTPUT); break ;
		case SET :  TCCR2 |= (3 << 4) ;                           DIO_ENUM_SET_PIN_DIR(PORTB,PIN3,OUTPUT); break ;
	}
	
}

void TIMER2_SET_COUNTER(uint8 value) {
	TCNT2 = value ;
}

void TIMER2_SET_COMPARE(uint8 value )
{
	OCR2 = value ;
}

void TIMER2_DEINIT(void)
{
	OCR2 = 0 ;
	TCCR2 = 0 ;
	TCNT2 = 0 ;
	TIMSK &= ~(3<<0);
}



uint32 TIMER2_TIME(void)
{
	static bool FLAG = FALSE ;
	
	if (FLAG == FALSE )
	{
		GIE_VID_ENABLE();
		TIMER_CONFIG TIME = {CTC,CPU_CLK,NC} ;
		TIMER2_INIT(&TIME);
		TIMER2_CALLBACK_PTR = SW_COUNTER2 ;
		TIMER2_SET_COMPARE(249) ;
		FLAG = TRUE ;
	}
	
	return counter2/4 ;
}

void SW_COUNTER2()
{
	counter2++ ;
}

void TIMER2_SET_CALLBACK( void (*ptr)(void) )
{
	TIMER2_CALLBACK_PTR = ptr ;
	
}



void WD_TIMER_ON(WD_TIMER_CLK CLK) 
{
	WDTCR |= (CLK<<0) ;
	WDTCR |= (1<<3) ;
}

void WD_TIMER_OFF()
{
	
	WDTCR |= (3<<3) ;
	WDTCR &= ~(1<<3) ;
}




/*TIMER0 Normal Mode ISR*/
void __vector_11 (void)		__attribute__((signal)) ;
void __vector_11 (void)
{
  
  if ( TIMER0_CALLBACK_PTR != NULL_PTR )
  {
	  TIMER0_CALLBACK_PTR() ;

  }

}




/*TIMER0 CTC Mode ISR*/
void __vector_10 (void)		__attribute__((signal)) ;
void __vector_10 (void)
{
  
  if ( TIMER0_CALLBACK_PTR != NULL_PTR )
  {
	  TIMER0_CALLBACK_PTR() ;

  }

}

/*TIMER1 Normal Mode ISR*/
void __vector_9 (void)		__attribute__((signal)) ;
void __vector_9 (void)
{
   
     if ( TIMER1_CALLBACK_PTR != NULL_PTR )
     {
	     TIMER1_CALLBACK_PTR() ;

     }
}

/*TIMER1 CTCB Mode ISR*/
void __vector_8 (void)		__attribute__((signal)) ;
void __vector_8 (void)
{
       if ( TIMER1_CALLBACK_PTR != NULL_PTR )
       {
	       TIMER1_CALLBACK_PTR() ;

       }
}

/*TIMER1 CTCA Mode ISR*/
void __vector_7 (void)		__attribute__((signal)) ;
void __vector_7 (void)
{
 if ( TIMER1_CALLBACK_PTR != NULL_PTR )
 {
	 TIMER1_CALLBACK_PTR() ;

 }
}

/*TIMER1 ICU ISR*/
void __vector_6 (void)		__attribute__((signal)) ;
void __vector_6 (void)
{
 if ( TIMER1_CALLBACK_PTR != NULL_PTR )
 {
	 TIMER1_CALLBACK_PTR() ;

 }
}

/*TIMER2 Normal Mode ISR*/
void __vector_5 (void)		__attribute__((signal)) ;
void __vector_5 (void)
{
       if ( TIMER2_CALLBACK_PTR != NULL_PTR )
       {
	       TIMER2_CALLBACK_PTR() ;

       }
}

/*TIMER2 CTC Mode ISR*/
void __vector_4 (void)		__attribute__((signal)) ;
void __vector_4 (void)
{
       if ( TIMER2_CALLBACK_PTR != NULL_PTR )
       {
	       TIMER2_CALLBACK_PTR() ;

       }
}