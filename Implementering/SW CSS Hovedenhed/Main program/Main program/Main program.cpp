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
// #include "SensorIF.h"
// #include "DE2IF.h"
// #include "UC1Login.h"
// #include "UC2Aktiver.h"
// #include "UC3Deaktiver.h"
// #include "UC5DetekterLyd.h"

int main( )
{
	// Opret alle objekter
	X10IF X10IFObj;
//	DE2IF DE2IFObj;
// 	UC1Login UC1Obj(&DE2IFObj);
// 	UC2Aktiver UC2Obj(&X10IFObj);
// 	UC3Deaktiver UC3Obj(&X10IFObj);
	RS232IF RS232IFObj;//(&UC1Obj, &UC2Obj, &UC3Obj);
// 	UC5DetekterLyd UC5Obj(&RS232IFObj);
//	SensorIF SensorIFObj(&UC5Obj);
	

    while(1)
    {
        //TODO:: Please write your application code 
    }
}