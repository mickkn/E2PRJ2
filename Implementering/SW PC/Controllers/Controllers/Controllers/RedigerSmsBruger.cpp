
#include "redigerSmsBruger.h"
#include <iostream>

using namespace std;

redigerSmsBruger::redigerSmsBruger(hukommelse * hu, brugerUI * ui)
{
	uiPtr = ui;
	huPtr = hu;
}

void redigerSmsBruger::redigerSMS()
{
	int nummer = huPtr->redigerSmsMenu();
	bool test = huPtr->saveNumber(nummer);

	if(test)
		cout << "nummeret blev gemt" << endl;
	else
		cout << "nummeret blev IKKE gemt" << endl;

	uiPtr->mainMenu;

}
