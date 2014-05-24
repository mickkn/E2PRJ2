
#include<iostream>
#include<sstream>
#include<string>
#include<windows.h>
#include<ShellApi.h>
#include"ClickATellIF.h"

using namespace std;

void sendSMS(int phoneNumber)
{
	// std::ostringstream number;
	// number << phoneNumber;

	std::string Url;

	Url.append("http://api.clickatell.com/http/sendmsg?user=jeppestaerk&password=Kodeord23&api_id=3453974&text=BABY%20ALARM%20sendt%20fra%20CSS%20system&msg_type=SMS_FLASH&to=45");
	Url.append(static_cast<ostringstream*>(&(ostringstream() << phoneNumber))->str());

	ShellExecuteA(NULL, "open", "iexplore.exe", Url.c_str(), NULL, 2);
}