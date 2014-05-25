
#pragma once

#include "brugerUI.h"
#include "hukommelse.h"

class redigerSmsBruger
{
public:
	redigerSmsBruger(hukommelse *, brugerUI *);
	void redigerSMS();

private:
	hukommelse * huPtr;
	brugerUI * uiPtr;
};