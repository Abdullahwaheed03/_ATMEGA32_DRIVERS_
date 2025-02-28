/*
 * TIMER_CONFIG.h
 *
 * Created: 1/21/2025 12:27:04 AM
 *  Author: Eng_A
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


typedef enum {
 OV_MODE,
 PWM_PHASE_CORRECT,
 CTC,
 PWM,
}MODES;




typedef enum {
	NC,
	SET,
	CLEAR,
	TGL
	}OC_STATE;

typedef enum {
	CPU_CLK=1,
	FCPU_D8,
	FCPU_D64,
	FCPU_D256,
	FCPU_D1024,
	}TIMER_CLK;

typedef enum {
  NONE,
  OC1A ,
  OC1B ,
  BOTH ,
}OC_CHN;

typedef struct {
	MODES MODE ;
	TIMER_CLK CLOCK ;
	OC_STATE STATE ;
}TIMER_CONFIG;


typedef struct {
	MODES MODE ;
	TIMER_CLK CLOCK ;
	OC_CHN CHANNELS ;
	OC_STATE STATE_1 ;
	OC_STATE STATE_2 ;
}TIMER1_CONFIG;


typedef enum {
	D16,
	D32,
	D64,
	D128,
	D256,
	D512,
	D1024,
	D2048,
}WD_TIMER_CLK;


#endif /* TIMER_CONFIG_H_ */