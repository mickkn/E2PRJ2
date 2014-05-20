/*
 * ZeroCrossInt interrupt implementering
 *
 * Styrer hvornår der skal afsendes 120 kHz bursts ud fra X10 kommandoerne i bufferen
 *
 * Test vejledning
  * Opstilling:
   * Ledning mellem PD2 og PB0
   * Oscilliscope måling på PB2 og PD5
  *
  * Testprogrammet genererer en firkantpuls på Port B med en frekvens på 250 Hz og Dutycycle på 50 %
  * Dette signal føres via jumper til INT0 indgangen for at simulerer ZeroCross signalet.
  * Når en kommando er lagt i bufferen, vil denne blive sendt ud på PB5 benet som 120 kHz bursts for hvert bit.
  * Programmet sender en aktiver og en deaktiver kommando afsted.
 *
 * Af Bjørn Sørensen
 *
 */

#include "ZeroCrossInt.h"

int main()
{
	// Afsend aktiver kommando
	X10.aktiver("0101");
	
	// Afsend deaktiver kommando
	X10.deaktiver("0011");
	
	// Test frekvens som aktiverer INT0. 
	DDRB = 0xFF;
	PORTB = 0xFF;
	while(1)
	{
		PORTB = 0x00;
		_delay_ms(2);
		PORTB = 0xFF;
		_delay_ms(2);
	}
}