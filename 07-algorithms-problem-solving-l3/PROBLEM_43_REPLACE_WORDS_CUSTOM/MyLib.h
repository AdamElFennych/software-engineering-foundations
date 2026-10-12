#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
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
	short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}
	bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}
	vector<string> SplitString(string S1, string Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable

		// use find() function to get the position of the delimiters
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}
	string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}
	string JoinString(vector<string> vString, string Delim)
	{
		string S1 = "";
		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}
	string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";
		vString = SplitString(S1, " ");
		// declare iterator
		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);
		// remove last space.
		return S2;
	}
}