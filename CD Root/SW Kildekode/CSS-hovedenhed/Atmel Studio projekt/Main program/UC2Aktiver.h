/*
 * Controller UC2Aktiver
 *
 * Af Bjørn Sørensen
 */ 


#pragma once

#include "X10IF.h"

class UC2Aktiver
{
public:
	UC2Aktiver(X10IF *);
	
	void aktiver(char* adresse);
private:
	X10IF * X10IFPtr_;
	
};