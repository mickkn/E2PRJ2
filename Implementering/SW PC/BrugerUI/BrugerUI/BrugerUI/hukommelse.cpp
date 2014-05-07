
#include "hukommelse.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <limits>
#include <sstream> 

using namespace std;


hukommelse::hukommelse()
{
	fstream myFile("hukommelse.txt");
		
	string line;
	while (getline(myFile, line)) // kører txt filen igennem og indlæser linje for linje.
	{
		memory_.push_back(line);
	}

	telefonNummer_ = atoi(memory_[0].c_str()); // læser string på første plads i memory_ og convertere til int.

	statusLogin_ = false;

	myFile.close();

}

hukommelse::~hukommelse()
{

}

void hukommelse::saveLogin(bool login)   // overflødig? bliver ikke gemt til hukommelsen, hvorfor sku den? 
{
	statusLogin_ = login;
}

void hukommelse::saveStatus(bool status, int enhed)
{
	memory_[enhed+2] = BoolToString(status); // ændre status i vectoren.

	fstream myFile;
	
	myFile.open("hukommelse.txt", fstream::out | fstream::trunc);

		while(myFile)
		{
			for(int i = 0; i<memory_.size(); i++)
			{
				string text = memory_[i];
				myFile << text << "\n";
			}
			myFile.close();
		}
}

vector<string> hukommelse::getEnheder() const
{
	return memory_;
}

int hukommelse::getNumber() const
{
	return telefonNummer_;
}

bool hukommelse::saveNumber(int num)
{
	fstream myFile("hukommelse.txt");  // åben filen
	if(num == telefonNummer_)
	{
		return false;
	}
		
	if (myFile)					// if filen er åben
	{
		GotoLine(myFile, 1);	 // gå til og skriv i linje 1.
		int line1;
		myFile << num;

		telefonNummer_ = num;
		return true;
	}			
		
	else
		return false;

}

bool hukommelse::saveAdresse(string adresse, string navn)
{

		memory_.push_back(adresse);
		memory_.push_back(navn);
		memory_.push_back("false");

		fstream myFile;
		myFile.open("hukommelse.txt", fstream::out | fstream::trunc); 

		while(myFile)
		{
			for(int i = 0; i<memory_.size(); i++)
			{
				string text = memory_[i];
				//cout << text << endl;
				myFile << text << "\n";
			}
			myFile.close();
			return true;
		}

		return false;	
}

bool hukommelse::removeAdresse(int num)
{
	fstream myFile;
	myFile.open("hukommelse.txt", fstream::out | fstream::trunc); 

	int move = 0; 
	
	move = ((num*3) - 2); 
	if(myFile)
	{
		if(memory_.size() < move+1)
		{
			cout << "Adressen blev ikke fjernet" << endl;
			return false;
		}
	
		memory_.erase(memory_.begin() + (move), memory_.begin() + (move+3));	

		for(int i = 0; i<memory_.size(); i++)
			{
				string text = memory_[i];
				myFile << text << "\n";
			}
			myFile.close();
		return true;
	}
	return false;
}

void hukommelse::print() const
{
for(int i = 0; i<memory_.size(); i++)
	{
		string text = memory_[i];
		cout << text << endl;

	}
}





