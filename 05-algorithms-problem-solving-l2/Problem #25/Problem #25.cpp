#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify function calls.

// Function: RandomNumber
// Purpose: Generates a random integer between two specified values (inclusive).
// Parameters:
//   From - The lower bound of the random range.
//   To   - The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) and then add From
    // to shift the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an integer array with random numbers between 1 and 100.
// Parameters:
//   arr      - The array to be filled (maximum capacity of 100).
//   arrLength- A reference variable to store the number of elements to fill.
// The user is prompted to enter the number of elements.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Fill each element of the array with a random number between 1 and 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   arr      - The array to print.
//   arrLength- The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  // Print a newline after printing all elements.
}

// Function: MinNumberInArray
// Purpose: Finds and returns the minimum number in an array.
// Parameters:
//   arr      - The array of integers.
//   arrLength- The number of elements in the array.
// Returns: The smallest integer found in the array.
int MinNumberInArray(int arr[100], int arrLength)
{
    int Min = arr[0];  // Initialize Min with the first element of the array.

    // Loop through the array to find the smallest element.
    for (int i = 0; i < arrLength; i++)
    {
        // If the current element is less than the current minimum, update Min.
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
    }
    return Min;  // Return the minimum value found.
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that different random numbers are generated on each run.
    srand((unsigned)time(NULL));

    int arr[100];   // Declare an array to hold up to 100 integers.
    int arrLength;  // Variable to store the number of elements to be filled in the array.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the array elements.
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Find and print the minimum number in the array.
    cout << "\nMin Number is : ";
    cout << MinNumberInArray(arr, arrLength) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}