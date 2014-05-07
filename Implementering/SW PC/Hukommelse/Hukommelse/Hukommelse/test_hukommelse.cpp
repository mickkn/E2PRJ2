
#pragma once

#include "hukommelse.h"
int main()
{
bool tester, numtester;
hukommelse testObj;

testObj.removeAdresse(1);
testObj.removeAdresse(1);
testObj.removeAdresse(1);

/*numtester = testObj.saveNumber(30227090);

if(numtester == 1)
{
	cout << "*****************" << endl << "det nye nummer blev gemt" << endl << "*****************" << endl << endl;
}
else
	cout << "*****************" << endl << "det nye nummer blev IKKE gemt" << endl << "*****************" << endl << endl;


int testNum = testObj.getNumber();
cout << endl << "*****************" << endl << testNum << " er nummeret" << endl << "*****************" << endl << endl;

// tilføjer nyt enhed

tester = testObj.saveAdresse("0100" , "hallway");
if(tester == 1)
{
	cout << "*****************" << endl << "den nye adresse blev gemt" << endl << "*****************" << endl << endl;
}
else
	cout << "*****************" << endl << "den nye adresse blev IKKE gemt" << endl << "*****************" << endl << endl;

// tilføjer nyt enhed

tester = testObj.saveAdresse("1000" , "roof");
if(tester == 1)
{
	cout << "*****************" << endl << "den nye adresse blev gemt" << endl << "*****************" << endl << endl;
}
else
	cout << "*****************" << endl << "den nye adresse blev IKKE gemt" << endl << "*****************" << endl << endl;

testObj.removeAdresse(1);
testObj.removeAdresse(3);
testObj.removeAdresse(2);
testObj.removeAdresse(1);


tester = testObj.saveAdresse("1001" , "last");
if(tester == 1)
{
	cout << "*****************" << endl << "den nye adresse blev gemt" << endl << "*****************" << endl << endl;
}
else
	cout << "*****************" << endl << "den nye adresse blev IKKE gemt" << endl << "*****************" << endl << endl;

testObj.saveStatus(true, 1);

tester = testObj.removeAdresse(1);
if(tester == 1)
{
	cout << "*****************" << endl << "den nye adresse blev gemt" << endl << "*****************" << endl << endl;
}
else
	cout << "*****************" << endl << "den nye adresse blev IKKE gemt" << endl << "*****************" << endl << endl;
tester = testObj.removeAdresse(1);
if(tester == 1)
{
	cout << "*****************" << endl << "den nye adresse blev gemt" << endl << "*****************" << endl << endl;
}
else
	cout << "*****************" << endl << "den nye adresse blev IKKE gemt" << endl << "*****************" << endl << endl;

testObj.print();*/

cout << "im done!" << endl;

while(1);

return 0;
}