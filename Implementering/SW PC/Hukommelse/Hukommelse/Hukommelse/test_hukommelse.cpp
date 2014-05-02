
#pragma once

#include "hukommelse.h"

int main()
{

	string test = "hej med dig";

	hukommelse testObj;

	testObj.WriteString("hukommelse.txt", test);

}