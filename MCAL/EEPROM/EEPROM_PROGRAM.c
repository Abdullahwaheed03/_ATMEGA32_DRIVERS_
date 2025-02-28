#include "MCAL/EEPROM/EEPROM_INTERFACE.h"
#include "MCAL/EEPROM/EEPROM_PRIVATE.h"
#include "util/delay.h"


void EEPROM_WRITE(uint16 ADDR , uint8 DATA) 
{
	while(BIT_GET(EECR,1));
	EEAR = ADDR ;
	EEDR = DATA ;
	EECR |= (1<<2) ;
	EECR |= (1<<1) ;
	_delay_ms(10);
}

uint8 EEPROM_READ(uint8 ADDR) 
{
	EEAR |= ADDR ;
	EECR |= (1<<0);
	while (BIT_GET(EECR,0));
	return EEDR ;
	
}

