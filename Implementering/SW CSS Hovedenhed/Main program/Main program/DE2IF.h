/*
 * Klasse DE2IF
 *
 * Interface til DE2 boardet
 *
 *  Af Bjørn Sørensen
 */ 

#pragma once

#include <avr/io.h>
#include <avr/interrupt.h>
#include "LoginTimer.h"
#include "UC1Login.h"

class UC1Login;

class DE2IF
{
public:
	DE2IF();
	~DE2IF();
	
	void setLoginStatus( bool );
	bool getLoginStatus( ) const;
	void setUC1Ptr( UC1Login * );
	
private:
	bool loginStatus_;
	UC1Login * UC1Ptr_;

};

extern DE2IF DE2IFObj;
