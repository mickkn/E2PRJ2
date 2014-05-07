
#pragma once

#include "hukommelse.h"
#include <string>
#include <vector>



class brugerUI
{
public:
	brugerUI();
	void showMenu(int);
	void print() const;
	int preLogin() const;
	int login() const;
	int mainMenu() const;
	int aktiverMenu() const;
	int deaktiverMenu() const;
	int visStatusMenu() const;
	int redigerSmsMenu() const;
	int addRemoveMenu() const;

private:
	hukommelse objHuk;
};