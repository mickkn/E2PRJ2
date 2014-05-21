/*
 * Klasse DE2IF
 *
 * Interface til DE2 boardet
 *
 *  Af Bjørn Sørensen
 */ 

#pragma once

#include <avr/interrupt.h>
#include "LoginTimer.h"

class DE2IF
{
public:
	DE2IF();
	~DE2IF();
	
	void setLoginStatus( bool );
	bool getLoginStatus( ) const;
	
private:
	bool loginStatus_;

};

extern DE2IF;
