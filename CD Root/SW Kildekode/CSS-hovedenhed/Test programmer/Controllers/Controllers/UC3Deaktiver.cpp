/*
 * Controller UC3Deaktiver
 *
 * Af Bjørn Sørensen
 */ 

#include "UC3Deaktiver.h"


UC3Deaktiver::UC3Deaktiver(X10IF *Ptr)
{
	X10IFPtr_ = Ptr;
}
	
void UC3Deaktiver::deaktiver(char* adresse)
{
	X10IFPtr_->deaktiver( adresse );
}
