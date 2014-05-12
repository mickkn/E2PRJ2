#pragma once;

#include "rs232IF.h"
#include "Serial.h"

#include <iostream>

using namespace std;

int main()
{
	RS232IF objRS;

	objRS.aktiver(1111);

	int aktiver = objRS.read();

	Sleep(1000);
	cout << aktiver << endl;



	while(1);
}