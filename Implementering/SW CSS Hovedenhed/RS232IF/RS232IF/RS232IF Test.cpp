/*
 * RS232IF.cpp
 *
 * Created: 07-05-2014 20:25:00
 *  Author: Bjørn
 */ 



#include <avr/io.h>
#include <avr/interrupt.h>

#include "RS232IF.h"
#include "led.h"
#include "UART.h"
#include <util/delay.h>


UART test(9600, 8);



ISR (USART_RXC_vect)
{
	char diode = 0;
	diode = test.readChar();
	PORTB = ~diode;
	test.sendChar(diode);
	
}

int main(void)
{
	// Initialiser port C som output
	DDRB = 0xFF;
	
	// Sluk alle dioder
	PORTB= 0xFF;
	
	// Opret objekt
	RS232IF objekt(9600, 8);
	//UART test(9600, 8);
		
	// Adviser test
	objekt.adviser();
	char testC;
	
	sei();
    while(1)
    {
		// Kommando afventning
		/*objekt.kommandoStandby();*/
		
		/*testC = test.readChar();
		_delay_ms(1000);
		test.sendChar(testC);*/
	}
}