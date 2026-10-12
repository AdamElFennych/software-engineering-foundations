#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace MyLib
{
	string ReadString()
	{
		string S1;
		cout << "Please Enter Your String?\n";
		getline(cin, S1);
		return S1;
	}
	int ReadNumber()
	{
		int Number = 0;
		cout << "Pease enter a number?" << endl;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one" << endl;
			cin >> Number;
		}
		return Number;
	}
	int RandomNumber(int From, int To)
	{
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}
	string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}
	string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	char ReadChar()
	{
		char Ch1;
		cout << "Please Enter a Character?\n";
		cin >> Ch1;
		return Ch1;
	}
	char InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}
	string InvertAllStringLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
}