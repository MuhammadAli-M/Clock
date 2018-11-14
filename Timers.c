/*
 * Timers.c
 *
 *  Created on: Nov 10, 2018
 *      Author: Muhammad Adam
 */
#include <avr/io.h>
#include "Timers.h"


void TIMER_Init(void){
	// for 250 counts (from 0x06 to 0xFF+1)
	TCNT0 = 0x06;
	TCCR0 |= (1<<FOC0);
	// enable overflow interrupt
	TIMSK |= (1<<TOIE0);
	// Normal mode
	TCCR0 &= ~((1<<WGM00) | (1<<WGM01));
	// 1024 prescaler
	TCCR0 |= (1<<CS00) | (1<<CS02) ;
	TCCR0 &= ~(1<<CS01);

}



