#pragma once;

#include "rs232IF.h"
#include "Serial.h"

#include <iostream>

using namespace std;

int main()
{
	RS232IF objRS;
	bool testing = true; // kør test 1 gang

	while(testing)
	{
		cout << "Aktiver kaldes og sender SA1111." << endl << "read() læser og udskriver beskeden og returnere 0: " << endl;
		objRS.aktiver(1111);
		int test1 = objRS.read();
		cout << "read returnerede: " << test1 << endl << endl;
		
		Sleep(2000);

		cout << "Deaktiver kaldes og sender SD1111. " << endl << "read() læser og udskriver beskeden og returnere 0: " << endl;
		objRS.deaktiver(1111);
		int test2 = objRS.read();
		cout << "read returnerede: " << test2 << endl << endl;

		Sleep(2000);

		cout << "Test af returværdi for read() metode" << endl << endl;
		cout << "ST9999 sendes og read skal gerne returnere 1: " << endl;
		objRS.tester("ST9999");
		int test3 = objRS.read();
		cout << "read returnerede: " << test3 << endl << endl;

		Sleep(2000);

		cout << "SF9999 sendes og read() skal gerne returnere 2: " << endl;
		objRS.tester("SF9999");
		int test4 = objRS.read();
		cout << "read returnerede: " << test4 << endl << endl;

		Sleep(2000);

		cout << "SB9999 sendes og read() skal gerne returnere 3: " << endl;
		objRS.tester("SB9999");
		int test5 = objRS.read();
		cout << "read returnerede: " << test5 << endl << endl;
		

		cout << "Test done!";
		testing = false;

	}

	while(1);
}