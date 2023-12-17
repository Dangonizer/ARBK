/*
 * Praktikum2_Intterupts.c
 *
 * Created: 05/11/2023 18:52:36
 * Author : Kevin Schier
 */ 

#define F_CPU 16000000UL 
#include <avr/io.h> 
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

bool blink = true;                                                                                                                                                                               ;
bool led0 = false;

ISR(INT0_vect)
{
	if(led0)
	{
		blink=!blink;
	}
	else
	{
		blink=true;
		led0=true;
	}
}

ISR(INT1_vect)
{
	if(!led0)
	{
		blink=!blink;
	}
	else
	{
		blink=true;
		led0=false;
	}
}

int main(void)
{
	cli();
	DDRB = 0xff; 
	PORTB = 0x00;		
	DDRD = 0x00;
	PORTD = 0xff; //D2 und D3 Eingänge
	
	EICRA |= 0b1010; //Triggert Interrupt bei sinkender flanke (low active taster)
	EIMSK |= 0b11; //Aktiviert externe Interrupts INT0 und INT1
	sei();
		
    while (1) 
    {
				if (led0)
				{
					if (blink)
					{
						PORTB &= ~(1 << 1);
						PORTB ^= (1 << 0);
					}
					else
					{
						PORTB &= ~(1 << 1);
						PORTB |= (1 << 0);
					}
				}
				else
				{
					if (blink)
					{
						PORTB &= ~(1 << 0);
						PORTB ^= (1 << 1);
					}
					else
					{
						PORTB &= ~(1 << 0);
						PORTB |= (1 << 1);

					}
				}
				_delay_ms(200);
    }
}

//Im Dissasembly enthalten Adresse 02 und 04 jump instructions
//00000000  JMP 0x00000034		Jump 
//00000002  JMP 0x00000053		Jump 
//00000004  JMP 0x00000071		Jump 

//Dort wird der Code der Interrupts ausgeführt. Danach wird vom interrupts returned.
//00000070  RETI 		Interrupt return  