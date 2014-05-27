/*
 * UC2Aktivere.h
 *
 * Created: 26-05-2014 13:18:09
 *  Author: jeppestaerk
 */ 


#pragma once
#include "AdresseIF.h"
#include "UdtagIF.h"

class UC2Aktiver
{
public:
	UC2Aktiver(AdresseIF * AIFPtr, UdtagIF * UIFPtr);	// Constructor
	void aktiver(char *adresse);						// Modtager aktiver funktion og kontroller om adresse stemmer overens med X10modtageren
public:
	AdresseIF * AIFPrt_;
	UdtagIF * UIFPtr_;
};