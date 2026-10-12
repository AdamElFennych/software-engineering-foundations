#include <iostream>
using namespace std;
int main()
{
	int arr[4] = { 10,20,30,40 };
	int* ptr;
	ptr = arr;
	for (int i = 0; i < 4; i++)
	{
		cout << "Adresse is  : ";
		cout << ptr + i << endl;
		cout << "Value is    : ";
		cout << *(ptr + i) << endl;
	}
	return 0;
}