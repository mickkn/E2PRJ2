/*
 * UC2Aktiver.cpp
 *
 * Created: 26-05-2014 13:17:49
 *  Author: jeppestaerk
 */ 


#include "UC2Aktivere.h"

UC2Aktiver::UC2Aktiver(AdresseIF * AIFPtr, UdtagIF * UIFPtr)
{
	AIFPrt_ = AIFPtr;
	UIFPtr_ = UIFPtr;
}

void UC2Aktiver::aktiver(char *adresse)
{
	if (AIFPrt_->adresseTjek(adresse) == true)
	{
		UIFPtr_->aktiver();	
	}
}