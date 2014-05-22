/*
 * Klasse RS232IF
 *
 * Styrer kommunikation mellem PC og CSS hovedenhed over RS232 protokollen
 *
 * Af Bjørn Sørensen
 *
 */

#include "RS232IF.h"

#define STX 'S'
#define ETX '\r'

RS232IF::RS232IF( )
{
	
}

RS232IF::~RS232IF()
{
	
}

// Returnerer UC nummer
unsigned char RS232IF::getUC(char * kommando)
{
	// Afvent komplet flag fra UART
	while(!commandReady);
	
	// Unwrap kommando
	unwrapper(dataIn, kommando);

	// Sænk komplet flag og nulstil buffer
	commandReady = 0;
	dataCount = 0;
		
	// Dekod protokol
	unsigned char ucNr = protokolUnwrap(kommando);

	// Returner UC nummer
	return ucNr;
}

// Returner adresse ud fra kommando
void RS232IF::getAdresse(char * kommando, char * adresse)
{
	// Hvis den er wrapped med STX og ETX fjernes de først
	if(kommando[0] == 's' || kommando[0] == 'S')
		unwrapper(kommando, kommando);
	
	// Kopier adressen over
	for(unsigned char i = 0; i < 4; i++)
		adresse[i] = kommando[i + 1];
	
}

// Retur svar fra loginValid
void RS232IF::loginStatus( bool status )
{
	// Send T når login er gyldigt
	if(status == true)
		loginTrue();
	// Ellers F
	else
		loginFalse();

}

// Afsend login verificeret
void RS232IF::loginTrue()
{
	// Send T og dummy adresse når login er verificeret
	char kommando[] = "T9999";

	// Wrap kommando med STX og ETX
	char wrapped[COMMAND_SIZE];
	wrapper(kommando, wrapped);
	
	// Afsend kommando
	sendKommando(wrapped);
	
}

// Afsend login ikke verificeret
void RS232IF::loginFalse()
{
	// Send F og dummy adresse når login ikke er verificeret
	char kommando[] = "F9999";

	// Wrap kommando med STX og ETX
	char wrapped[COMMAND_SIZE];
	wrapper(kommando, wrapped);
	
	// Afsend kommando
	sendKommando(wrapped);
	
}

// Alarmer PC om babyalarm
void RS232IF::adviser( )
{
	// Send B og dummy adresse når alarm aktiveres
	char kommando[] = "B9999";
	
	// Wrap kommando med STX og ETX
	char wrapped[COMMAND_SIZE];
	wrapper(kommando, wrapped);
	
	// Afsend kommando
	sendKommando(wrapped);
}

// Kommandowrapper (STX og ETX)
void RS232IF::wrapper(const char * kommando, char * wrapped)
{
	// STX: 'S'
	wrapped[0] = STX;
	
	// Indskriv kommando indhold
	for(unsigned char i = 0; i < (COMMAND_SIZE - 2); i++)	// Kommando længde minus STX og ETX
		wrapped[i + 1] = kommando[i];

	// ETX: <cr>
	wrapped[COMMAND_SIZE - 1] = ETX;
}

// Kommandounwrapper (STX og ETX)
void RS232IF::unwrapper(const char * wrapped, char * kommando)
{
	// Indskriv kommando indhold
	unsigned char i = 0;
	while(wrapped[i + 1] != ETX)
	{
		kommando[i] = wrapped[i + 1];
		i++;
	}
}

// Afsend wrapped kommando over UART
void RS232IF::sendKommando(char * wrapped)
{
	for(unsigned char i = 0; i < COMMAND_SIZE; i++)
		RS232UART.sendChar(wrapped[i]);
}

// Dekod protokol ud fra unwrapped kommando
unsigned char RS232IF::protokolUnwrap( char * kommando )
{
	// UC nummer
	unsigned char ucNr = 0;
	
	switch (kommando[0])
	{
		// UC1 Login
		case 'L':
		case 'l':
			ucNr = 1;
			break;
		
		// UC2 Aktiver
		case 'A':
		case 'a':
			ucNr = 2;
			break;
		
		// UC3 Deaktiver
		case 'D':
		case 'd':
			ucNr = 3;
			break;

	}
	
	// Returner UC nummer
	return ucNr;
}