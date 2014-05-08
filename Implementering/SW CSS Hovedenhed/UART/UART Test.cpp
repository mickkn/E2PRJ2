/*
 * Test program
 *
 * RS232IF og UART driver
 *
 * Af Bjørn Sørensen
 *
 */


#include <avr/io.h>
#include "UART.h"


int main(void)
{
	{
	// Opret UART objekt
	UART RS232UART (9600, 8);
	
	// Send char
	RS232UART.sendChar('A');
	
	// Send string
	char string[] = "CSS hovedenhed";
	RS232UART.sendString(string);
	}
	
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}