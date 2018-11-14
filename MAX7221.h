/*
 * MAX7221.h
 *
 *  Created on: Nov 8, 2018
 *      Author: Muhammad Adam
 */

#ifndef MAX7221_H_
#define MAX7221_H_

#define SET_VALUE_OF_DIGIT_0 (0x01)
#define SET_VALUE_OF_DIGIT_1 (0x02)
#define SET_VALUE_OF_DIGIT_2 (0x03)
#define SET_VALUE_OF_DIGIT_3 (0x04)
#define SET_VALUE_OF_DIGIT_4 (0x05)
#define SET_VALUE_OF_DIGIT_5 (0x06)
#define SET_VALUE_OF_DIGIT_6 (0x07)
#define SET_VALUE_OF_DIGIT_7 (0x08)
#define SET_DECODING_MODE (0x09)
#define SET_INTENSITY_OF_LIGHT (0x0A)
#define SET_SCAN_LIMIT (0x0B)
#define TURN_DISPLAY_ON_OFF (0x0C)
#define DISPLAY_TEST (0x0F)


void MAX7221_Execute(unsigned char command, unsigned char data);
void MAX7221_Init(void);

#endif /* MAX7221_H_ */
