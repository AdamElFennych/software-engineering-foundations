
#include <iostream>
using namespace std;

int main()
{
	int number = 0;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cout << "enter the number " << i+1 << endl;
		cin >> number;
		if (number > 50 )
		{
			cout << "the number is greater than 50 and wont be calculated\n";
			continue;
		}
		sum += number;
	}
	cout << "the sum is : " << sum;
}
