
#include "deaktiver.h"

#include <iostream>

using namespace std;

deaktiver::deaktiver(RS232IF *rs, hukommelse *hu, brugerUI *ui)
{
	rsPtr = rs;
	huPtr = hu;
	uiPtr = ui;
}

void deaktiver::deaktiverEnhed(int adresse)
{
	while(1)
	{
		int enhed = uiPtr->deaktiverMenu;
		if(enhed == 99)
			break;

		bool test = rsPtr->deaktiver(enhed);
		if(test)
		{
			huPtr->saveStatus("false", enhed);
		}
		else
			cout << "enhedens status blev ikke ændret" << endl;
	}
	uiPtr->mainMenu; // vis main menu og exit controller
}