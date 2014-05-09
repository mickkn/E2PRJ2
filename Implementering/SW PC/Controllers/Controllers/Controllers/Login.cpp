
#include "login.h"

login::login(RS232IF * rs)
{
	rsPtr = rs;
}

bool login::loginValid()
{
	return rsPtr->loginValid();
}