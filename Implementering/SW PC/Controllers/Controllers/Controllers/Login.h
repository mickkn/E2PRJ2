
#pragma once

#include "RS232IF.h"

class login
{
public:
	login(RS232IF *);
	bool loginValid();
private:
	RS232IF * rsPtr;
};