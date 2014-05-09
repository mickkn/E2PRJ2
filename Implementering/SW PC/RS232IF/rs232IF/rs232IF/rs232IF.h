
#pragma once

#include "Serial.h"

class RS232IF
{
public:
	RS232IF();
	~RS232IF();
	bool loginValid();
	bool aktiver(int);
	bool deaktiver(int);
	int read();

private:
	CSerial serial;
	bool login;
};