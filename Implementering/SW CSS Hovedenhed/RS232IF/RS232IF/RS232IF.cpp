/*
 * Klasse RS232IF
 *
 * Styrer kommunikation mellem PC og CSS hovedenhed over RS232 protokollen
 *
 * Af Bjørn Sørensen
 *
 */

#include "RS232IF.h"


RS232IF::RS232IF( unsigned long baudRate, unsigned char dataBit ) : forbindelse(baudRate, dataBit)	// Indsæt som første parameter:  UC1Login * UC1Ptr, UC2Aktiver * UC2Ptr, UC3Deaktiver * UC3Ptr,
{
	// Init referencer
	 /*UC1Ptr_ = UC1Ptr;
	 UC2Ptr_ = UC2Ptr;
	 UC3Ptr_ = UC3Ptr;*/
	
}

void RS232IF::kommandoStandby()
{
	// Kommando char array
	char kommando[8];
	getKommando(kommando);
}

bool RS232IF::getKommando(char * kommando)
{
	// Clear kommando array
	for(unsigned char i = 0; i < 8; i++)
		kommando[i] = '\0';
	
	// Hent komplet kommando
	unsigned char i = 0;
	while(kommando[i] != 0x0d && i <= 7)	// Ikke ETX og max længde for en kommando
	{
		// Hent char
		kommando[i] = forbindelse.readChar();
		
		 PORTB = ~kommando[i]; 
		 
		 // Vent
		_delay_ms(1000);
				
		// Returner modtagne char DEBUG
		forbindelse.sendChar(kommando[i]);
		

		// Næste char
		i++;
	}
	
	// Send fuld kommando retur DEBUG	
	//forbindelse.sendString(kommando);
	
	return true;
}

void RS232IF::loginStatus( bool status )
{
	/*char kommando[2] = {'\0', '\0' };
		
	// Send T hvis logget ind
	if( status == true )
		kommando[0] = 'T';
	else	if( status == false )	// Ellers F
		kommando[0] = 'F';
	
	// Wrap og send
	char wrapped[8];
	wrapper(kommando, wrapped);
	forbindelse.sendString( wrapped );
	*/
	
}

void RS232IF::adviser( )
{
	// Send B når alarm aktiveres
	char kommando[] = "B";
	
	// Wrap og send
	char wrapped[8];
	wrapper(kommando, wrapped);
	forbindelse.sendString(wrapped);
}
/*
void RS232IF::protokol( string kommando )
{
	
		/*if(kommando[0] == 'S' || kommando[0] == 's')
		{
			switch (kommando[1])
			{
				// Aktiver eller deaktiver, hent adresse
				case 'A':
				case 'a':
				case 'D':
				case 'd':
					// Array til char adressen
					char adresseChar[4];
					
					// Hent fire chars til adressen
					for(unsigned char i = 0; i < 4 && !dataFejl; i++)
					{
						if( kommando[2 + i] == '1' || kommando[2 + i] == '0' )
							adresseChar[i] = kommando[2 + i];
						else
							dataFejl = true;
					}
					
					// Kontroller ETX
					if(kommando[6] != 0x0D)
						dataFejl = true;
					
					if(!dataFejl)
					{
						// Konverter char adresse til int
						int adresseInt = atoi(adresseChar);
						
						if(kommando[1] == 'A' || kommando[1] == 'a' )
						{
							//UC2Ptr_->aktiver(adresseInt);
							
							// Dummy: Returner adresse
							forbindelse.sendChar('A');
							char array[5];
							itoa(adresseInt, array, 5);
							forbindelse.sendString(array);
						}
						else if( kommando[1] == 'D' || kommando[1] == 'd')
						{
							//UC3Ptr_->deaktiver(adresseInt);
							forbindelse.sendChar('D');
							char array[5];
							itoa(adresseInt, array, 5);
							forbindelse.sendString(array);
						}
					}
					
				break; // End 'A' og 'D'
					
				// Login
				case 'L':
				case 'l':
					//loginStatus( UC1Ptr_->loginValid( ) );
					loginStatus(true);
				break; // End 'L'
					
			}
		}*
}*/

// Kommandowrapper (STX og ETX)
void RS232IF::wrapper(char * kommando, char * wrapped)
{
	// STX: 'S'
	wrapped[0] = 'S';
	
	// Indskriv kommando indhold
	unsigned char i = 0;
	while(kommando[i] != '\0')
	{
		wrapped[i + 1] = kommando[i];
		i++;
	}
	
	// ETX: <cr>
	wrapped[i + 1] = 0x0D;
	
	// Terminer streng
	wrapped[i + 2] = '\0';

}
