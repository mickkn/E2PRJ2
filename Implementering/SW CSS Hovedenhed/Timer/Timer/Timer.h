/*
 * Klasse Timer Header
 *
 * Styrer intern timer1 i atmega32 processor
 *
 *  Af Bjørn Sørensen
 */ 

#pragma once

#include <avr/io.h>

class Timer{
public:
	Timer();
	~Timer();
	
	void start();	// Start timer på 120 kHz
	void stop();	// Stop timer
};

extern Timer timer;