
#pragma once

#include "Serial.h"
#include <string>

using namespace std;

#define port 3
#define commandSize 7

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