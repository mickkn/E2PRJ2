/*
 * Header til klasse LoginTimer
 *
 * Login timer som tæller ned når et login er aktivt og giver PC besked når tiden er udløbet
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once

#define LOGIN_TIMOUT 56 // 60 sekunder: 843, 5 minutter: 4218
#include "DE2IF.h"

class LoginTimer
{
public:
	LoginTimer( );
	~LoginTimer( );
	
	void start( );	// Start og initialiser nedtælling
	void stop( );	// Stop og nulstil nedtælling
	void inc( );	// Inkrementer overflow tæller
	
private:
	unsigned int ovfCount_;
};

extern LoginTimer loginTimer;