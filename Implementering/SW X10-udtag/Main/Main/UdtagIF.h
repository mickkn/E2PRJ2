/*
 * UdtagIF.h
 *
 * Created: 26-05-2014 13:19:19
 *  Author: jeppestaerk
 */ 


#pragma once

#include <avr/io.h>

class UdtagIF
{
public:
	UdtagIF();				// Constructor, sætter Port D, Pin 7 som udgang
	void aktiver();			// Aktiver udtag
	void deaktiver();		// Deaktiver udtag
};