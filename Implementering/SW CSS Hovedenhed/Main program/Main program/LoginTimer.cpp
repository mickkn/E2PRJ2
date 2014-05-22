/*
 * Implementering af klasse LoginTimer
 *
 * Login timer som tæller ned når et login er aktivt og giver PC besked når tiden er udløbet
 *
 * Af Bjørn Sørensen
 *
 */


#include "LoginTimer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

LoginTimer::LoginTimer( )
{
	// Init ovfCount
	ovfCount_ = 0;
	
	// Stop timer
	stop();
}

LoginTimer::~LoginTimer( )
{
	// Stop timer
	stop();
}

// Start og initialiser nedtælling
void LoginTimer::start( )
{
	// Start timer
	TCCR0 = 0b00010101;	// Normal mode, No output, 1024 prescale
	
	// Aktiver interrupts
	TIMSK |= 0b00000001;	// Overflow interrupt
	TIMSK &= 0b11111101;
	
	// Global interrupt enable
	sei();
}

// Stop og nulstil nedtælling
void LoginTimer::stop( )
{
	// Stop timer
	TCCR0 = 0b0;
	
	// Deaktiver interrupts
	TIMSK &= 0b11111100;
}

// Inkrementer overflow tæller og alarmer hvis den nulstilles
void LoginTimer::inc( )
{
	// Inkrementer
	ovfCount_++;

	if(ovfCount_ >= LOGIN_TIMOUT)
	{
		// Alarmer DE2 controller
		DE2IFObj.setLoginStatus(false);

		// Nulstil ovfCounter
		ovfCount_ = 0;
	}
}

// Automatisk oprettet timer objekt
LoginTimer loginTimer;

// Timer0 interrupt rutine
ISR(TIMER0_OVF_vect)
{
	// Inkrementer overflow tæller
	loginTimer.inc();
}