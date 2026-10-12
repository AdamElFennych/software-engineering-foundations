#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify function calls.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the range.
//   - To:   The upper bound of the range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number using the modulus operator and shift it by 'From'.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An array (with maximum capacity of 100 elements) to store the random numbers.
//   - arrLength: A reference variable to hold the number of elements the user wants to fill.
// The function prompts the user to specify the number of elements, then fills each element with a random number.
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
//   - arr: The array to be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: SumArray
// Purpose: Calculates the sum of all elements in the array.
// Parameters:
//   - arr: The array of integers.
//   - arrLength: The number of elements in the array.
// Returns: The sum of all the elements in the array.
int SumArray(int arr[100], int arrLength)
{
    int Sum = 0;  // Initialize sum to zero.

    // Loop through each element of the array and add it to Sum.
    for (int i = 0; i < arrLength; i++)
    {
        Sum += arr[i];
    }

    return Sum;  // Return the calculated sum.
}

// Main function: Program entry point.
int main() {
    // Seed the random number generator with the current time to ensure a different sequence on each run.
    srand((unsigned)time(NULL));

    int arr[100];    // Declare an array with capacity for 100 integers.
    int arrLength;   // Variable to store the number of elements to be filled.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Display the array elements.
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Calculate and display the sum of all numbers in the array.
    cout << "\nSum of all number is : ";
    cout << SumArray(arr, arrLength) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}