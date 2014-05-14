
#include "detekterLyd.h"

detekterLyd::detekterLyd(/*clickATellIF * click,*/ hukommelse * hu)
{
	//smsPtr = click;
	huPtr = hu;
}

void detekterLyd::lydDetekteret()
{
	int nummer = huPtr->getNumber;

	//smsPtr->sendSMS(nummer);

}