/*
 * Main.cpp
 *
 * Created: 26-05-2014 15:06:42
 *  Author: jeppestaerk
 */ 


#include "X10IF.h"
#include "UC2Aktivere.h"
#include "UC3Deaktiver.h"
#include "AdresseIF.h"
#include "UdtagIF.h"

int main()
{
	AdresseIF AIFObj;
	UdtagIF UIFObj;
	UC2Aktiver UC2Obj(&AIFObj, &UIFObj);
	UC3Deaktiver UC3Obj(&AIFObj, &UIFObj);
	X10IFObj.setPointer(&UC2Obj, &UC3Obj);
		
	while(1)
	{}
}