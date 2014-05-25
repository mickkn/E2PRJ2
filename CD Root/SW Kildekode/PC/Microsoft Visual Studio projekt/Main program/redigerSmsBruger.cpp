
#include "redigerSmsBruger.h"
#include <iostream>
#include <windows.h>

using namespace std;

redigerSmsBruger::redigerSmsBruger(hukommelse * hu, brugerUI * ui)
{
	uiPtr = ui;
	huPtr = hu;
}

void redigerSmsBruger::redigerSMS()
{
	bool test = true;

	while(test)
	{
		int nummer = uiPtr->redigerSmsMenu();
		if(nummer == 0)
			break;

		bool gemt = huPtr->saveNumber(nummer);

		if(gemt)
		{
			int nr = huPtr->getNumber();
			cout << endl << endl << int(nr) << " blev gemt" << endl;
			Sleep(4000);
			test = false;
		}
		else
			cout << "nummeret blev IKKE gemt" << endl;
	}

	uiPtr->mainMenu();

}
