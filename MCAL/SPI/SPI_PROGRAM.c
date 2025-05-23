#include "MCAL/SPI/SPI_INTERFACE.h"

void SPI_INIT(SPI_CONF* CONF)
{
	#if SPI_INT == 1 
    BIT_SET(SPCR,7);
	#endif
	SPCR = ((CONF->ORDER) << 5) | ((CONF->M) << 4) | ((CONF->CPOL) << 3) | ((CONF->CPHA) << 2) | (BIT_GET(CONF->FREQ,1) << 1)| (BIT_GET(CONF->FREQ,0) << 0) ;
	SPSR |= (BIT_GET(CONF->FREQ,2)<<0) ;
	
	if (CONF->M == MASTER)
	{
	DIO_ENUM_SET_PIN_DIR(CONF->SS_PORT,CONF->SS_PIN,OUTPUT);
	DIO_ENUM_SET_PIN_DIR(PORTB,PIN5,OUTPUT);
	DIO_ENUM_SET_PIN_DIR(PORTB,PIN6,INPUT);
	DIO_ENUM_SET_PIN_DIR(PORTB,PIN7,OUTPUT);
	DIO_ENUM_SET_PIN_VAL(CONF->SS_PORT,CONF->SS_PIN,HIGH);	
	}

	else if (CONF->M == SLAVE)
{
	DIO_ENUM_SET_PIN_DIR(CONF->SS_PORT,CONF->SS_PIN,INPUT);
	DIO_ENUM_SET_PIN_DIR(PORTB,PIN5,INPUT);
	DIO_ENUM_SET_PIN_DIR(PORTB,PIN6,OUTPUT);
	DIO_ENUM_SET_PIN_DIR(PORTB,PIN7,INPUT);
}
	BIT_SET(SPCR,6) ; 

}

uint8 SPI_SEND_REC_BYTE(SPI_CONF* CONF , uint8 DATA) 
{
	uint8 temp ; 
	if (CONF->M == MASTER )
	{
			DIO_ENUM_SET_PIN_VAL(CONF->SS_PORT,CONF->SS_PIN,LOW);
			SPDR = DATA ;
			while(! BIT_GET(SPSR,7));
			DIO_ENUM_SET_PIN_VAL(CONF->SS_PORT,CONF->SS_PIN,HIGH);
	}
    else if (CONF->M == SLAVE)
	{
     	SPDR = DATA ;
     	while(! BIT_GET(SPSR,7));
	}
	
	return SPDR ;
}

