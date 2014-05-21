/*
 * Klasse CircBuffer header
 *
 * Circulær buffer til X10 data. Kan indeholde 4 kommandoer
 *
 * Af Bjørn Sørensen
 *
 */

#pragma once
#define X10_ARRAY_SIZE 4*29 // 4 kommandoer af 28 tegn plus kommando terminering

class CircBuffer {

public:
	CircBuffer( );

	CircBuffer & insert( char * );
	char get( );
	
	unsigned char getNextIndex();
	unsigned char getCurrentIndex();

private:
	unsigned char nextIndex_;		// Næste index til indskrivning
	unsigned char currentIndex_;	// Næste index til udlæsning
	char array[X10_ARRAY_SIZE];		// Array til kommandoer

};