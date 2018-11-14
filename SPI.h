/*
 * SPI.h
 *
 *  Created on: Oct 14, 2018
 *      Author: Muhammad Adam
 */

#ifndef SPI_H_
#define SPI_H_

#define DDR_SPI DDRB
#define PORT_SPI PORTB
#define DD_SS 	PB4
#define DD_MOSI PB5
#define DD_MISO PB6
#define DD_SCK 	PB7


void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);
void SPI_SlaveInit(void);
char SPI_SlaveReceive(void);
char SPI_SlaveSendAndReceive(char cData);


#endif /* SPI_H_ */
