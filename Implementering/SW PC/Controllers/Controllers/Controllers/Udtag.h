
#pragma once

#include "brugerUI.h"
#include "hukommelse.h"

class udtag
{
public:
	udtag(hukommelse *, brugerUI *);
	void addRemoveUdtag();

private:
	hukommelse * huPtr;
	brugerUI * uiPtr;
};