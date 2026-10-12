#pragma once
#include <iostream>
using namespace std;
namespace MyLib
{
	void test()
	{
		cout << "this is a test func\n";
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
}