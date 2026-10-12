#include <iostream>
using namespace std;
int main()
{
    int arr[10] = { 10,20,44,55,33,22,99,88,99 ,100 };
	int search = 20;

	for (int i = 0; i <= 9; i++)
	{	cout << "we are at iteration " << i + 1 << endl;
		if (arr[i] == search)
		{
			cout << endl << search << " found at position " << i << endl;
			break;
		}
	}
}
