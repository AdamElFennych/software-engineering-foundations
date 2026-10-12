#pragma once

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace MyStringLib
{
enum enWhatToCount
{
    SmallLetters = 0,
    CapitalLetters = 1,
    All = 3
};
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

void PrintFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;
    cout << "\nFirst letters of this string: \n";
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            cout << S1[i] << endl;
        }
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
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
    for (short i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
            Counter++;
    }
    return Counter;
}

short CountSmallLetters(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
            Counter++;
    }
    return Counter;
}

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
{
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
            Counter++;
        if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
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

short CountVowels(string S1)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            Counter++;
    }
    return Counter;
}

void PrintVowels(string S1)
{
    cout << "\nVowels in string are: ";
    for (short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            cout << S1[i] << "    ";
    }
    cout << endl;
}

void PrintEachWordInString(string S1)
{
    string delim = " ";
    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        cout << S1 << endl;
    }
}

short CountWords(string S1)
{
    string delim = " ";
    short Counter = 0;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            Counter++;
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        Counter++;
    }
    return Counter;
}

vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
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

string JoinString(string arrString[], short Length, string Delim)
{
    string S1 = "";
    for (short i = 0; i < Length; i++)
    {
        S1 = S1 + arrString[i] + Delim;
    }
    return S1.substr(0, S1.length() - Delim.length());
}

string ReverseWordsInString(string S1)
{
    vector<string> vString;
    string S2 = "";
    vString = SplitString(S1, " ");
    vector<string>::iterator iter = vString.end();
    while (iter != vString.begin())
    {
        --iter;
        S2 += *iter + " ";
    }
    return S2.substr(0, S2.length() - 1);
}

string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
    vector<string> vString = SplitString(S1, " ");
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

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

string RemovePunctuationsFromString(string S1)
{
    string S2 = "";
    for (short i = 0; i < S1.length(); i++)
    {
        if (!ispunct(S1[i]))
        {
            S2 += S1[i];
        }
    }
    return S2;
}
} // namespace MyStringLib
