#include <iostream>
#include <string>
using namespace std;
enum enNumbertype { Odd = 1,Even = 2 };

int ReadNumber()
{
	int Num;

	cout << "Please enter the number ?" << endl;
	cin >> Num;
	return Num;
}

enNumbertype CheckNumbertype(int Num)
{
	int Result = Num % 2;
	if (Result == 0)
	{
		return enNumbertype::Even;
	}
	else
	{
		return enNumbertype::Odd;
	}
}

void PrintNumberType(enNumbertype Numbertype)
{
	if (Numbertype == enNumbertype::Even)
		cout << "\n the number is Even\n";
	else
	{
		cout << "\nthe number is Ood\n";
	}

}

int main()
{
	PrintNumberType(CheckNumbertype(ReadNumber()));
}
