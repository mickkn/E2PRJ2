#define NOMINMAX // fix til windows.h bug
#pragma once

#include "aktiver.h"
#include "deaktiver.h"
#include "brugerUI.h"
#include "hukommelse.h"
#include "redigerSmsBruger.h"
#include "udtag.h"
#include "Login.h"

#include <conio.h>

int main()
{
	hukommelse huObj;
	hukommelse * huPtr = &huObj;
	brugerUI uiObj(huPtr);
	brugerUI * uiPtr = &uiObj;

	udtag udtagObj(huPtr, uiPtr);
	redigerSmsBruger smsObj(huPtr, uiPtr);
	RS232IF rsObj;
	RS232IF * rsPtr = &rsObj;
	login logObj(rsPtr, uiPtr);
	aktiver aktiverObj(rsPtr, huPtr, uiPtr);
	deaktiver deaktiverObj(rsPtr, huPtr, uiPtr);

	//char ch;
	int i;
	bool testing = false;
	uiObj.preLogin; // viser altid preLogin menu f�rst

	while(1)
	{
		while(!testing)
		{

			cin >> i;

			if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
			}

			if(i == 1)	// login menu
			{
				testing = logObj.loginValid();
			}

			if(i == 2)
			{
				uiObj.visStatusMenu();
			}
			else
				cin.clear();
		}

		
		cin >> i;


		//ch = getch();
		//int i = (int)((char)ch - '0');
		//cin >> i;

		if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}

		if(i == 2)	// login menu
		{
			logObj.loginValid();
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

		if(i == 5)	// tilf�j fjern menu
		{
			udtagObj.addRemoveUdtag();
		}
		else
			cin.clear();

		while(!kbhit)
		{
			int read = rsObj.read();
			if(read == 2)
			{
				bool test = logObj.loginValid();

				if(test == true) // break while n�r der er logget ind igen.
					break;
			}
			if(read == 3)
			{
						// BABY ALARM KALD ////////////////////////////////////
				cout << " BABY ALARM OMG!" << endl;
			}		
		}
	}
}
