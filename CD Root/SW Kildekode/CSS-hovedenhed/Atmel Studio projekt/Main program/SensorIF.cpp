/*
 * Klasse SensorIF
 *
 * Interface til lyddetektoren
 *
 *  Af Bjørn Sørensen
 */ 

#include "SensorIF.h"

SensorIF::SensorIF()
{
	
	// Sæt input port INT1
	DDRD &= 0b11110111;
	
	// Aktiver interrupt ved skift til høj
	GICR |= 0b10000000;
	MCUCR |= 0b00001100;
	sei();
}

SensorIF::~SensorIF()
{
	// Deaktiver interrupt
	GICR &= 0b01111111;
}

void SensorIF::alarmer()
{
	UC5Ptr_->detekterLyd();
}

void SensorIF::setUC5Ptr(UC5DetekterLyd * Ptr)
{
	UC5Ptr_ = Ptr;
}

SensorIF SensorIFObj;

// INT1 ISR
ISR(INT1_vect)
{
	SensorIFObj.alarmer( );
}