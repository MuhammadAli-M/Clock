/*
 * SPI_MC1.c
 *
 *  Created on: Oct 14, 2018
 *      Author: Muhammad Adam
 */

#include <avr/io.h>
#include "avr/interrupt.h"

#include "SPI.h"
#include "MAX7221.h"
#include "Timers.h"

volatile int timerFlag = 0;

int main(void)
{
	unsigned char seconds = 0;
	unsigned char minutes = 0;
	//enable general interrupts
	SREG |= (1<<7);

	SPI_MasterInit();
	MAX7221_Init();
	TIMER_Init();

	while(1){

		MAX7221_Execute(SET_VALUE_OF_DIGIT_3,seconds%10);
		MAX7221_Execute(SET_VALUE_OF_DIGIT_2,seconds/10);
		MAX7221_Execute(SET_VALUE_OF_DIGIT_1,minutes%10);
		MAX7221_Execute(SET_VALUE_OF_DIGIT_0,minutes/10);

		if (timerFlag >= 4){
		if (seconds >= 59){
			seconds = 0;
			minutes++;
		}
		if (minutes >= 59){
			minutes = 0;
		}
		seconds++;
		TCNT0 = 0x06;	// reset timer0 to its initial value
		timerFlag = 0;
	}
	}
}


ISR(TIMER0_OVF_vect){
	timerFlag ++;
}


