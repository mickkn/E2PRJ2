/*
 * Header til klasse UART
 *
 * RS232 driver
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once

#define F_CPU 3686400

#include <avr/io.h>
#include <string.h>

class UART {
public:
	UART( unsigned long BaudRate, unsigned char Databit );
	~UART( );

	unsigned char charReady( );
	char readChar( );
	void sendChar( char );
	void sendString( char * );

};
