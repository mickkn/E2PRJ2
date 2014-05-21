/*
 * Controller UC1Login
 *
 * Af Bjørn Sørensen
 */ 


#include "UC1Login.h"

UC1Login::UC1Login(DE2IF *Ptr)
{
	DE2IFPtr_ = Ptr;
}
	
bool UC1Login::loginValid()
{
	return DE2IFPtr_->getLoginStatus();
}
