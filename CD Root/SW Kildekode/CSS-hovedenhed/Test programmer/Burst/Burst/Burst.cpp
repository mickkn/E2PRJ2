/*
 * Burst.cpp
 *
 * Created: 13-05-2014 21:16:28
 *  Author: Bjørn
 */ 

#define F_CPU 3686400

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR (INT0_vect) {
	
	// Start Timer 1 på 120 kHz
	TCCR1B = 0b00001001;
	
	// Vent 1 ms
	_delay_ms(1);
	
	// Stop Timer 1
	TCCR1B = 0b00001000;
}

int main(void)
{
	// Initialiser OC1A (PD5) som output
	//             INT0 (PD2) som input
	DDRD = 0b00100000;
	
	// Init timer 1 til CTC mode, prescale 1, toggle ved compare match
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001000;
	
    // Øvre grænse for timeren for at lave cirka 120 kHz (122.88 kHz)
    OCR1A = 14;
	  
	// Global interrupt enable
	sei();
		
	// Enable INT0
	GICR |= 0b01000000;
		
	// INT0 on change
	MCUCR |= 0b00000001;
	
	while(1);
	
	return 0;
}