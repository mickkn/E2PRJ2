/*
 * AdresseIF.h
 *
 * Created: 26-05-2014 13:18:57
 *  Author: jeppestaerk
 */ 


#pragma once

#include <avr/io.h>

class AdresseIF
{
public:
	AdresseIF();									// Constructor, sætter Port D, Pin 0, 2, 4 & 6 som indgange og fylder adresse_ arrayet med 0'er
	bool adresseTjek(char *adresse);				// Kontroller modtaget adresse op imod X10modtagerens adresse_
private:
	char adresse_[4];					// Indholder X10modtagerens adresse		
};