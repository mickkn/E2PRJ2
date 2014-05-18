
#pragma once

#include "Serial.h"
#include <string>

#define port 4
#define commandSize 7

using namespace std;

class RS232IF
{
public:
	RS232IF();
	~RS232IF();
	bool validLogin();
	bool aktiver(string);
	bool deaktiver(string);
	int read();

private:
	CSerial serial;
};