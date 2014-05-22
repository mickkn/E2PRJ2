
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
		int valg = uiPtr->preLogin(); // vis prelogin

		if(valg == 2)
			uiPtr->visStatusMenu();

	
		if(valg == 1)
		{
			uiPtr->login();		// Login besked
			rsPtr->validLogin();	// Afsend SL999
			while(!kbhit())
			{
				int read = rsPtr->read();
				

				if(read == 1)
				{
					uiPtr->mainMenu();
					return true;
				}
			}
		}
	}
}
