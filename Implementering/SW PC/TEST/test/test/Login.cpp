
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

		uiPtr->login();
		rsPtr->validLogin();		// spørger STK kit om der er logget ind
		while(!kbhit)
		{
			int read = rsPtr->read(); // læser svar fra STK kit indtil brugeren annullere med kbhit
			if(read == 1)// når read returnere 1 betyder det at der er logget ind
			{
				uiPtr->mainMenu;
				return true;
			}
		}
		return false;			// hvis bruger annullere inden login er godtaget returneres false
	}
}
