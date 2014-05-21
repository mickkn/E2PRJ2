/*
 * Klasse ZeroCrossInt implementering
 *
 * Styrer hvornår der skal afsendes 120 kHz bursts ud fra X10 kommandoerne i bufferen
 *
 * Af Bjørn Sørensen
 *
 */

#include "ZeroCrossInt.h"


ISR (INT0_vect) {
	
	if(X10.getAfventer() > 0)
	{
		char ch = X10.getBit();
		
		// Vent 1 ms hvis bit 0
		if(ch == '0')
			_delay_ms(1);
			
		// Tænd timer på 120 kHz hvis bit er 1
		else if(ch == '1')
		{
			timer.start();
			_delay_ms(1);
			timer.stop();
			
		// Træk en fra kommandoer i kø hvis det er sidst tegn
		} else if(ch == '\0')
			X10.decreaseAfventer();
		
	} 
	// Hvis der ikke er noget i kø så disable interrupts
	else
		X10.disableInt0();
}
