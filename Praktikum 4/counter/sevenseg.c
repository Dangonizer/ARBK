/*
 * sevenseg.c
 *
 * Created: 03/12/2023 15:56:15
 *  Author: Kevin Schier
 */ 
#include "sevenseg.h"
const int binpattern[10]={ 64, 121, 36, 48, 25, 18, 2, 120, 0, 16 }; //binary pattern as int (example pattern for 0: 100 0000 = 64) for number of corresponding index

void print(int number, int place) //number: number to be displayed, place: digit of the number (0,1)
{
	if (place == 0)
		PORTB &= ~(1 << PINB0);
	else if (place == 1)
		PORTB |= (1 << PINB0);
	PORTD = binpattern[number];
	_delay_ms(10);
}
