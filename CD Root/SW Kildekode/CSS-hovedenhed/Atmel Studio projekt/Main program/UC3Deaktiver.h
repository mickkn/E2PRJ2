/*
 * Controller UC3Deaktiver
 *
 * Af Bjørn Sørensen
 */ 


#pragma once

#include "X10IF.h"

class UC3Deaktiver
{
public:
	UC3Deaktiver(X10IF *);
	
	void deaktiver(char* adresse);
private:
	X10IF * X10IFPtr_;
	
};