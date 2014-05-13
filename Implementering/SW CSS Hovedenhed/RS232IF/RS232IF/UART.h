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
#define COMMAND_SIZE 7

#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>


class UART {
public:
	UART( unsigned long BaudRate, unsigned char Databit );
	~UART( );

	char charReady( );
	char readChar( );
	void sendChar( char );
	void sendString( char * );

};

// Fortæl compiler at disse globale variable findes
extern char dataIn[];
extern unsigned char volatile dataCount;
extern unsigned char volatile commandReady;
extern UART RS232UART; 