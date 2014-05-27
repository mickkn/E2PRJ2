/*
 * Klasse RS232IF test applikation
 *
 * Styrer kommunikation mellem PC og CSS hovedenhed over RS232 protokollen
 *
 * Af Bjørn Sørensen
 *
 */


#include <avr/io.h>
#include <stdlib.h>
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

	// Metoderne adviser() og loginStatus(true/false) testes
	objekt.adviser();
	objekt.loginStatus(true);
	objekt.loginStatus(false);

	// UC nummer
	unsigned char ucNr;
		
	// Kommando array
	char kommando[COMMAND_SIZE];
		
	while(1)
	{
		// Hent kommando
		ucNr = objekt.getUC(kommando);
		PORTB = ~ucNr;

		if(ucNr == 2 || ucNr == 3)
		{
			char adresse[5];
			objekt.getAdresse(kommando, adresse);
			adresse[4] = '\0';
			RS232UART.sendString(adresse);
		}
	}
	
	return 0;
}