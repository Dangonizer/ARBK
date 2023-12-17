/*
 * Praktikum_3.c
 *
 * Created: 18/11/2023 17:35:05
 * Author : Kevin Schier
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint32_t systemClock = 0;

ISR(TIMER0_COMPA_vect){
	systemClock++;
}

void waitFor(uint32_t ms){
	uint32_t time = systemClock + ms;
	while(!(systemClock == time)){
	}
}

void waitUntil(uint32_t ms){
	while(systemClock < ms){	
	}
}

int main(void)
{
	cli();
	DDRD = 0xff;
	PORTD = 0x00;
	//Set timer mode to clear timer on compare match
	TCCR0A = (1 << WGM01);
	//Set clock source in timer counter control register as clkio/64
	TCCR0B = (1 << CS01) | (1 << CS00);
	//set output compare register: 16 000 000 / 64 * 1/s * 0,001 s = 250
	OCR0A = 249;	
	//enable output compare interrupt für ocr0a	in timer interrupt mask						
	TIMSK0 = (1 << OCIE0A);
	systemClock = 4294967295 - 3000;
	sei();
	waitUntil(4294967295 - 1000);
    while (1) 
    {
		PORTD ^= 1;
		waitFor(2000);
    }
}
//a) Zeigt compiler dass sich variabel unerwartet ändern kann -> wird nicht optimiert -> verhindert inkorrektes verhalten wenn variabel in unterschiedlichen threads oder interrupts verändert wird
//b)4294967295 ms = 49,71 Tage
//c)while schleife fragt den zielwert genau ab (kein < oder >). Selbst wenn time overflowed wird nicht frühzeit abgebrochen. Alternativ: fallunterscheidung mit if und falls nötig zurücksetzen des timers
//d)Datentyp mit größerem wertebereich wählen (64 bit int)