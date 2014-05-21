/*
 * Controller UC1Login
 *
 * Af Bjørn Sørensen
 */ 


#pragma once

#include "DE2IF.h"

class UC1Login
{
public:
	UC1Login(DE2IF *);
	
	bool loginValid();
private:
	DE2IF * DE2IFPtr_;
	
};