/*
 * Controller UC1Login
 *
 * Af Bjørn Sørensen
 */ 


#include "UC1Login.h"

UC1Login::UC1Login(RS232IF * RSPtr, DE2IF *DEPtr)
{
	DE2IFPtr_ = DEPtr;
	RS232IFPtr_ = RSPtr;
	
	DE2IFPtr_->setUC1Ptr(this);
}
	
bool UC1Login::loginValid()
{
	return DE2IFPtr_->getLoginStatus();
}

void UC1Login::loginStatus( bool status )
{
	RS232IFPtr_->loginStatus(status);
}