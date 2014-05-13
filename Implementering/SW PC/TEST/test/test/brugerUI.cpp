
#include "brugerUI.h"

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;

brugerUI::brugerUI(hukommelse *hu)
{
	huPtr = hu;
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
		string retur;
		cin.clear();
		getline(cin, retur,'\n');


		if(!cin) // Hvi brugeren indtaster nogeet der ikke er int
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}

		if(retur == "1")
			return 1;

		if(retur == "2")
			return 2;
		cin.clear();
	}
}

void brugerUI::login() const
{
	system("cls"); // clear screen

	cout << "CSS: Child Security System" << endl << endl;
	cout << "	Login på DE2 boardet" << endl << endl << endl << endl;
	cout << "	Tryk på en vilkårlig tast for at annullere" << endl;
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

	return 0;
}

int brugerUI::aktiverMenu() const
{
	system("cls"); // clear screen

	string temp;

	cout << "Følgende enheder er aktiveret:" << endl << endl;

	int myArray[15] = {0};

	int count;
	vector<string> tempVector = huPtr->getEnheder();

		for(int i = 1; i<tempVector.size(); i++)
		{
			if(tempVector[i] == "true")
			{
				if(i == 1)
					count = 1;
				else 
					count = i/3;

				temp = tempVector[i-1];
				cout << "	" << int(count) << ". Udtag " << temp << endl;					
			}			
		}
	
		cout << endl << "følgende enheder kan aktiveres: " << endl << endl;

		int counter2 = 0;

		for(int i = 1; i<tempVector.size(); i++)
		{
			if(tempVector[i] == "false")
			{
				temp = tempVector[i-1];
				if(i == 1)
					count = 1;
				else
					count = i/3;
				cout << "	" << int(count) << ". Udtag " << temp << endl;
				myArray[counter2] = i;	
				counter2++;
			}			
		}

	cout << endl << "Tast 27 for at gå tilbage til hovedemenuen" << endl;

	int num;

	cin >> num;
	if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		return 100;
	}

	if(num == 27) // Controller loop bliver exited
		return 27;

// loop til at kontrollere om indtastet værdi var en valid valgmulighed
	for(int i = 0; i<15; i++)  
	{
		if(num*3 == myArray[i] || num == 1)
		{
			if(num == 1)
				return 1;
			return num;	
		}
	}
// ikke ændret på noget da der er tastet forkert
	return 100;               
}
	

			
			

	
int brugerUI::deaktiverMenu() const
{
	system("cls"); // clear screen

	string temp;

	cout << "Følgende enheder er deaktiveret:" << endl << endl;

	int myArray[15] = {0};

	int count;
	vector<string> tempVector = huPtr->getEnheder();

		for(int i = 1; i<tempVector.size(); i++)
		{
			if(tempVector[i] == "false")
			{
				if(i == 1)
					count = 1;
				else 
					count = i/3;

				temp = tempVector[i-1];
				cout << "	" << int(count) << ". Udtag " << temp << endl;					
			}			
		}
	
		cout << endl << "følgende enheder kan deaktiveres: " << endl << endl;

		int counter2 = 0;

		for(int i = 1; i<tempVector.size(); i++)
		{
			if(tempVector[i] == "true")
			{
				temp = tempVector[i-1];
				if(i == 1)
					count = 1;
				else
					count = i/3;
				cout << "	" << int(count) << ". Udtag " << temp << endl;
				myArray[counter2] = i;	
				counter2++;
			}			
		}

	cout << endl << "Tast 27 for at gå tilbage til hovedemenuen" << endl;

	int num;

	cin >> num;
	if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		return 100;
	}

	if(num == 27)
		return 27; // Controller loop bliver exited

	for(int i = 0; i<15; i++)
	{
		if(num*3 == myArray[i] || num == 1)
		{
			if(num == 1)
				return 1;
			return num;	
		}
	}
	

	return 100; // ikke ændret på noget da der er tastet forkert     
}
	
int brugerUI::visStatusMenu() const
{
	system("cls"); // clear screen

	vector<string> tempVector = huPtr->getEnheder();

	cout << "Enhederne har følgende status" << endl << endl;

	int size = (tempVector.size() - 1) / 3;
	int counter;
	for(int i = 1; i<size+1; i++)
	{
	counter = ((i*3) - 2); 
	string navn = tempVector[counter+1];
	cout << setw(15) << navn << ": ";
		if(tempVector[counter+2] == "false")
			cout << setw(15) << "Deaktiv" << endl;
		if(tempVector[counter+2] == "true")
			cout << setw(15) << "Aktiv" << endl;
	
	}

	cout << endl << "Tast 27 for at gå tilbage til hovedemenuen" << endl;
	int num;

	cin >> num;

	if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		return 0;
	}

	if(num == 27)
		mainMenu();
		return 0; // return nada
}
	
int brugerUI::redigerSmsMenu() const
{
	system("cls"); // clear screen

	int num = huPtr->getNumber();

	cout << "sms modtager:" << endl;
	cout << "Tlf nr: " << num << endl << endl;
	cout << "Tryk 1. for at ændre tlf nr." << endl << endl;
	cout << "Tryk 27 for at gå tilbage til hovedmenu" << endl << endl;

	int retur;
	cin >> retur;

	if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		return 100;
	}

	if(retur == 27)
		return 0;

	if(retur == 1)
	{
		do
		{
			cout << "Indtast et 8 cifret tlf nr." << endl << endl;

			cin >> retur;

			if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
			if(retur == 27)
				return 0;

			if(retur > 99999999 || retur <10000000)
				cout << "nummer er invalid. skal være mindre end 99999999 og større end 10000000" << endl;

		}while(retur > 99999999 || retur <10000000);
	}
	
	return retur;
}
	
int brugerUI::addRemoveMenu() const
{
	system("cls"); // clear screen

	vector<string> tempVector = huPtr->getEnheder();
	int move;

	cout << endl << "Du har følgende enheder:" << endl << endl;

	for(int i = 1; i<=(tempVector.size()-1)/3; i++)
	{
		int move = ((i*3) - 2); 

		string text = tempVector[move+1];
		string adres = tempVector[move];
		cout << setw(4) << int(i) << ". " << setw(16) << text << setw(16) << adres << endl;

	
	}

	int retur;
	if(tempVector.size() >= 46)
	{	cout << "Der kan ikke tilføjes flere enheder" << endl <<
				"Slet nogle enheder hvis der ønskes at tilføje nye" << endl;
		cout << endl <<  "Tryk 1 for fjern enhed" << endl << endl;
		cout << "Tast 27 for at annullere" << endl;
		while(1)
		{
			cin >> retur;

			if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
			if(retur == 1)
				return 0;

			if(retur == 27)
				return 27;
		}
	}
	else
	{
		cout << "Ønsker du at tilføje eller fjerne udtag?" << endl << endl;
		cout << "Tast 1 for fjerne enhed" << endl;
		cout << "Tast 2 for tilføje enhed." << endl << endl;
		cout << "Tast 27 for at annullere" << endl;
		while(1)
		{		
			string retur;
			getline(cin, retur,'\n');


			if(!cin) // Hvi brugeren indtaster nogeet der ikke er int
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}
			if(retur == "1")
				return 0;
		
			if(retur == "27")
				return 27;

			if(retur == "2");
				return 1;
		}
	}
}