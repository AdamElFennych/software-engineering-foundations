#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RandomNumber(int From, int To)
{
	// Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

// Problem #1
void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			arr[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << arr[i][j] << "     ";
		}
		cout << "\n";
	}
}

// Problem #2
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

// Problem #3
void SumMatrixRowsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	// Sum row elements into an Array
	for (short i = 0; i < Rows; i++)
	{
		arrSum[i] = RowSum(arr, i, Cols);
	}
}

void PrintRowsSumArray(int arr[3], short Rows)
{
	// Print Array elements
	cout << "\nThe following are the sum of each row in the matrix:\n";
	for (short i = 0; i < Rows; i++)
	{
		cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
	}
}

int main()
{
	// Different random number with each call
	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	// Problem #1
	// arr[3][3] Matrix, first for Rows, second for Cols
	// Variables
	int arr[3][3];
	int arrSum[3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	// Problem #3
	SumMatrixRowsInArray(arr, arrSum, 3, 3);
	PrintRowsSumArray(arrSum, 3);

	system("pause>0");
	return 0;
}