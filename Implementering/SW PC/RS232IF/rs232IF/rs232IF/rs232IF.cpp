
#include "rs232IF.h"

#include <string>
#include <iostream>

using namespace std;

RS232IF::RS232IF() 
{
	CSerial temp;
	serial = temp;

	serial.Open(port, 9600);
	/*
	// forsøger at åbne serie port.
	serial.Open("COM1");

	serial.Setup(CSerial::EBaud9600,CSerial::EData8,CSerial::EParNone,CSerial::EStop1);

	serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);

	login = false;*/
}

RS232IF::~RS232IF()
{
	// forsøger at lukke serie port.
	serial.Close();
}

bool RS232IF::loginValid()
{
	if(login == true)
		return true;

	string start = "SL";
	string data = "0000";
	string slut = "cr";

	string message = start + data + slut;

	//serial.Write(message);
	
}
	
bool RS232IF::aktiver(int a)
{
	string start = "SA";
	string data = to_string(a);
	string slut = "cr";

	string message = start + data + slut;
	const char * c = message.c_str();

	serial.SendData( c, 8);
	return true;
	/*
	serial.Write(message);
	*/
}
	
bool RS232IF::deaktiver(int b)
{
	string start = "SD";
	string data = to_string(b);
	string slut = "cr";

	string message = start + data + slut;
	const char * c = message.c_str();

	serial.SendData( c, 8);
	return true;
	/*
	serial.Write(message);
	*/
}

int RS232IF::read()
{
	string reading;
	void *ptr = &reading;

	if(serial.ReadDataWaiting() >= 8)
	{
		serial.ReadData(ptr, 8);
		cout << "data was read" << endl;
	}

	if(reading[0] == 'b' || reading[0] == 'B')
		return 2;

	if(reading[0] == 't' || reading[0] == 'T')
		return 1;

	return 0;

	/*
	// Read data, until there is nothing left
	unsigned long int abBuffer[100];
	long int dwBytesRead = 0;
    do
    {
        // Read data from the COM-port
        serial.Read(abBuffer ,sizeof(abBuffer),&dwBytesRead);
        if (dwBytesRead > 0)
        {
            // TODO: Process the data
        }
    }
    while (dwBytesRead == sizeof(abBuffer));*/
}