/*
 * Klasse Timer Implementering
 *
 * Styrer intern timer1 i atmega32 processor
 *
 *  Af Bjørn Sørensen
 */ 

#include "Timer.h"

Timer::Timer()
{
	// Set output
	DDRD = 0b00100000;
	
	// Init timer 1 til CTC mode, prescale 1, toggle ved compare match
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001000;
	
	// Øvre grænse for timeren for at lave cirka 120 kHz (122.88 kHz)
	OCR1A = 14;

}

Timer::~Timer()
{
	// Afbryd forbindelse til timer
	TCCR1A = 0b00000000;
	
	// Stop Timer 1
	TCCR1B = 0b00001000;
	
	// Sæt output lavt
	PORTB &= 0b11011111;
	
}

void Timer::start()
{
	// Sæt forbindelse til timer
	TCCR1A = 0b01000000;

	// Start Timer 1 på 120 kHz
	TCCR1B = 0b00001001;
}

void Timer::stop()
{
	// Afbryd forbindelse til timer
	TCCR1A = 0b00000000;

	// Stop Timer 1
	TCCR1B = 0b00001000;

	// Sæt output lavt
	PORTB &= 0b11011111;
}

// Globalt objekt
Timer timer = Timer();