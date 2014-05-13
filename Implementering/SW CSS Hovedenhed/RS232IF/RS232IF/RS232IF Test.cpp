/*
 * RS232IF.cpp
 *
 * Created: 07-05-2014 20:25:00
 *  Author: Bjørn
 */ 


#include <avr/io.h>
#include "RS232IF.h"

int main()
{
	// Initialiser port C som output
	DDRB = 0xFF;
	
	// Sluk alle dioder
	PORTB= 0xFF;

	// Global interrupt enable
	sei();	
	
	// Opret objekt
	RS232IF objekt;

	// Adviser test
	objekt.adviser();

	// Loginstatus
	objekt.loginStatus(true);
	objekt.loginStatus(false);

	// UC nummer
	unsigned char ucNr;
		
	// Kommando array
	char kommando[COMMAND_SIZE];
		
	while(1)
	{
		ucNr = objekt.getUC(kommando);
		PORTB = ~ucNr;
	}
	
	return 0;
}