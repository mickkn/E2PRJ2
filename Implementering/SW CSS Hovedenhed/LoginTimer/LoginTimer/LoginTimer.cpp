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
	// Start timer
	start();
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
	
	// Aktiver interrupts
	
}

// Stop og nulstil nedtælling
void LoginTimer::stop( )
{
	// Stop timer
	
	// Deaktiver interrupts
	
}

// Inkrementer overflow tæller og alarmer hvis den nulstilles
void LoginTimer::inc( )
{
	// Inkrementer
	ovfCount++;
	
	// Alarmer login controller
	//UC1Login.loginUdlob( );
	
}

// Automatisk oprettet timer objekt
LoginTimer loginTimer;

// Timer0 interrupt rutine
ISR(TIMER0_OVF_vect)
{
	// Inkrementer overflow tæller
	loginTimer.inc();
}