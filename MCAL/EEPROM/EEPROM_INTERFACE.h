#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#include "LIB/STD_TYPES.h"


void EEPROM_WRITE(uint16 ADDR , uint8 DATA) ;

uint8 EEPROM_READ(uint8 ADDR) ;


#endif /* EEPROM_INTERFACE_H_ */
