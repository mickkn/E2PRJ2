#pragma once;

#include "rs232IF.h"
#include "Serial.h"

#include <iostream>

using namespace std;

int main()
{
	RS232IF objRS;
	
	while(1)
	{
	int aktiver = objRS.read();

	Sleep(3000);
	cout << aktiver << endl;

	objRS.aktiver(1111);

	}

	while(1);
}