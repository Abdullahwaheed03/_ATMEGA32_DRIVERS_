#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#include "MCAL/SPI/SPI_PRIVATE.h"
#include "MCAL/SPI/SPI_CONFIG.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BITMATH.h"
void SPI_INIT(SPI_CONF* CONF);

uint8 SPI_SEND_REC_BYTE(SPI_CONF* CONF , uint8 DATA);



#endif /* SPI_INTERFACE_H_ */
