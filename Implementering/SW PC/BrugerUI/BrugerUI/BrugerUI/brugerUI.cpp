
#include "brugerUI.h"
#include "Cursor.h"

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

brugerUI::brugerUI()
{
	Cursor curObj();
}

void brugerUI::showMenu(int menu)
{
	while(1)
	{
		if(menu == 0)   // vis prelogin menu. Login og vis status kan vælges
		{
			menu = preLogin();
		}

		if(menu == 1)	// login menu. bruger skal login på DE2 eller tryk ESC
		{
			menu = login();
		}

		if(menu == 2)	// main menu. 
		{
			menu = mainMenu();
		}

		if(menu == 3) // vis status menu
		{
		
		}

		if(menu == 4)	// aktiver menu
		{
		
		}

		if(menu == 5)	// deaktiver menu
		{
		
		}

		if(menu == 6)	// rediger sms modtager menu
		{}

		if(menu == 7)	// tilføj / fjern enheder menu
		{}

	}


}

int brugerUI::preLogin() const
{
	system("cls");  // clear screen.
	
	cout << "CSS: Child Security System" << endl << endl;
	cout << "	1. Login" << endl;
	cout << "	2. Vis status" << endl;

	char temp;

	while(1)
	{
	cin >> temp;

	if(temp == 1)
		return 1;

	if(temp == 2)
		return 2;

	}
}

int brugerUI::login() const
{
	system("cls"); // clear screen

	cout << "CSS: Child Security System" << endl << endl;
	cout << "	Login på DE2 boardet" << endl << endl << endl << endl <<;
	cout << "	Tryk ESC for at annullere" << endl;

	char c;

	 while(1)
    {
		////////////// Login kald mangler! ///////////////

        c=getch();
        if(c == 27)
		{
        return 0;
		}
    }
}

int brugerUI::mainMenu() const
{
	system("cls"); // clear screen

	cout << "CSS: Child Security System" << endl << endl;
	cout << "	1. Aktiver enheder" << endl;
	cout << "	2. Deaktiver enheder" << endl;
	cout << "	3. Vis status" << endl;
	cout << "	4. Rediger sms-modtager" << endl;
	cout << "	5. Tilføj / fjern enheder" << endl;

	char temp;

	while(1)
	{
		cin >> temp;

		if(temp == 1)
			return 4; // aktiver menu int.

		if(temp == 2)
			return 5; // deaktiver menu int.

		if(temp == 3)
			return 3; // vis status int.

		if(temp == 4)
			return 6; // rediger sms bruger int.

		if(temp == 5)
			return 7; // tilføj fjern menu int.

	}
}

int brugerUI::aktiverMenu() const
{
	system("cls"); // clear screen

	while(1) // mangler rigtigt kald til RS232 klasse   loginValid()
	{
		string temp;
		cout << "Følgende enheder er aktiveret:" << endl << endl;

		vector<string> tempVector = objHuk.getEnheder;

		int myArray[15] = {0};

			for(int i = 1; i<tempVector.size(); i++)
			{
				if(tempVector[i] == "true")
				{
					temp = tempVector[i-1];
					cout << "	" << ". Udtag " << temp << endl;
				
				}			
			}
	
			cout << "følgende enheder kan aktiveres: " << endl << endl;

			for(int i = 1; i<tempVector.size(); i++)
			{
				if(tempVector[i] == "false")
				{
					temp = tempVector[i-1];
					cout << "	" << i << ". Udtag " << temp << endl;
				
				}			
			}

		cout << "Tryk ESC for at gå tilbage til hovedemenuen" << endl;

		char c;
		 while(1)
		{
			cin >> c;

			c=getch();
			if(c == 27)
			{
			return 99; // aktiver controller stopper loop
			}
		}

	}

	return 0; // hvis der ikke er logget ind længere returneres der til prelogin menuen.
}
	
int brugerUI::deaktiverMenu() const
{
	system("cls"); // clear screen

	

	if(1) // mangler rigtigt kald til RS232 klasse   loginValid()
	{
		string temp;
		cout << "Følgende enheder er deaktiveret:" << endl << endl;

		vector<string> tempVector = objHuk.getEnheder;

		int myArray[15] = {0};

			for(int i = 1; i<tempVector.size(); i++)
			{
				if(tempVector[i] == "false")
				{
					temp = tempVector[i-1];
					cout << "	" << i << ". Udtag " << temp << endl;
				
				}			
			}
	
			cout << "følgende enheder kan deaktiveres: " << endl << endl;

			int counter = 0; // tæller antallet af enheder der kan deaktiveres, til arrayet

			for(int i = 1; i<tempVector.size(); i++)
			{
				if(tempVector[i] == "true")
				{
					temp = tempVector[i-1];
					myArray[counter] = (i-2); // array til første plads på hver enhed der kan deaktiveres
					counter++;
					cout << "	" << i << ". Udtag " << temp << endl;
				
				}			
			}
		cout << "Tryk ESC for at gå tilbage til hovedemenuen" << endl;

		char c;
		 while(1)
		{
			cin >> c;
			for(int i = 0; i<15; i++)
			{
				if(myArray[i] == c)

			}
			c=getch();
			if(c == 27)
			{
			return 2; // Main menu int.
			}
		}
	}

	return 0; // hvis der ikke er logget ind længere returneres der til prelogin menuen.
}
	
int brugerUI::visStatusMenu() const
{

}
	
int brugerUI::redigerSmsMenu() const
{
	int num = huPtr->getNumber;

	cout << "sms modtager:" << endl;
	cout << "Tlf nr: " << num << endl << endl;
	cout << "Tryk 1. for at ændre tlf nr." << endl << endl;
	cout << "Tryk ESC for at gå tilbage til hovedmenu" << endl;

	int retur;
	do
	{
		cin >> retur;
		if(retur > 99999999 || retur <10000000)
			cout << "nummer er invalid. skal være mindre end 99999999 og større end 10000000" << endl;
	}while(retur > 99999999 || retur <10000000);
	
	return retur;
}
	
int brugerUI::addRemoveMenu() const
{
	vector<string> tempVector = objHuk.getEnheder;
	int move;

	cout << "Du har følgende enheder:" << endl << endl;

	for(int i = 0; i<16; i++)
	{
		int move = ((i*3) - 2); 
		while(move < tempVector.size())
		{
		string text = tempVector[move];
		cout << "	" << i << ". " << text << endl;
		}
	
	}

	if(tempVector.size() >= 46)
	{	cout << "Der kan ikke tilføjes flere enheder" << endl <<
				"Slet nogle enheder hvis der ønskes at tilføje nye" << endl;
	}

	cout << "Ønsker du at tilføje eller fjerne udtag?" << endl;
	cout << "Tryk T for tilføje enhed." << "Tryk F for fjern enhed" << endl;
	cout << "Tryk ESC for at annullere" << endl;

	char c;
	while(1)
	{
		cin >> c;
		if(c == 'T' || c == 't')
		{
			return 1;

		if(c == 'F' || c == 'f')
			return 0;

		}
		c=getch();
		if(c == 27)
		{
		return 2;
		}
	}
}