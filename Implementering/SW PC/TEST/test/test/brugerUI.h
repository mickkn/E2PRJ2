
#pragma once

#include "hukommelse.h"
#include <string>
#include <vector>



class brugerUI
{
public:
	brugerUI(hukommelse *);
	void print() const;
	void preLogin() const;
	void login() const;
	void mainMenu() const;
	int aktiverMenu() const;
	int deaktiverMenu() const;
	int visStatusMenu() const;
	int redigerSmsMenu() const;
	int addRemoveMenu() const;

private:
	hukommelse *huPtr;
};