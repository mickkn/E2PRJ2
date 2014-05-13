/*
 * Klasse RS232IF
 *
 * Styrer kommunikation mellem PC og CSS hovedenhed over RS232 protokollen
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once

#define F_CPU 3686400

#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>


#include "UART.h"

class RS232IF {
public:
	RS232IF( unsigned long baudRate, unsigned char dataBit );	// Indsæt som første parameter:  UC1Login * UC1Ptr, UC2Aktiver * UC2Ptr, UC3Deaktiver * UC3Ptr,
	
	void loginStatus( bool status );	// Retur svar fra loginValid
	void adviser( );					// Alarmer PC om babyalarm
	void kommandoStandby();				// Afventer chars på RS232 og kalder passende UC når de modtages

private:
	// Referencer
	/*UC1Login * UC1Ptr_;
	UC2Aktiver * UC2Ptr_;
	UC3Deaktiver * UC3Ptr_;*/
	
	bool getKommando(char *);	// Hent fuld kommando
	
	// Kommandowrapper (STX og ETX)
	void wrapper(char *, char *);
	
	// UART Forbindelse
	UART forbindelse;
};
