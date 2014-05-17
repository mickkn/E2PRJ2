/*
 * CircBuffer_Test.cpp
 *
 * Created: 17-05-2014 20:40:48
 *  Author: Bjørn
 */ 

#define F_CPU 3686400

#include "avr/io.h"
#include <util/delay.h>
#include "CircBuffer.h"
#include "UART.h"


int main(void)
{
	// Sæt LED outputs
	DDRB = 0xFF;
	
	// Sluk LEDer
	PORTB = ~0x00;

	// Opret objekt
	CircBuffer objekt;
	UART RS232(9600, 8);

	// Output next og current index
	/*PORTB = ~objekt.getNextIndex();
	_delay_ms(2000);
	
	PORTB = ~0xFF;
	_delay_ms(1000);
	
	PORTB = ~objekt.getCurrentIndex();
	_delay_ms(2000);*/


	// Indsæt bits
	char i = '0';
	char *iPtr = &i;
	
	/*objekt.insert(iPtr);
	
	// Output next og current index
	PORTB = ~objekt.getNextIndex();
	_delay_ms(5000);
	
	PORTB = ~0xFF;
	_delay_ms(1000);
	
	PORTB = ~objekt.getCurrentIndex();
	_delay_ms(5000);
	
	PORTB = ~objekt.get();
	_delay_ms(5000);*/
	
	// Fyld array 1.5 gange
	for(unsigned int j = 0; j < X10_ARRAY_SIZE*1.4; j++)
	{
		objekt.insert(iPtr);

	}
	// Output next og current index
	//PORTB = ~objekt.getNextIndex();
	RS232.sendChar(objekt.getNextIndex());
	_delay_ms(5000);
	
	PORTB = ~0xFF;
	_delay_ms(1000);
	
// 	RS232.sendChar(objekt.getNextIndex());
// 	_delay_ms(5000);
	RS232.sendChar(objekt.getCurrentIndex());
	

	// Læs data ud fra array
	for(unsigned char j = 0; j < X10_ARRAY_SIZE*1.4; j++)
	{
		//PORTB = ~objekt.get();
		_delay_ms(100); RS232.sendChar(objekt.get());
		

	}
	RS232.sendChar('\r');
	RS232.sendChar('\n');
	_delay_ms(2000);
	
	// Output next og current index
	//PORTB = ~objekt.getNextIndex();
	//_delay_ms(5000);
	RS232.sendChar(objekt.getNextIndex());
	
	PORTB = 0xAA;
	_delay_ms(1000);
	
	//PORTB = ~objekt.getCurrentIndex();
	//_delay_ms(5000);
	RS232.sendChar(objekt.getCurrentIndex());
	while(1)
	{
		
	}
}