
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
	hukommelse();				// l�ser den gemte hukommelse og initialisere members.
	~hukommelse();
	vector<string> getEnheder() const;	// funktion der returnere en vector med alle enheder og telefonnr.
	void saveLogin(bool);				// funktion til at gemme login.
	void saveStatus(bool, int adresse);	// funktion til at �ndre status p� en p�g�ldende enhed
	int getNumber() const;				// funktion til at hente det gemte telefonnr.
	bool saveNumber(int);				// funktion til at overwrite gemte telefonnr.
	bool saveAdresse(string, string);	// funktion til at tilf�je ny enheder til vectoren memory_
	bool removeAdresse(int);			// funktion der fjerner enhed i vectoren memory_
	void print() const;					// funktion til at printe .txt filen. prim�rt til test

	fstream& GotoLine(fstream& file, int num)	// funktion til at g� til linje 1 i txt filen og skriv der. bruges n�r telefonnr skal overwrites.
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

