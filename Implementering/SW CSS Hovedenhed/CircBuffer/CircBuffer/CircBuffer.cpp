/*
 * Klasse CircBuffer Implementering
 *
 * Circulær buffer til X10 data. Kan indeholde 4 kommandoer
 *
 * Af Bjørn Sørensen
 *
 */

#include "CircBuffer.h"

CircBuffer::CircBuffer( )
{
	nextIndex_ = 0;				// Set next index
	currentIndex_ = 0;			// Set current index
	
	for(unsigned char i = 0; i < X10_ARRAY_SIZE; i++)
		array[i] = '\0';
	
}

CircBuffer & CircBuffer::insert( char *bit )
{
	// Indsæt bit på næste plads
	array[nextIndex_] = *bit;			
	
	// Læg én til index og moduler så den bliver inden for range
	(++nextIndex_) %= X10_ARRAY_SIZE;

	return *this;
}

char CircBuffer::get( )
{
	// Gem bit midlertidigt
	char temp = array[currentIndex_];
		
	// Læg én til index og moduler så den bliver inden for range
	(++currentIndex_) %= X10_ARRAY_SIZE;	
	
	// Returner bit
	return temp;

}

unsigned char CircBuffer::getNextIndex()
{
	return nextIndex_;
}
unsigned char CircBuffer::getCurrentIndex()
{
	return currentIndex_;
}