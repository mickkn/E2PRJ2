/*
 * X10IF.cpp
 *
 *  Author: jeppestaerk
 */ 


#include "X10IF.h"

X10IF::X10IF()
{
	DDRD &= 0b11010111;							// Sætter Port D, Pin 3 & 5 som indgange
	
	for (int i = 0; i < 28; i++)				// Fylder X10Array_et med 0'er
	{
		X10Array_[i] = 0;
	}
	
	for (int i = 0; i < 5; i++)					// Fylder X10Kommando_et med 0'er
	{
		X10Kommando_[i] = 0;
	}
	
	for (int i = 0; i < 4; i++)					// Fylder X10KAdresse_et med 0'er
	{
		X10Adresse_[i] = 0;
	}
	
	X10ArrayPlads_ = 0;							// Sætter X10ArrayPlads_ til 0	
	X10KommandoPlads_ = 0;						// Sætter X10KontrolPlads_ til 0	
	X10AdressePlads_ = 0;						// Sætter X10AdreesPlads_ til 0
}

void X10IF::setPointer(UC2Aktiver * UC2Ptr, UC3Deaktiver * UC3Ptr)
{
	UC2Ptr_ = UC2Ptr;							// Loader UC2Ptr ind på UC2Ptr_
	UC3Prt_ = UC3Ptr;							// Loader UC3Ptr ind på UC3Ptr_	
}

void X10IF::aktiverINT1()
{
	GICR  |= 0b10000000;						// Aktiver INT1
	MCUCR &= 0b11110111;						// INT1 ved toggel
	MCUCR |= 0b00000100;						// INT1 ved toggel
	sei();										// Aktiver Global interrupt
}

void X10IF::deaktiverINT1()
{
	GICR  &= 0b01111111;						// Deaktiver INT1
}

void X10IF::insertX10bit(char X10bit)
{
	X10Array_[X10ArrayPlads_] = X10bit;			// Indsætter "bit" på "X10plads" i X10array
	
	if (X10ArrayPlads_ == 0 && X10Array_[0] != 1)	// Kontroller X10Array_ for STX kommando bit[0]
	{
		X10ArrayPlads_ = 0;						// Nulstiller X10ArrayPlads_ til 0
	}	
	else if (X10ArrayPlads_ == 1 && X10Array_[0] != 1 && X10Array_[1])	// Kontroller X10Array_ for STX kommando bit[0] & [1]
	{
		X10ArrayPlads_ = 0;						// Nulstiller X10ArrayPlads_ til 0
	}	
	else if (X10ArrayPlads_ == 2 && X10Array_[0] != 1 && X10Array_[1] != 1 && X10Array_[2])	// Kontroller X10Array_ for STX kommando bit[0], [1] & [2]
	{
		X10ArrayPlads_ = 0;						// Nulstiller X10ArrayPlads_ til 0
	}
	else if (X10ArrayPlads_ == 3 && X10Array_[0] != 1 && X10Array_[1] != 1 && X10Array_[2] != 1 && X10Array_[3] != 0)	// Kontroller X10Array_ for STX kommando bit[0], [1], [2] & [3]
	{
		X10ArrayPlads_ = 0;						// Nulstiller X10ArrayPlads_ til 0
	}
	else if (X10ArrayPlads_ < 27)				// Kontroller om X10ArrayPlads_ er under 27
	{
		X10ArrayPlads_++;						// Skriver værdien af X10plads en op
	}	
	else if (X10ArrayPlads_ >= 27)				// Kontroller om X10ArrayPlads_ er 27 eller derover
	{
		unwrapX10Array(X10Array_);				// Sender X10Array_'er til funktionen unwrapX10Array
		X10ArrayPlads_ = 0;						// Sætter X10ArrayPlads_ til 0
	}
}

void X10IF::unwrapX10Array(char *X10Array)
{
	if (X10Array[0] == 1 && X10Array[1] == 1 && X10Array[2] == 1 && X10Array[3] == 0 && X10Array[22] == 0 && X10Array[23] == 0 && X10Array[24] == 0 && X10Array[25] == 0 && X10Array[26] == 0 && X10Array[27] == 0) // Kontroller X10Array_ for STX og ETX
	{	
		for (int i = 4; i < 14; i += 2)								// Henter kommandoen fra X10Array_'er fra bit [4] til bit [13]
		{
			if (X10Array[i] == 0 && X10Array[i+1] == 1)				// Kontroller X10Array_'et på plads [i] og [i+1] for '01' bit
			{
				X10Kommando_[X10KommandoPlads_] = 0;				// Indsætter '0' bit i X10Kommando_ på X10KommandoPlads_
				X10KommandoPlads_++;								// Tæller X10KommandoPlads_ en op
			}
			else if (X10Array[i] == 1 && X10Array[i+1] == 0)		// Kontroller X10Array_'et på plads [i] og [i+1] for '10' bit
			{
				X10Kommando_[X10KommandoPlads_] = 1;				// Indsætter '1' bit i X10Kommando_ på X10KommandoPlads_
				X10KommandoPlads_++;								// Tæller X10KommandoPlads_ en op
			}
		}
		
		for (int i = 14; i < 22; i += 2)							// Henter adressen fra X10Array_'er fra bit [14] til bit [21]
		{
			if (X10Array[i] == 0 && X10Array[i+1] == 1)				// Kontroller X10Array_'et på plads [i] og [i+1] for '01' bit
			{
				X10Adresse_[X10AdressePlads_] = 0;					// Indsætter '0' bit i X10Adresse_ på X10AdressePlads_
				X10AdressePlads_++;									// Tæller X10AdressePlads_ en op
			}
			else if (X10Array[i] == 1 && X10Array[i+1] == 0)		// Kontroller X10Array_'et på plads [i] og [i+1] for '10' bit	
			{
				X10Adresse_[X10AdressePlads_] = 1;					// Indsætter '1' bit i X10Adresse_ på X10AdressePlads_
				X10AdressePlads_++;									// Tæller X10AdressePlads_ en op
			}
		}
	}
	

	if (X10Kommando_[0] == 0 && X10Kommando_[1] == 0 && X10Kommando_[2] == 1 && X10Kommando_[3] == 0 && X10Kommando_[4] == 1)		// Kontroller om X10Kommando_ matcher aktiver kommando
	{
		UC2Ptr_->aktiver(X10Adresse_);		
	}
	else if (X10Kommando_[0] == 0 && X10Kommando_[1] == 0 && X10Kommando_[2] == 1 && X10Kommando_[3] == 1 && X10Kommando_[4] == 1)	// Kontroller om X10Kommando_ matcher deaktiver kommando
	{
		UC3Prt_->deaktiver(X10Adresse_);
	}
	
	X10KommandoPlads_ = 0;											// Sætter X10KommandoPlads_ til 0
	X10AdressePlads_ = 0;											// Sætter X10AdressePlads_ til 0
}

X10IF X10IFObj;

ISR(INT1_vect)
{
	X10IFObj.deaktiverINT1();
	
	_delay_us(DELAY_TIME);
	
	if (PIND == 0b00100000)
	{
		X10IFObj.insertX10bit(1);									// Sender '1' bit til X10array_
	}
	else
	{
		X10IFObj.insertX10bit(1);									// Sender '0' bit til X10array_
	}
	
	X10IFObj.aktiverINT1();
}