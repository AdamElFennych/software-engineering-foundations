#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <ctime>

using namespace std;

int RandomNumber(int From, int To)
{
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
			//arr[i][j] = RandomNumber(1, 100);
			arr[i][j] = RandomNumber(1, 10);
		}
	}
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			//cout << setw(3) << arr[i][j] << " ";
			printf(" %0*d ", 2, arr[i][j]);
		}
		cout << "\n";
	}
}
// Problem #12
bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	cout << "\n Matrix 1 :\n";
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n Matrix 2 :\n";
	PrintMatrix(Matrix2, 3, 3);

	if (AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		cout << "\n YES : both Matrices are Typical.";
	else
		cout << "\n No : Matrices are NOT Typical";

	system("pause>0");
	return 0;
}