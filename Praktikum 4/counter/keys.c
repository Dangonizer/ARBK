/*
 * keys.c
 *
 * Created: 03/12/2023 16:04:44
 *  Author: Dango
 */ 

#include "keys.h"

void init()
{
	cli();
	
	DDRD=0xff; // Sevenssegment Output
	//PORTD= (1<<PIND0);
	
	DDRB=0x01;	//B0 = Signal A -> Switch between pos 0 und 1
	PORTB |= (1<< PINB1) | (1<<PINB2); // Activate pullup for B1 and B2 (Switches)
	
	PCICR |= 0x01; // Enable interrupt
	PCMSK0|=(1 << PINB1) | (1 << PINB2); // Set interrupt controllmask
	
	sei();
}
