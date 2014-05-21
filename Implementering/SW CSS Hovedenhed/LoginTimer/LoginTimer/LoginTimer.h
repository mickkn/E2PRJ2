/*
 * Header til klasse LoginTimer
 *
 * Login timer som tæller ned når et login er aktivt og giver PC besked når tiden er udløbet
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once

class LoginTimer
{
public:
	LoginTimer( );
	~LoginTimer( );
	
	void start( );	// Start og initialiser nedtælling
	void stop( );	// Stop og nulstil nedtælling
	void inc( );	// Inkrementer overflow tæller
	
private:
	unsigned int ovfCount;
};

extern LoginTimer;