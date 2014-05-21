/*
 * Klasse DE2IF
 *
 * Interface til DE2 boardet
 *
 *  Af Bjørn Sørensen
 */ 

#include "DE2IF.h"


DE2IF::DE2IF()
{
	// Sæt input port
	DDRB &= 0b11111011;
	
	// Aktiver interrupt ved skift til høj
	GICR |= 0b00100000;
	MCUCSR |= 0b01000000;
	sei();
}

DE2IF::~DE2IF()
{
	// Deaktiver interrupt
	GICR &= 0b11011111;
}


void DE2IF::setLoginStatus( bool status )
{
	loginStatus_ = status;
	
	if(status == true)
		loginTimer.start();
	else
		loginTimer.stop();
		
}

bool DE2IF::getLoginStatus( ) const
{
	return loginStatus_;
}

DE2IF DE2IFObj;

// INT2 ISR
ISR(INT2)
{
	DE2IFObj.setLoginStatus(true);
}