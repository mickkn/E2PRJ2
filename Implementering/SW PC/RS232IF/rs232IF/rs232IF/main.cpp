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
		cout << "Aktiver kaldes og sender SA1111. read() læser og udskriver beskeden og returnere 0: " << endl;
		objRS.aktiver(1111);
		int test = objRS.read();
		cout << "read() returnerede: " << test << endl << endl;
		
		Sleep(2000);

		cout << "Deaktiver kaldes og sender SD1111. read() læser og udskriver beskeden og returnere 0: " << endl;
		objRS.deaktiver(1111);
		int test = objRS.read();
		cout << "read() returnerede: " << test << endl << endl;

		Sleep(2000);

		cout << "Test af returværdi for read() metode" << endl << endl;
		cout << "ST9999 sendes og read() skal gerne returnere 1: " << endl;
		bool tester("ST999");
		int test = objRS.read();
		cout << "read() returnerede: " << test << endl << endl;

		Sleep(2000);

		cout << "SF9999 sendes og read() skal gerne returnere 2: " << endl;
		bool tester("SF999");
		int test = objRS.read();
		cout << "read() returnerede: " << test << endl << endl;

		Sleep(2000);

		cout << "SB9999 sendes og read() skal gerne returnere 3: " << endl;
		bool tester("SB999");
		int test = objRS.read();
		cout << "read() returnerede: " << test << endl << endl;
		
		testing = false;

	}

	while(1);
}