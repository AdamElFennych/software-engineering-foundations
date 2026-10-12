#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

// Problem #26
string LowerAllString(string S3)
{
	for (int i = 0; i < S3.length(); i++)
	{
		S3[i] = tolower(S3[i]);
	}
	return S3;
}

// Problem #37
vector<string> SplitString(string S9, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use fine() function to get the position of the delimiters
	while ((pos = S9.find(Delim)) != std::string::npos)
	{
		// Find the delimiter - space
		sWord = S9.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		// Delete from 0 to number of characters + delimiter
		// erase() until positon and move to next word
		S9.erase(0, pos + Delim.length());
	}
	// Print the last word of the text
	if (S9 != "")
	{
		// it print last word of the string
		vString.push_back(S9);
	}
	return vString;
}

// Problem #39
string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	// Delete the last Delim
	return S1.substr(0, S1.length() - Delim.length());
}

// Problem #43
string ReplaceWordInStringUsingSplit(string S13, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
	vector<string> vString = SplitString(S13, " ");
	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sRepalceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = sRepalceTo;
			}
		}
	}
	return JoinString(vString, " ");
}

int main()
{
	// Problem #43
	string S13 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string ReplaceTo = "USA";
	cout << "\nOriginal String\n" << S13;
	cout << "\n\nReplace with Match Case :";
	cout << "\n" << ReplaceWordInStringUsingSplit(S13, StringToReplace, ReplaceTo);
	cout << "\n\nReplace with don't Match Case :";
	cout << "\n" << ReplaceWordInStringUsingSplit(S13, StringToReplace, ReplaceTo, false);
	system("pause>0");
}