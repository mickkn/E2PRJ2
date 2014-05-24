
#pragma once

#include"ClickATellIF.h"

int main()
{
	clickATellIF CATObj;

	int mobil;

	cout << "Indtast 8-cifret modtager nummer: " << endl;
	cin >> mobil;

	CATObj.sendSMS(mobil);

	return 0;
}