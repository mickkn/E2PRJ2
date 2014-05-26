/*
 * AdresseIF.cpp
 *
 * Created: 26-05-2014 13:18:50
 *  Author: jeppestaerk
 */ 

#include "AdresseIF.h"

AdresseIF::AdresseIF()
{
	DDRD &= 0b10101010;					// sætter Port D, Pin 0, 2, 4 & 6 som indgange
	
	for (int i = 0; i < 4; i++)			// Fylder adresse_ arrayet med 0'er
	{
		adresse_[i] = 0;
	}
}

bool AdresseIF::adresseTjek(char *adresse)
{
	adresse_[3] = 1;					// Læser værdien fra PortD Pin0
	adresse_[2] = 0;					// Læser værdien fra PortD Pin2
	adresse_[1] = 1;					// Læser værdien fra PortD Pin3
	adresse_[0] = 0;					// Læser værdien fra PortD Pin4
	
	if (adresse_[0] == adresse[0] && adresse_[1] == adresse[1] && adresse_[2] == adresse[2] && adresse_[3] == adresse[3]) // Kontroller om adresse_ arrayet er identisk med adresse arrayet
	{
		return true;
	}
	else
	{
		return false;
	}
}