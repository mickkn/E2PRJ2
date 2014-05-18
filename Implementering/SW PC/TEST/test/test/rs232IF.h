
#pragma once

#include "Serial.h"

#define port 3
#define commandSize 7

class RS232IF
{
public:
	RS232IF();
	~RS232IF();
	bool validLogin();
	bool aktiver(int);
	bool deaktiver(int);
	int read();

private:
	CSerial serial;
};