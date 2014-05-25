
#pragma once

#include "RS232IF.h"
#include "brugerUI.h"

class login
{
public:
	login(RS232IF *, brugerUI *);
	bool loginValid();
private:
	RS232IF * rsPtr;
	brugerUI * uiPtr;
};