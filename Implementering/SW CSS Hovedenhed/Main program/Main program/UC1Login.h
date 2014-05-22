/*
 * Controller UC1Login
 *
 * Af Bjørn Sørensen
 */ 


#pragma once

#include "DE2IF.h"
#include "RS232IF.h"

class DE2IF;

class UC1Login
{
public:
	UC1Login(RS232IF * RSPtr, DE2IF *DEPtr);
	
	bool loginValid();
	void loginStatus(bool);
private:
	DE2IF * DE2IFPtr_;
	RS232IF * RS232IFPtr_;
};