#include <iostream>
#include <iomanip>
using namespace std;

// Problem #6
void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
	int Counter = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Counter++;
			arr[i][j] = Counter;
		}
	}
}

// Problem #1
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3];
	FillMatrixWithOrderedNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 Ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	system("pause>0");
}