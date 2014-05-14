
#include "deaktiver.h"

#include <iostream>

using namespace std;

deaktiver::deaktiver(RS232IF *rs, hukommelse *hu, brugerUI *ui)
{
	rsPtr = rs;
	huPtr = hu;
	uiPtr = ui;
}

void deaktiver::deaktiverEnhed()
{
	bool test;

	while(1)
	{
		test = true;
		int enhed = uiPtr->deaktiverMenu();
		if(enhed == 27)
			break;

		if(enhed == 100) // fail safe. bruger tastede noget ugyldigt.
		test = false;

		vector<string> temp = huPtr->getEnheder;
		int move = ((enhed*3) - 2); 
		string adresse = temp[move];

		bool test = rsPtr->deaktiver(adresse);
		if(test)
		{
			huPtr->saveStatus("false", enhed);
		}
	}
	uiPtr->mainMenu(); // vis main menu og exit controller
}