/*
 * RS232IF.cpp
 *
 * Created: 07-05-2014 20:25:00
 *  Author: Bjørn
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
		PORTB = ucNr;
		_delay_ms(1000);	
			
		if(ucNr == 2 || ucNr == 3)
		{
			char adresseC[5] = {0};
			
			unsigned int adresseI;
			
			for(unsigned char i = 0; i < 4; i++)
				adresseC[i] = kommando[i + 1];
				
			adresseC[4] = '\0';	// strtol terminering
			adresseI = strtol(adresseC, NULL, 10);
			
			RS232UART.sendString(adresseC);
		}
		_delay_ms(1000);
	}
	
	return 0;
}