#include <iostream>
#include <string>
using namespace std;
struct stInfo 
{ 
	int Age;
	bool HasDrivingLicense;
};
stInfo ReadInfo()
{
	stInfo info;
	cout << "please enter your Age? \n";
	cin >> info.Age;
	cout << "Do you have driver Livense? \n";
	cin >> info.HasDrivingLicense;
	return info;
}
bool IsAccepted(stInfo Info)
{
	return (Info.Age > 21 && Info.HasDrivingLicense);
}
void PrintInfo(stInfo Info)
{
	if (IsAccepted(Info))
	{
		cout << "\n Hired \n";
	}
	else
	{
		cout << "\n Rejected \n";
	}
}
int main()
{
	PrintInfo(ReadInfo());
}