
#pragma once

//#include "RS232IF.h"
#include "brugerUI.h"
#include "hukommelse.h"

class aktiver
{
public:
	aktiver(/*RS232IF *,*/ hukommelse *, brugerUI *);
	void aktiverEnhed();

private:
	//RS232IF * rsPtr;
	hukommelse * huPtr;
	brugerUI * uiPtr;
};