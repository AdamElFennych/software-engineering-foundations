#include <iostream>
#include <iomanip>

using namespace std;

// Function to generate a random number
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

// Function to fill the matrix with random numbers
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

// Function to print the matrix
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

// Function to calculate the sum of a specific row
// This function performs logic only (Calculation) and does not print
int RowSum(int arr[3][3], short RowNumber, short Cols)
{
	int Sum = 0;
	for (short j = 0; j <= Cols - 1; j++)
	{
		Sum += arr[RowNumber][j];
	}
	return Sum;
}

// Function to print the sum of each row
// This function handles the UI (Printing)
void PrintEachRowSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe following are the sum of each row in the matrix:\n";
	for (short i = 0; i < Rows; i++)
	{
		// Call the calculation function inside the print statement
		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
	}
}

int main()
{
	// Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	int arr[3][3];

	FillMatrixWithRandomNumbers(arr, 3, 3);

	cout << "\n The following is a 3x3 random matrix:\n";
	PrintMatrix(arr, 3, 3);

	// Call the function to print row sums
	PrintEachRowSum(arr, 3, 3);

	system("pause>0");
	return 0;
}