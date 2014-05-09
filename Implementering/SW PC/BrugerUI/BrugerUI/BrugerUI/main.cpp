

#pragma once

#include "hukommelse.h"
#include "brugerUI.h"

#include <string>
#include <iostream>


int main()
{
	brugerUI UIObj;
	hukommelse memObj;

	int menu;
	if(menu == 0)   // vis prelogin menu. Login og vis status kan vælges
		{
			menu = UIObj.preLogin();
		}

		if(menu == 1)	// login menu. bruger skal login på DE2 eller tryk ESC
		{
			menu = UIObj.login();
		}

		if(menu == 2)	// main menu. 
		{
			menu = UIObj.mainMenu();
		}

		if(menu == 3) // vis status menu
		{
			menu = UIObj.showStatus();
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