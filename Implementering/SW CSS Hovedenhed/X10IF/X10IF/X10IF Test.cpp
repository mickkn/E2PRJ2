/*
 * Klasse X10IF Test
 *
 * Styrer kommunikation mellem CSS hovedenhed og X10 udtag over X10 protokollen
 *
 * Opstilling:
  * Fladkabel mellem PORTB og LEDS
  * 2-ledet ledning mellem RS232 SPARE og PD0-PD1
  * Ledning mellem SW0 og PD2
 *
 * Testforløb:
  * Efter at have brændt programmet ned på STK500 kittet flyttes USB->RS232 converteren til RS232 SPARE porten på STK500.
  * Et terminal vindue åbnes og indstilles til 9600 baud, 8 databits, 1 stopbit og 0 parititet.
  *
  * Tryk på Reset og følgende kode skal modtages på RS232 interfacet
   * 0121110010110011001100110000000111001011001100110011000000011100101101010010110100000001110010110101001011010000000
   * 012 Er antal kommandoer i kø udskrevet før, i mellem og efter at aktiver og deaktiver kommandoerne er kaldt.
   * 1110010110011001100110000000 Er Aktiver kommandoen med adresse 0101
   *									Denne er gentaget 2 gange iht. protokollen
   * 1110010110101001011010000000 Er Deaktiver kommandoen med adresse 0011
   *									Denne er også gentaget 2 gange.
  * 
  * Efter udskrifterne er det muligt at trykke på SW0 i 5 sekunder.
  * Tryk eller slip på SW0 vil resulterer i at lysdioderne blinker i 0,25 sekunder
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
	
	// Sæt aktiver kommando i kø
	X10Obj.aktiver("0101");
	
	// Hent antal kommandoer i kø og udskriv
	afventer = X10Obj.getAfventer() + 48;	// Convert to ASCII '0' etc.
	UARTObj.sendChar(afventer);
	
	// Sæt deaktiver kommando i kø
	X10Obj.deaktiver("0011");
	
	// Hen antal kommandoer i kø og udskriv
	afventer = X10Obj.getAfventer() + 48;	// Convert to ASCII '0' etc.
	UARTObj.sendChar(afventer);
		
	// Udskriv alle kommandoer i bufferen
	char ch;
	while(1)
	{
		// Hent bit
		ch = X10Obj.getBit();
		
		// Hvis terminering
		if(ch == '\0')
			// Afbryd hvis der ikke er flere kommandoer i kø
			if(X10Obj.getAfventer() == 0)
				break;
			else
				// Sænt antallet af kommandoer i kø
				X10Obj.decreaseAfventer();
		else
			// Udskriv bit værdi på UART
			UARTObj.sendChar(ch);
	}
	
	// Test af enableInt0() og disableInt0()
	// Sæt LED output og sluk dem
	DDRB = 0xFF;
	PORTB = 0xFF;
	
	// Aktiver interrupts i 5 sekunder
	// Det er muligt at få dioderne til at blinke inden for tidsrammen ved at trykke på SW0
	X10Obj.enableInt0();
	_delay_ms(5000);
	X10Obj.disableInt0();
	
	while(1);
}

// ISR for INT0. Tænd lysdioder i 0,25 sekunder
ISR (INT0_vect) {
	
	PORTB = 0x00;
	_delay_ms(250);
	PORTB = 0xFF;
}