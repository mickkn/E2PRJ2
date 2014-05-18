/*
 * Testprogram til PCens RS232IF klasse
 *
 * Ved tryk på en af knapperne forbundet til port A afsendes kommando:
 *
 * SW0: Adviser (Babyalarm)
 * SW1: Login valideret (True)
 * SW2: Login ikke valideret (False)
 *
 * Af Bjørn Sørensen
 *
 */

#define F_CPU 3686400
#include <util/delay.h>
#include <avr/io.h>
#include "RS232IF.h"

int main()
{
	// Port A som output
	DDRA = 0x00;

	// RS232IF test objekt
	RS232IF objekt;

    while(1)
    {
		// Hvis SW0 er trykket
		if(PINA == 0b11111110)
		{
			objekt.adviser();
			_delay_ms(1000);
		}
		
		// Hvis SW1 er trykket
		if(PINA == 0b11111101)
		{
			objekt.loginStatus(true);
			_delay_ms(1000);
		}
		
		// Hvis SW2 er trykket
		if(PINA == 0b11111011)
		{
			objekt.loginStatus(false);
			_delay_ms(1000);
		}

    }
	
	return 0;
}