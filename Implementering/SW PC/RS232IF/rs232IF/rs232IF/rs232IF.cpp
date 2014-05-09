
#include "rs232IF.h"

#include <string>

using namespace std;

RS232IF::RS232IF()
{
	CSerial temp;
	serial = temp;
	// forsøger at åbne serie port.
	serial.Open("COM1");

	serial.Setup(CSerial::EBaud9600,CSerial::EData8,CSerial::EParNone,CSerial::EStop1);

	serial.SetupReadTimeouts(CSerial::EReadTimeoutNonblocking);

	login = false;
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

	serial.Write(message);
	
}
	
bool RS232IF::aktiver(int a)
{
	string start = "SA";
	string data = to_string(a);
	string slut = "cr";

	string message = start + data + slut;

	serial.Write(message);
}
	
bool RS232IF::deaktiver(int b)
{
	string start = "SD";
	string data = to_string(b);
	string slut = "cr";

	string message = start + data + slut;

	serial.Write(message);
}

int RS232IF::read()
{
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
    while (dwBytesRead == sizeof(abBuffer));
}