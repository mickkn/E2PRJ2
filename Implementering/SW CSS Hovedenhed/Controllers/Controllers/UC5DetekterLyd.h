/*
 * Controller UC5DetekterLyd
 *
 * Af Bjørn Sørensen
 */ 


#pragma once

#include "RS232IF.h"

class UC5DetekterLyd
{
public:
	UC5DetekterLyd(RS232IF *);
	
	void detekterLyd( );
private:
	RS232IF * RS232Ptr_;
	
};