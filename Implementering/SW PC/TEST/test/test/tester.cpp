#define NOMINMAX // fix til windows.h bug
#pragma once

#include "aktiver.h"
#include "deaktiver.h"
#include "brugerUI.h"
#include "hukommelse.h"
#include "redigerSmsBruger.h"
#include "udtag.h"
#include "Login.h"
#include "ClickATellIF.h"

#include <conio.h>

int main()
{
	hukommelse huObj;
	hukommelse * huPtr = &huObj;
	RS232IF rsObj;
	RS232IF * rsPtr = &rsObj;
	brugerUI uiObj(huPtr);
	brugerUI * uiPtr = &uiObj;
	aktiver aktiverObj(rsPtr, huPtr, uiPtr);
	deaktiver deaktiverObj(rsPtr, huPtr, uiPtr);
	udtag udtagObj(huPtr, uiPtr);
	redigerSmsBruger smsObj(huPtr, uiPtr);
	login logObj(rsPtr, uiPtr);
	clickATellIF SMSObj;

	char ch;
	
	logObj.loginValid();

	while(1)
	{
		while(!kbhit())
		{
			int read = rsObj.read();
			if(read == 2) // Hvis login udløbet
			{
				bool test = logObj.loginValid();

				if(test == true) // break while når der er logget ind igen.
					break;
			}
			if(read == 3)
			{
				// BABY ALARM KALD 
				SMSObj.sendSMS(huObj.getNumber());
			}
				
		}

		int i;
		cin >> i;

		//ch = getch();
		//int i = (int)((char)ch - '0');
		//cin >> i;

		if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}

		if(i == 1)	// aktiver menu
		{
			aktiverObj.aktiverEnhed();
		}

		if(i == 2)	// deaktiver menu
		{
			deaktiverObj.deaktiverEnhed();
		}

		if(i == 3) // vis status menu
		{
			uiObj.visStatusMenu();
		}

		if(i == 4)	// sms bruger menu
		{
			smsObj.redigerSMS();
		}

		if(i == 5)	// tilføj fjern menu
		{
			udtagObj.addRemoveUdtag();
		}
	}
}
