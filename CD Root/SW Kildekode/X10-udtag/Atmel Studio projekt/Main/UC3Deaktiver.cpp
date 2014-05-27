/*
 * UC3Deaktiver.cpp
 *
 * Created: 26-05-2014 13:18:28
 *  Author: jeppestaerk
 */ 


#include "UC3Deaktiver.h"

UC3Deaktiver::UC3Deaktiver(AdresseIF * AIFPtr, UdtagIF * UIFPtr)
{
	AIFPtr_ = AIFPtr;
	UIFPtr_ = UIFPtr;
}

void UC3Deaktiver::deaktiver(char *adresse)
{
	if (AIFPtr_->adresseTjek(adresse) == true)
	{
		UIFPtr_->deaktiver();
	}
}