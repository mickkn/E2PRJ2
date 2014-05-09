#pragma once

#include "aktiver.h"
#include "deaktiver.h"
#include "brugerUI.h"
#include "hukommelse.h"
#include "redigerSmsBruger.h"
#include "udtag.h"

#include <conio.h>

int main()
{
	hukommelse huObj;
	hukommelse * huPtr = &huObj;
	brugerUI uiObj(huPtr);
	brugerUI * uiPtr = &uiObj;
	aktiver aktiverObj(huPtr, uiPtr);
	deaktiver deaktiverObj(huPtr, uiPtr);
	udtag udtagObj(huPtr, uiPtr);
	redigerSmsBruger smsObj(huPtr, uiPtr);

	char ch;
	

	while(1)
	{
		uiObj.mainMenu();
		ch = getch();
		int i = (int)((char)ch - '0');
		//cin >> i;

		if(!cin) // Hvis brugeren indtaster nogeet der ikke er int
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}

		if(i == 0)   // vis prelogin menu. Login og vis status kan vælges
		{
		
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

		while(1);




}