
#pragma once

#include <string>
#include <fstream>
#include <iostream>




using namespace std;


class hukommelse
{
public:
	hukommelse();
	~hukommelse();
	void WriteString(ofstream& ,const string& );
	string ReadString(ifstream& );

private:


};