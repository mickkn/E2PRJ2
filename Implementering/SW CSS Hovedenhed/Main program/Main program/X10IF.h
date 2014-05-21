/*
 * Klasse X10IF header
 *
 * Styrer kommunikation mellem CSS hovedenhed og X10 udtag over X10 protokollen
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once

#define X10_COMMAND_LENGHT 28
#include "CircBuffer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

class X10IF
{
public:
	X10IF();
	
	void aktiver(char *adresse);				// Send aktiver kommando over X10
	void deaktiver(char *adresse);				// Send deaktiver kommando over X10
	
	unsigned char getAfventer( );				// Returner antallet af kommandoer i kø
	void decreaseAfventer( );					// Træk 1 fra antallet af kommandoer i kø
	
	void enableInt0( );							// Aktiver ZeroCrossInt interrupt
	void disableInt0( );						// Deaktiver ZeroCrossInt interrupt
	
	char getBit();								// Hent næste bit fra X10 bufferen

private:
	CircBuffer buffer_;							// Indholder X10 kommandoer klar til afsendelse
	unsigned char afventer_;					// Inderholder antallet af kommandoer i kø, default: 0
	
	void wrap(char *unwrapped, char *wrapped);	// Wrap kommando til X10 formatet
	void sendKommando(char *wrapped);			// Indskriver X10 kommando i bufferen
	char * formatX10(char *plads, char bit);	// Indskriver komplimentær X10 bit værdi på plads og returnerer pointer til næste plads
};

extern X10IF X10;