/*
 * Main program til CSS hovedenheden
 *
 * Af Bjørn Sørensen
 *  
 */ 


#include <avr/io.h>
#include "X10IF.h"
#include "ZeroCrossInt.h"
#include "RS232IF.h"
#include "SensorIF.h"
#include "DE2IF.h"
#include "UC1Login.h"
#include "UC2Aktiver.h"
#include "UC3Deaktiver.h"
#include "UC5DetekterLyd.h"

int main( )
{
	// Opret alle objekter
	ZeroCrossInt ZeroCrossIntObj;
	RS232IF RS232IFObj;
	UC1Login UC1Obj(&RS232IFObj, &DE2IFObj);
	UC2Aktiver UC2Obj(&X10IFObj);
	UC3Deaktiver UC3Obj(&X10IFObj);
 	UC5DetekterLyd UC5Obj(&RS232IFObj);
	SensorIFObj.setUC5Ptr(&UC5Obj);
	
	// Kommando array
	char kommando[COMMAND_SIZE];
	char adresse[5];
	
	unsigned char UCnr;
	DDRC = 0xFF;
	PORTC = 0xFF;
	
    while(1)
    {
		// Afvent kommando
		while(!commandReady);
		
		// Gem UC nummer og evt. adresse
		UCnr = RS232IFObj.getUC(kommando);
		RS232IFObj.getAdresse(kommando, adresse);
		
		switch(UCnr)
		{
			// UC1 Login. Hent aktuel status og send retur
			case 1:
				PORTC = 0b11111110;
				RS232IFObj.loginStatus( UC1Obj.loginValid() );
				break;
			
			// UC2 Aktiver. Send aktiver kommando over X10
			case 2:
				PORTC = 0b11111101;
				UC2Obj.aktiver( adresse );
				break;
				
			// UC3 Deaktiver. Send deaktiver kommando over X10
			case 3:
				PORTC = 0b11111100;
				UC3Obj.deaktiver( adresse );
				break;
		}

    }
}