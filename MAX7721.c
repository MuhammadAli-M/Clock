/*
 * MAX7721.c
 *
 *  Created on: Nov 8, 2018
 *      Author: Muhammad Adam
 */
#include <avr/io.h>
#include "MAX7221.h"
#include "SPI.h"

void MAX7221_Execute(unsigned char command, unsigned char data){
	PORT_SPI &= ~(1<<DD_SS);
	SPI_MasterTransmit(command);
	SPI_MasterTransmit(data);
	PORT_SPI |= (1<<DD_SS);
}

void MAX7221_Init(void){
	// To set the decoding mode for the 7-segment connected to DIG 0,1,2,3.
	// Decoding mode means to send the binary not the segments themselves.
	MAX7221_Execute(SET_DECODING_MODE,0x0F);
	// enable four 7-segment
	MAX7221_Execute(SET_SCAN_LIMIT,0x03);
	MAX7221_Execute(SET_INTENSITY_OF_LIGHT,0x08);
	// to turn on the display of 7-segment connected to DIG 0,1,2,3.
	MAX7221_Execute(TURN_DISPLAY_ON_OFF,0x0F);
}

