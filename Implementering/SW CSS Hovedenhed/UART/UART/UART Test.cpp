/*
 * Test program
 *
 * RS232IF og UART driver
 *
 * Af Bjørn Sørensen
 *
 */

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "UART.h"


int main()
{
	// Initialiser kommando buffer
	dataCount = 0;
	commandReady = 0;
	
	// Initialiser port B til output og sluk LEDer 
	DDRB = 0xFF;
	PORTB= 0xFF;

	// Send string
	char string[] = "CSS hovedenhed\r\n";
	RS232UART.sendString(string);
	
	// Global interrupt enable
	sei();
	
	while(1)
	{
		// Hvis fuld kommando er klar
		if(commandReady == 1)
		{
			// Alloker hukommelse
			char * dataRetur = (char*) malloc((COMMAND_SIZE + 1)*sizeof(*dataRetur));
			
			// Kopier data over
			for(unsigned char i = 0; i < COMMAND_SIZE; i++)
				dataRetur[i] = dataIn[i];
			
			// Terminer med \n
			dataRetur[COMMAND_SIZE] = '\n';
			
			// Returner modtaget kommando
			RS232UART.sendString(dataRetur);
			
			// Frigør hukommelse
			free(dataRetur);
			
			// Kommando læst, nulstil buffer
			commandReady = 0;
			dataCount = 0;
		}
	}
}