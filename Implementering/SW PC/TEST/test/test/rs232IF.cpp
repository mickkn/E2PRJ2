
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


	
bool RS232IF::aktiver(int a)
{
	string start = "SA";
	string data = to_string(a);
	char slut = '\r';

	string message = start + data + slut;
	const char * c = message.c_str();
	serial.SendData( c, commandSize);
	return true;
}
	
bool RS232IF::deaktiver(int b)
{
	string start = "SD";
	string data = to_string(b);
	char slut = '\r';

	string message = start + data + slut;
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
		cout << "data was read" << endl;
	}
	string reading(ipBuffer, commandSize);

	cout << reading << endl;
	delete []ipBuffer;

	if(reading[0] == 'b' || reading[0] == 'B') // Lyd detekteret
		return 3;

	if(reading[0] == 't' || reading[0] == 'T') // Login 
		return 1;

	if(reading[0] == 'f' || reading[0] == 'F') // Login udløbet
		return 2;

	return 0;
}