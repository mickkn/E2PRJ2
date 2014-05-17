/*
 * Timer.cpp
 *
 * Created: 17-05-2014 16:23:45
 *  Author: Bjørn
 */ 

#define F_CPU 3686400
#include <avr/io.h>
#include <util/delay.h>
#include "Timer.h"

int main(void)
{
	
	// Opret Timer objekt
	Timer objekt;
	
    while(1)
    {
		// Start timer
		objekt.start();
	
		_delay_ms(1000);
	
		// Stop timer
		objekt.stop();
	
		_delay_ms(1000);
	}
}