/*
 * UC3Deaktiver.h
 *
 * Created: 26-05-2014 13:18:35
 *  Author: jeppestaerk
 */ 


#pragma once

#include "AdresseIF.h"
#include "UdtagIF.h"

class UC3Deaktiver
{
public:
	UC3Deaktiver(AdresseIF * AIFPtr, UdtagIF * UIFPtr);		// Constructor
	void deaktiver(char *adresse);							// Modtager aktiver funktion og kontroller om adresse stemmer overens med X10modtageren
private:
	AdresseIF * AIFPtr_;
	UdtagIF * UIFPtr_;
};