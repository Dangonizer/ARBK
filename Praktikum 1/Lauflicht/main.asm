;
; Lauflicht.asm
;
; Created: 22/10/2023 17:01:45
; Author : Dango
;


; Replace with your application code
.include "m328pdef.inc"
.org 0x000
	jmp start
start:
    ldi r16, LOW(RAMEND)
	out SPL, r16
	ldi r16, HIGH(RAMEND)
	out SPH, r16
	ldi r16, 0b11111111
	out DDRD, r16
	out DDRB, r16
	ldi r16, 1

right_to_left:
	out PORTD, r16
	lsl r16
	rcall delay
	brcc right_to_left
	out PORTD, r16
	ldi r16, 0b00000001
	out PORTB, r16
	lsl r16
	rcall delay
	out PORTB, r16

left_to_right:
	lsr r16
	rcall delay
	out PORTB, r16
	lsr r16
	rcall delay
	out PORTB, r16
	ldi r16, 0b10000000

loop:
	out PORTD, r16
	lsr r16
	rcall delay
	cpi r16, 0b0000001
	brne loop
	jmp right_to_left

delay:
	ldi r17, 23
L1: 
	ldi r18, 255
L2:
	ldi r19, 255
L3:
	dec r19
	brne L3
	dec r18
	brne L2
	dec r17
	brne L1
	ret



		
