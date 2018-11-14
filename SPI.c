/*
 * SPI.c
 *
 *  Created on: Oct 14, 2018
 *      Author: Muhammad Adam
 */

#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"


void SPI_MasterInit(void)
{
/* Set MOSI and SCK output, all others input */
DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS);
DDR_SPI &= ~(1<<DD_MISO);
/* Enable SPI, Master, set clock rate fck/16 */
SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
}


void SPI_MasterTransmit(char cData)
{
/* Start transmission */
SPDR = cData;
/* Wait for transmission complete */
while(!(SPSR & (1<<SPIF)))
;
}

void SPI_SlaveInit(void)
{
/* Set MISO output, all others input */
DDR_SPI = (1<<DD_MISO);
DDR_SPI &= ~((1<<DD_MOSI)|(1<<DD_SCK)|(1<<DD_SS));
/* Enable SPI */
SPCR = (1<<SPE);
/* Make base clock is high and the sampling edge is trailing so sampling occurs at rising*/
SPCR |= (1<<CPOL)|(1<<CPHA);

}


char SPI_SlaveReceive(void)
{
/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)))
;
/* Return data register */
return SPDR;
}

char SPI_SlaveSendAndReceive(char cData)
{
/* Start transmission */
SPDR = cData;
/* Wait for reception complete */
while(!(SPSR & (1<<SPIF)))
;
/* Return data register */
return SPDR;
}



