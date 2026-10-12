#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the random range.
//   - To:   The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number using the modulus operator:
    // rand() % (To - From + 1) produces a value between 0 and (To - From),
    // then adding From shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An integer array (capacity: 100) to store random numbers.
//   - arrLength: A reference variable that will store the number of elements to fill.
// The function prompts the user to specify the number of elements, then fills each element with a random number.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Loop through the array indices from 0 to arrLength - 1,
    // and assign a random number (between 1 and 100) to each element.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   - arr: The array to print.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and output each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  // Print a newline after printing all elements.
}

// Function: SumArray
// Purpose: Computes the sum of all elements in the array.
// Parameters:
//   - arr: The array of integers.
//   - arrLength: The number of elements in the array.
// Returns: The total sum of the array elements.
int SumArray(int arr[100], int arrLength)
{
    int Sum = 0;  // Initialize sum to zero.

    // Iterate through each element in the array and add it to Sum.
    for (int i = 0; i < arrLength; i++)
    {
        Sum += arr[i];
    }

    return Sum;  // Return the computed sum.
}

// Function: ArrayAverage
// Purpose: Calculates the average of all elements in the array.
// Parameters:
//   - arr: The array of integers.
//   - arrLength: The number of elements in the array.
// Returns: The average as a float, computed by dividing the sum by the number of elements.
float ArrayAverage(int arr[100], int arrLength)
{
    // Compute the average by casting the sum to float to ensure floating-point division.
    return (float)SumArray(arr, arrLength) / arrLength;
}

// Main function: Program entry point.
int main() {
    // Seed the random number generator with the current time.
    // This ensures a different sequence of random numbers on each run.
    srand((unsigned)time(NULL));

    int arr[100];    // Declare an array with a maximum capacity of 100 integers.
    int arrLength;   // Variable to store the number of elements the user wants to fill.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the filled array.
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Compute and display the average of the array elements.
    cout << "\nAverage of all number is : ";
    cout << ArrayAverage(arr, arrLength) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}