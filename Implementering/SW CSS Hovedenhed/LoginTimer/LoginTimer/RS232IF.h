/*
 * Klasse RS232IF
 *
 * Styrer kommunikation mellem PC og CSS hovedenhed over RS232 protokollen
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once

#define F_CPU 3686400

#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#include "UART.h"

class RS232IF {
public:
	RS232IF( );
	~RS232IF();

	unsigned char getUC(char *);	// Henter fuld kommando, unwrapper og dekoder protokollen, returnerer nummer på næste UC kald:
										// // 1: UC1 Login
										// // 2: UC2 Aktiver
										// // 3: UC3 Deaktiver
										
	void getAdresse(char *kommando, char *adresse);	// Hent adresse ud af kommando
	
	void loginStatus( bool status );	// Afsend login status
	void adviser( );					// Alarmer PC om babyalarm

private:
	// Kommandowrapper (STX og ETX)
	void wrapper(const char *kommando, char *wrapped);
	void unwrapper(const char *wrapped, char *kommando);
	unsigned char protokolUnwrap(char *kommando);
	
	// Afsend wrapped kommando
	void sendKommando(char * wrapped);

	void loginTrue( );					// Afsend login verificeret
	void loginFalse( );					// Afsend login ikke verificeret
	
};
