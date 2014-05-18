/*
 * ZeroCrossInt interrupt implementering
 *
 * Styrer hvornår der skal afsendes 120 kHz bursts ud fra X10 kommandoerne i bufferen
 *
 * Af Bjørn Sørensen
 *
 */

#include "ZeroCrossInt.h"

int main()
{
	
	X10.aktiver("0101");
	
	
	DDRB = 0xFF;
	PORTB = 0xFF;
	while(1)
	{
		PORTB = 0x00;
		_delay_ms(1000);
		PORTB = 0xFF;
		_delay_ms(1000);
	}
}