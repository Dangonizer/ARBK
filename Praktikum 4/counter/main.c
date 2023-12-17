/*
 * counter.c
 *
 * Created: 03/12/2023 15:50:23
 * Author : Dango
 */ 

#include "keys.h"
#include "sevenseg.h"
#include <avr/io.h>

volatile uint32_t counter = 0;

ISR(PCINT0_vect)
{
	if(!(PINB&(1<<PINB1)))
	{
		if(counter == 0)
		{
			counter= 99; 
		}
		else
		counter--;
	}
	if(!(PINB&(1<<PINB2)))
	{
		if(counter == 99)
		{
			counter = 0;  
		}
		else
		counter++;
	}
}

int main(void)
{
	init();
	
	while (1)
	{
		int digit0 = counter % 10; // Get first digit by using Modulo
		int digit1 = (counter - digit0) / 10 ; //Get second digit by removing first digit and dividing by 10
		
		print(digit0,0);
		print(digit1,1);
	}
}

