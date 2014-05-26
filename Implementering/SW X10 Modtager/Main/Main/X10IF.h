/*
 * X10IF.h
 *
 * Created: 26-05-2014 13:17:10
 *  Author: jeppestaerk
 */ 


#pragma once

#define F_CPU 3686400
#define DELAY_TIME 40

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "UC2Aktivere.h"
#include "UC3Deaktiver.h"

class X10IF
{
public:
	X10IF();
	void setPointer(UC2Aktiver * UC2Ptr, UC3Deaktiver * UC3Ptr);
	void aktiverINT1();
	void deaktiverINT1();
	void insertX10bit(char X10bit);
	void unwrapX10Array(char *X10Array);
private:
	char X10Array_[28];
	char X10Kommando_[5];
	char X10Adresse_[4];
	char X10ArrayPlads_;
	char X10KommandoPlads_;
	char X10AdressePlads_;
	UC2Aktiver * UC2Ptr_;
	UC3Deaktiver * UC3Prt_;	
};

extern X10IF X10IFObj;