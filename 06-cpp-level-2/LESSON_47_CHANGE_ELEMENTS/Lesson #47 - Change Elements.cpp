#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>vNum{ 1,2,3,4,5 };
	cout << "Initial Vector: ";
	for (const int& i : vNum)
	{
		cout << i << " ";
	}
	cout << "\n\nUpdate Vector: ";
	for (int& i : vNum)
	{
		i = 20;
		cout << i << " ";
	}
	vNum[1] = 40;
	vNum.at(2) = 80;
	vNum.at(4) = 90;
	cout << "\n\nUpdate Vector: ";
	for (const int& i : vNum)
	{
		cout << i << " ";
	}
	return 0;
}