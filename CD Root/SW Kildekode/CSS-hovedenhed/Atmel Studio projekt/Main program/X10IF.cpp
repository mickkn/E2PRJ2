/*
 * Klasse X10IF implementering
 *
 * Styrer kommunikation mellem CSS hovedenhed og X10 udtag over X10 protokollen
 *
 * Af Bjørn Sørensen
 *
 */

#include "X10IF.h"

// Default constructor
X10IF::X10IF()
{
	// Sæt members
	afventer_ = 0;
}

// Send aktiver kommando over X10
void X10IF::aktiver(char *adresse)
{
	char unwrapped[5];
	
	// Indsæt aktiver kode
	unwrapped[0] = 'a';
	
	// Indsæt adresse
	for(unsigned char i = 0; i < 4; i++)
		unwrapped[i + 1] = adresse[i];
		
	// Send kommando
	sendKommando(unwrapped);
}

// Send deaktiver kommando over X10
void X10IF::deaktiver(char *adresse)
{
	char unwrapped[5];
	
	// Indsæt aktiver kode
	unwrapped[0] = 'd';
	
	// Indsæt adresse
	for(unsigned char i = 0; i < 4; i++)
	unwrapped[i + 1] = adresse[i];
	
	// Send kommando
	sendKommando(unwrapped);
}

// Returner antallet af kommandoer i kø
unsigned char X10IF::getAfventer()
{
	return afventer_;
}

// Træk 1 fra antallet af kommandoer i kø
void X10IF::decreaseAfventer()
{
	// Træk en fra afventer_ hvis ikke 0
	if(afventer_ > 0)
		afventer_--;
}

// Aktiver ZeroCrossInt interrupt
void X10IF::enableInt0( )
{

	// Aktiver INT0
	GICR |= 0b01000000;
	
	// Interrupt ved toggles, ISC01/00: 01
	MCUCR |= 0b00000001;
	MCUCR &= 0b11111101;
	
	// Aktiver global interrupt
	sei();
}

// Deaktiver ZeroCrossInt interrupt
void X10IF::disableInt0( )
{
	// Deaktiver INT0
	GICR &= 0b10111111;
	
}

// Hent næste bit fra X10 bufferen
char X10IF::getBit()
{
	return buffer_.get();
}

// Wrap kommando til X10 formatet
void X10IF::wrap(char *unwrapped, char *wrapped)
{
	// Char ptr til næste ledige plads efter STX
	char *wrappedPtr = wrapped + 4;
	
	// Indsæt STX: 1110 (X10)
	wrapped[0] = '1';
	wrapped[1] = '1';
	wrapped[2] = '1';
	wrapped[3] = '0';
	
	// Indsæt første del af kommandoen: 001
	wrappedPtr = formatX10(wrappedPtr, '0');
	wrappedPtr = formatX10(wrappedPtr, '0');
	wrappedPtr = formatX10(wrappedPtr, '1');
	
	// Indsæt aktiver: 01 eller deaktiver: 11
	if((unwrapped[0] == 'a') || (unwrapped[0] == 'A'))
	{
		wrappedPtr = formatX10(wrappedPtr, '0');
		wrappedPtr = formatX10(wrappedPtr, '1');
	}
	else if((unwrapped[0] == 'd')  || (unwrapped[0] == 'D'))
	{

		wrappedPtr = formatX10(wrappedPtr, '1');
		wrappedPtr = formatX10(wrappedPtr, '1');
	}
	
	// Indsæt adresse XXXX
	for(unsigned char i = 0; i < 4; i++)
		wrappedPtr = formatX10(wrappedPtr, unwrapped[i + 1]);
	
	// Indsæt ETX: 000000 (X10)
	for(unsigned char i = 0; i < 6; i++)
		wrappedPtr[i] = '0';
}

// Indskriver X10 kommando i bufferen
void X10IF::sendKommando(char *unwrapped)
{
	// Indeholder kommando i X10 format
	char wrapped[X10_COMMAND_LENGHT];
	wrap(unwrapped, wrapped);
	
	// Indsæt bits i bufferen 2 gange
	for(unsigned char j = 0; j < 2; j++)
	{
		// Indsæt bits
		for(char i = 0; i < X10_COMMAND_LENGHT; i++)
			buffer_.insert(wrapped + i);
	}
	
	// Terminer bufferen
	char termChar = '\0';
	buffer_.insert(&termChar);
	
	// Forøg antallet af kommandoer der venter på at blive sendt
	afventer_++;
	
	// Aktiver ZeroCrossInt interrupt
	enableInt0();
}

// Indskriver komplimentær X10 bit værdi på plads og returnerer pointer til næste plads
char * X10IF::formatX10(char *plads, char bit)
{
	// Indsæt X10 format af bit 0
	if(bit == '0')
	{
		*plads = '0';
		*(plads + 1) = '1';
	}
	// Indsæt X10 format af bit 1
	else if(bit == '1')
	{
		*plads = '1';
		*(plads + 1) = '0';
	}
	
	// Returner ny pointer som peger på næste plads
	return plads + 2;
	
}

// Globalt objekt
X10IF X10IFObj = X10IF();