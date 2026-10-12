#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> vNumber = { 10,20,30,40,50 };
	cout << "Numbers Vector = ";
	for (int &i : vNumber)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}