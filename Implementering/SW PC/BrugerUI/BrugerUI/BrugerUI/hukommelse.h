
#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>


using namespace std;

class hukommelse
{
public:
	hukommelse();				// læser den gemte hukommelse og initialisere members.
	~hukommelse();
	vector<string> getEnheder() const;	// funktion der returnere en vector med alle enheder og telefonnr.
	void saveLogin(bool);				// funktion til at gemme login.
	void saveStatus(bool, int adresse);	// funktion til at ændre status på en pågældende enhed
	int getNumber() const;				// funktion til at hente det gemte telefonnr.
	bool saveNumber(int);				// funktion til at overwrite gemte telefonnr.
	bool saveAdresse(string, string);	// funktion til at tilføje ny enheder til vectoren memory_
	bool removeAdresse(int);			// funktion der fjerner enhed i vectoren memory_
	void print() const;					// funktion til at printe .txt filen. primært til test

	fstream& GotoLine(fstream& file, int num)	// funktion til at gå til linje 1 i txt filen og skriv der. bruges når telefonnr skal overwrites.
	{
		file.seekg(ios::beg);
		for(int i=0; i < num - 1; ++i)
		{
			file.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		return file;
	}

private:
	int telefonNummer_;
	bool statusLogin_;
	vector<string> memory_;

};

inline const char * const BoolToString(bool b)
{
  return b ? "true" : "false";
}

