/*
 * DE2IF_Test.cpp
 *
 * Created: 22-05-2014 08:38:42
 *  Author: Bjørn
 */ 


#include <avr/io.h>
#include "DE2IF.h"
#include "RS232IF.h"
#include "UC1Login.h"


int main()
{
	RS232IF RS232Obj;
	
	UC1Login UC1Obj(&RS232Obj, &DE2IFObj);
	
	UC1Obj.loginValid();
	RS232UART.sendChar('\n');
	
	while(1);
}