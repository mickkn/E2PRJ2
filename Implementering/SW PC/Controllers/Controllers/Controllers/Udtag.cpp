
#include "udtag.h"
#include <iostream>
#include <string>

using namespace std;

udtag::udtag(hukommelse * hu, brugerUI * ui)
{
	uiPtr = ui;
	huPtr = hu;
}

void udtag::addRemoveUdtag()
{
	int resultat = uiPtr->addRemoveMenu();
	if(resultat = 1)
	{
		cout << "Navngiv venligst enheden" << endl;
		string navn;
		getline(cin, navn);
		string adresse;
		cout << "Angiv venligst adresse kode" << endl;
		getline(cin, adresse);
		bool test = huPtr->saveAdresse(adresse, navn);
		if(test)
		{
			cout << "Enhed tilføjet" << endl;

		}
		else
			cout << "Enhed blev ikke tilføjet" << endl;
	}

	if(resultat = 0)
	{
		cout << "Angiv hvilken enhed der skal fjernes" << endl;
		int nr;
		cin >> nr;
		bool test = huPtr->removeAdresse(nr);
		if(test)
		{
			cout << "Enhed fjernet" << endl;

		}
		else
				cout << "Enhed blev ikke fjernet" << endl;
	}

		uiPtr->mainMenu; // vis main menu og exit controller
}
