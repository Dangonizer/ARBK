/*
 * P2_Polling.c
 *
 * Created: 05/11/2023 16:01:02
 * Author : Kevin Schier
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdbool.h>


int main(void)
{
	DDRC = 0x00;
	PORTC = 0xff;
	DDRD = 0xff;
	PORTD = 0x00;
	bool blink = true;
	bool led0 = false;
	
	
    while (1) 
    {
		if (!((PINC >> PINC0) & 1))
		{
			if (led0)
			{
				blink ^= 1;	
			}
			else
			{
				blink = true;
				led0 = true;	
			}	
		}
		else if (!((PINC >> PINC1) & 1))
		{
			if (!led0)
			{
				blink ^= 1;
			}
			else
			{
				blink = true;
				led0 = false;
			}
		}
		
		if (led0)
		{
			if (blink)
			{
				PORTD &= ~(1 << 1);
				PORTD ^= (1 << 0); 	
			}
			else 
			{
				PORTD &= ~(1 << 1);
				PORTD |= (1 << 0);
			}
		}
		else 
		{
			if (blink)
			{
				PORTD &= ~(1 << 0);
				PORTD ^= (1 << 1);
			}
			else
			{
				PORTD &= ~(1 << 0);
				PORTD |= (1 << 1);

			}
		}
		_delay_ms(200);	
    }
	
}

