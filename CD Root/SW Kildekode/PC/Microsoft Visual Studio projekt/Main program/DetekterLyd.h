
#pragma once

//#include "clickATellIF.h"
#include "hukommelse.h"

class detekterLyd
{
public:
	detekterLyd(/*clickATellIF *,*/ hukommelse *);
	void lydDetekteret();

private:
	//clickATellIF * smsPtr;
	hukommelse * huPtr;
};