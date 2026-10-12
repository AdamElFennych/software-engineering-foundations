#include <iostream>
#include <iomanip>
using namespace std;

// Problem #6 (Reused in Problem 7)
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

// Problem #1 (Reused in Problem 7)
void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			// Reserve three spaces to put numbers in
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

// Problem #7
void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrTransposed[i][j] = arr[j][i];
		}
	}
}

int main()
{
	// Different random number with each call
	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	// arr[3][3] is called Matrix, first [] for number of rows, second [] for number of columns
	int arr[3][3];
	int arrTransposed[3][3];

	// Problem #6
	FillMatrixWithOrderedNumbers(arr, 3, 3);
	cout << "\n The following is a 3x3 Ordered matrix:\n";
	PrintMatrix(arr, 3, 3);

	// Problem #7
	TransposeMatrix(arr, arrTransposed, 3, 3);
	cout << "\n The following is the Transposed matrix:\n";
	PrintMatrix(arrTransposed, 3, 3);

	system("pause>0");
}