#include <iostream>
using namespace std;

int main()
{
    int Mark = 15;
    string result;
	if (Mark >= 50)
	{
		result = "PASS";
	}
	else
	{
		result = "FAIL";
	}
	cout << result << endl;
	//using short hand if
	(Mark >= 50) ? cout << "PASS" : cout << "FAIL";

	return 0;
}

