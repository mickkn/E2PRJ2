/*
 * Klasse X10IF Test
 *
 * Styrer kommunikation mellem CSS hovedenhed og X10 udtag over X10 protokollen
 *
 * Af Bjørn Sørensen
 *
 */

#define F_CPU 3686400

#include <util/delay.h>
#include "X10IF.h"
#include "UART.h"
#include <avr/io.h>

int main()
{
	// Opret objekter
	X10IF X10Obj;
	UART UARTObj(9600, 8);

	
	// Hent antal kommandoer i kø og udskriv
	char afventer = X10Obj.getAfventer() + 48;	// Convert to ASCII '0' etc.
	UARTObj.sendChar(afventer);
	UARTObj.sendChar(' ');
	
	// Sæt aktiver kommando i kø
	X10Obj.aktiver("0101");
	
	// Hent antal kommandoer i kø og udskriv
	afventer = X10Obj.getAfventer() + 48;	// Konverter til ASCII tal.
	UARTObj.sendChar(afventer);
	UARTObj.sendChar(' ');
	
	// Sæt deaktiver kommando i kø
	X10Obj.deaktiver("0011");
	
	// Hetn antal kommandoer i kø og udskriv
	afventer = X10Obj.getAfventer() + 48;	// Konverter til ASCII tal.
	UARTObj.sendChar(afventer);
	UARTObj.sendChar('\n');
		
	// Udskriv alle kommandoer i bufferen
	char ch;
	while(1)
	{
		// Hent bit
		ch = X10Obj.getBit();
		
		// Hvis terminering
		if(ch == '\0')
		{
			// Afbryd hvis der ikke er flere kommandoer i kø
			if(X10Obj.getAfventer() == 0)
				break;
			else
				// Sænt antallet af kommandoer i kø
				X10Obj.decreaseAfventer();
				
			// Udskriv ny linje
			UARTObj.sendChar('\n');
		}
		else
			// Udskriv bit værdi på UART
			UARTObj.sendChar(ch);
	}
	
	// Test af enableInt0() og disableInt0()
	// Sæt LED output og sluk dem på nær bit 7
	DDRB = 0xFF;
	PORTB = 0x7F;
	
	// Aktiver interrupts i 5 sekunder
	// Det er muligt at få dioderne til at blinke inden for tidsrammen ved at trykke på SW0
	X10Obj.enableInt0();
	_delay_ms(5000);
	X10Obj.disableInt0();
	
	// Sluk dioder
	PORTB = 0xFF;
	
	
	while(1);
}

// ISR for INT0. Tænd lysdioder i 0,25 sekunder
ISR (INT0_vect) {
	
	PORTB = 0x00;
	_delay_ms(250);
	PORTB = 0x7F;
}