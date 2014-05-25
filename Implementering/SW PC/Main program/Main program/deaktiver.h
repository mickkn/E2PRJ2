
#pragma once

#include "RS232IF.h"
#include "brugerUI.h"
#include "hukommelse.h"

class deaktiver
{
public:
	deaktiver(RS232IF *, hukommelse *, brugerUI *);
	void deaktiverEnhed();

private:
	RS232IF * rsPtr;
	hukommelse * huPtr;
	brugerUI * uiPtr;
};