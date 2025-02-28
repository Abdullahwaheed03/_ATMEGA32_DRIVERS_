/*********************************************************************/
/**************** @ AUTHOR : Abdullah waheed @ ***********************/
/**************** @ DATE   : 26 - 2 - 2023   @ ***********************/
/**************** @ FILE   : TWI_INTERFACE.h @ ***********************/
/**************** @ BRIEF  :      TWI        @ ***********************/
/*********************************************************************/


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/I2C/I2C_PRIVATE.h"



void TWI_INIT(uint8 addr);

void TWI_START();

void TWI_STOP();

void TWI_WAIT_FLAG();

void TWI_CLR_FLAG();

void TWI_SLAVE_SET_ADD(uint8 addr);

void TWI_SEND_ADD(uint8 addr);

void TWI_MASTER_SEND_DATA(uint8 addr, uint8 data );

uint8 TWI_MSR_READ_DATA(uint8 addr );


#endif /* I2C_INTERFACE_H_ */