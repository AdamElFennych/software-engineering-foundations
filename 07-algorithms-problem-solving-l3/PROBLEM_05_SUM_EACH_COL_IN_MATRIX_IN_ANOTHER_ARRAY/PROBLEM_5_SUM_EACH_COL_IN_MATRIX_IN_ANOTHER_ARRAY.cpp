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

// Problem #4
int ColSum(int arr[3][3], short Rows, short ColNumber)
{
	// Sum of column elements
	int Sum = 0;
	for (short i = 0; i <= Rows - 1; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}

// Problem #5
void SumMatrixColsInArray(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		arrSum[i] = ColSum(arr, Rows, i);
	}
}

void PrintColsSumArray(int arr[3], short Cols)
{
	cout << "\nThe following are the sum of each Col in the matrix: \n";
	for (short j = 0; j < Cols; j++)
	{
		cout << " Col " << j + 1 << " Sum = " << arr[j] << endl;
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

	// Problem #5
	SumMatrixColsInArray(arr, arrSum, 3, 3);
	PrintColsSumArray(arrSum, 3);

	system("pause>0");
	return 0;
}