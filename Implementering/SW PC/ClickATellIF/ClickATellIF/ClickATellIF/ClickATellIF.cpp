
#pragma once

#include"ClickATellIF.h"
#include<windows.h>
#include<ShellApi.h>

clickATellIF::clickATellIF()
{}

void clickATellIF::sendSMS(int phoneNumber)
{
	string url;

	url.append("http://api.clickatell.com/http/sendmsg?user=jeppestaerk&password=Kodeord23&api_id=3453974&text=BABY%20ALARM%20sendt%20fra%20CSS%20system&msg_type=SMS_FLASH&to=45");
	url.append(static_cast<ostringstream*>(&(ostringstream() << phoneNumber))->str());

	ShellExecuteA(NULL, "open", "iexplore.exe", url.c_str(), NULL, 2);
}