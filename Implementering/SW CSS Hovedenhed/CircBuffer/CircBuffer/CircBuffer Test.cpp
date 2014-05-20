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
	// Opret objekter
	CircBuffer objekt;
	UART RS232(9600, 8);

	// Variabel og Ptr til indsættelse i buffer
	char i = 'A';
	char *iPtr = &i;
	
	// Send NextIndex og CurrentIndex som ASCII tal (+48)
	RS232.sendChar((char)(objekt.getNextIndex()+48));
	RS232.sendChar(' ');
	RS232.sendChar((char)(objekt.getCurrentIndex()+48));
	RS232.sendChar('\n');
	
	// Indsæt værdi i buffer
	objekt.insert(iPtr);
	
	// Send NextIndex og CurrentIndex som ASCII tal (+48)
	RS232.sendChar((char)(objekt.getNextIndex()+48));
	RS232.sendChar(' ');
	RS232.sendChar((char)(objekt.getCurrentIndex()+48));
	RS232.sendChar('\n');
	
	RS232.sendChar(objekt.get());
	RS232.sendChar('\n');
	RS232.sendChar((char)(objekt.getNextIndex()+48));
	RS232.sendChar(' ');
	RS232.sendChar((char)(objekt.getCurrentIndex()+48));
	RS232.sendChar('\n');

	// Fyld array 1.5 gange med 'B'
	i = 'B';
	for(unsigned int j = 0; j < X10_ARRAY_SIZE*1.5; j++)
		objekt.insert(iPtr);
	
	// Indsæt 'C'
	i = 'C';
	objekt.insert(iPtr);
	
	// Send NextIndex og CurrentIndex som ASCII tal (+48)
	RS232.sendChar((char)(objekt.getNextIndex()+48));
	RS232.sendChar(' ');
	RS232.sendChar((char)(objekt.getCurrentIndex()+48));
	RS232.sendChar('\n');	

	// Læs data ud fra array indtil 'C' rammes
	char ch;
	do 
	{
		ch = objekt.get();
		RS232.sendChar(ch);
	} while (ch != 'C');
		

	RS232.sendChar('\n');
	
	// Send NextIndex og CurrentIndex som ASCII tal (+48)
	RS232.sendChar((char)(objekt.getNextIndex()));
	RS232.sendChar(' ');
	RS232.sendChar((char)(objekt.getCurrentIndex()));
	RS232.sendChar('\n');

	while(1);
}