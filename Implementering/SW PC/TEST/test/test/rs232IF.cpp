
#include "rs232IF.h"

#include <string>
#include <iostream>

using namespace std;

RS232IF::RS232IF()
{
	serial.Open(port, 9600);
}

RS232IF::~RS232IF()
{
	// forsøger at lukke serie port.
	serial.Close();
}

bool RS232IF::validLogin()
{
	string start = "SL";
	string data = "9999";
	char slut = '\r';

	string message = start + data + slut;
	const char * c = message.c_str();
	serial.SendData( c, commandSize);
	return true;
}


	
bool RS232IF::aktiver(string adresse)
{
	string start = "SA";
	char slut = '\r';

	string message = start + adresse + slut;
	const char * c = message.c_str();
	serial.SendData( c, commandSize);
	return true;
}
	
bool RS232IF::deaktiver(string adresse)
{
	string start = "SD";
	char slut = '\r';

	string message = start + adresse + slut;
	const char * c = message.c_str();

	serial.SendData( c, commandSize);
	return true;
}

int RS232IF::read()
{

	char *ipBuffer = new char[commandSize+1];

	if(serial.ReadDataWaiting() >= 7)
	{
		serial.ReadData(ipBuffer, commandSize+1);
	}
	string reading(ipBuffer, commandSize);

	delete []ipBuffer;

	if(reading[1] == 'b' || reading[1] == 'B') // Lyd detekteret
		return 3;

	if(reading[1] == 't' || reading[1] == 'T') // Login 
		return 1;

	if(reading[1] == 'f' || reading[1] == 'F') // Login udløbet
		return 2;

	return 0;
}