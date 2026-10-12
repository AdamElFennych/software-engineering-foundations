#include <iostream>
using namespace std;
int main()
{
	// declare an int Pointer
	int* ptrX;
	// declare a float Pointer
	float* ptrY;
	// dynamically allocate memory
	// إنشاء متغير مؤقت في الذاكرة
	ptrX = new int;
	ptrY = new float;
	// assigning value to the memory
	// إضافة قيمة للمتغير المؤقت في الذاكرة
	*ptrX = 45;
	*ptrY = 58.35;
	cout << *ptrX << endl;
	cout << *ptrY << endl;
	// deallocate the memory
	// إزالة المتغير المؤقت من الذاكرة
	delete ptrX;
	delete ptrY;
	cout << endl;
}