#define NOMINMAX // fix til windows.h bug

#include "udtag.h"
#include <iostream>
#include <string>
#include <Windows.h>



using namespace std;

udtag::udtag(hukommelse * hu, brugerUI * ui)
{
	uiPtr = ui;
	huPtr = hu;
}

void udtag::addRemoveUdtag()
{
	

	bool imens = true;
	while(imens)
	{
		bool test = false;
		int resultat = uiPtr->addRemoveMenu();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		if(resultat == 1)
		{
			cout << "Navngiv venligst enheden" << endl;
			string navn;
			getline(cin, navn,'\n');

			string adresse;
			while(!test)
			{
				vector<string> tempVector = huPtr->getEnheder();
				cout << "Angiv venligst valid adresse kode" << endl;
				cin.clear();
				getline(cin, adresse,'\n');

				int counter = 0;
				if(adresse.size() == 4)
				{
					for(int i = 0; i<4; i++)
					{
						if(adresse[i] == '1' || adresse[i] == '0')
							counter++;
					}

					if(counter == 4)
					{
						bool tasting = true;
						//while(tasting)
						//{
							for(int i = 1; i<=(tempVector.size()-1)/3; i++)
							{
								int move = ((i*3) - 2);
								if(tempVector[move] == adresse)
								{
									cout << endl << "adressen er allerede brugt, vælg en anden" << endl << endl;
									//i = 100;
									tasting = false;
									break;
								}
							}
							if(tasting == true)
								test = huPtr->saveAdresse(adresse, navn);

							
						//}				
					}
				}
				
			}
			if(test)
			{
				cout << "Enhed tilføjet" << endl;
				Sleep(3000);
			}
			else
			{
				cout << "Enhed blev ikke tilføjet" << endl;
				Sleep(3000);
			}
		}

		if(resultat == 0)
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
		if(resultat == 27)
			imens = false;
	}
		uiPtr->mainMenu(); // vis main menu og exit controller
}
