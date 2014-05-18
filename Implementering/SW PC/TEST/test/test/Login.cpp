
#include "login.h"
#include "brugerUI.h"

#include <conio.h>

login::login(RS232IF * rs, brugerUI * ui)
{
	rsPtr = rs;
	uiPtr = ui;
}

bool login::loginValid()
{
	while(1)
	{	
		cout << "entered login" << endl;
		bool tester = true;
		uiPtr->login();
		rsPtr->validLogin();		// spørger STK kit om der er logget ind
		cin.clear();
		while(!kbhit())
		{
			int read = rsPtr->read(); // læser svar fra STK kit indtil brugeren annullere med kbhit
			if(read == 1)// når read returnere 1 betyder det at der er logget ind
			{
<<<<<<< HEAD
				int read = rsPtr->read();
				if(read == 1)
				{
					return true;
					uiPtr->mainMenu();
				}
=======
				uiPtr->mainMenu();
				return true;
>>>>>>> parent of fe63449... Git hub fucker. committer ALT i repos.
			}

			if(kbhit())
				tester = false;
		}
		return false;			// hvis bruger annullere inden login er godtaget returneres false
	}
}
