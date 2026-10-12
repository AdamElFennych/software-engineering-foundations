#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	void* ptr;
	float f1 = 5.2;
	int x = 50;

	ptr = &f1;
	cout << ptr << endl;

	cout << *(static_cast<float*>(ptr)) << endl;
	ptr = &x;
	cout << *(static_cast<int*>(ptr)) << endl;
	
}