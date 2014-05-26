/*
 * UdtagIF.cpp
 *
 * Created: 26-05-2014 13:19:10
 *  Author: jeppestaerk
 */ 


#include "UdtagIF.h"

UdtagIF::UdtagIF()
{
	DDRD |= 0b10000000;		// Sætter Port D, Pin 7 som udgang
}

void UdtagIF::aktiver()
{
	PORTD |= 0b10000000;	// Sætter Port D, Pin 7 til høj (logisk 1)
}

void UdtagIF::deaktiver()
{
	PORTD &= 0b01111111;	// Sætter Port D, Pin 7 til lav (logisk 0)
}