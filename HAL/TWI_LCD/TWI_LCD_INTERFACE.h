#ifndef TWI_LCD_INTERFACE_H_
#define TWI_LCD_INTERFACE_H_

#include "util/delay.h"
#include "MCAL/I2C/I2C_INTERFACE.h"
#include "LIB/BITMATH.h"

void TWI_LCD_CMD(uint8 ADDR,uint8 CMD);


void TWI_LCD_INIT(uint8 ADDR);


void TWI_LCD_WRITE_CHAR(uint8 ADDR,uint8 DATA);

void TWI_LCD_WRITE_STR(uint8 ADDR,uint8 *DATA);

void TWI_LCD_WRITE_NUM(uint8 ADDR,sint16 DATA);


void TWI_LCD_SET_CURSOR(uint8 ADDR, uint8 ROW , uint8 COLOM);
#endif /* TWI_LCD_INTERFACE_H_ */
