
#include "aktiver.h"

#include <iostream>

using namespace std;

aktiver::aktiver(/*RS232IF *rs,*/ hukommelse *hu, brugerUI *ui)
{
	//rsPtr = rs;
	huPtr = hu;
	uiPtr = ui;
}

void aktiver::aktiverEnhed()
{
	bool test;

	while(1)
	{
		test = true;
		int enhed = uiPtr->aktiverMenu();
		if(enhed == 27)
			break;

		if(enhed == 100) // fail safe. bruger tastede noget ugyldigt.
			test = false;

		//bool test = rsPtr->aktiver(enhed);
		if(/*test*/ test)
		{
			huPtr->saveStatus("true", enhed);
		}
	}
	uiPtr->mainMenu(); // vis main menu og exit controller
}