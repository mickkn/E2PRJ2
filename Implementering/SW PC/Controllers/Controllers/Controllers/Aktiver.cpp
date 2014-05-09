
#include "aktiver.h"

#include <iostream>

using namespace std;

aktiver::aktiver(RS232IF *rs, hukommelse *hu, brugerUI *ui)
{
	rsPtr = rs;
	huPtr = hu;
	uiPtr = ui;
}

void aktiver::aktiverEnhed()
{
	while(1)
	{
		int enhed = uiPtr->aktiverMenu;
		if(enhed == 99)
			break;

		bool test = rsPtr->aktiver(enhed);
		if(test)
		{
			huPtr->saveStatus("true", enhed);
		}
		else
			cout << "enhedens status blev ikke ændret" << endl;
	}
	uiPtr->mainMenu; // vis main menu og exit controller
}