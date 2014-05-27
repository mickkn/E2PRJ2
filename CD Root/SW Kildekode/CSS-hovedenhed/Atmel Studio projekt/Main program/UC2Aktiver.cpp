/*
 * Controller UC2Aktiver
 *
 * Af Bjørn Sørensen
 */ 

#include "UC2Aktiver.h"


UC2Aktiver::UC2Aktiver(X10IF *Ptr)
{
	X10IFPtr_ = Ptr;
}
	
void UC2Aktiver::aktiver(char* adresse)
{
	X10IFPtr_->aktiver( adresse );
}
