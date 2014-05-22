/*
 * Controller UC3Deaktiver
 *
 * Af Bjørn Sørensen
 */ 

#include "UC5DetekterLyd.h"


UC5DetekterLyd::UC5DetekterLyd(RS232IF *Ptr)
{
	RS232Ptr_ = Ptr;
}
	
void UC5DetekterLyd::detekterLyd( )
{
	RS232Ptr_->adviser( );
}
