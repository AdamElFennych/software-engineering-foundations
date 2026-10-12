#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to common functions.

// Function: RandomNumber
// Purpose: Generates a random integer between two specified values (inclusive).
// Parameters:
//    - From: The lower bound of the random range.
//    - To:   The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number in the range [From, To]:
    // rand() % (To - From + 1) produces a number between 0 and (To - From),
    // then adding From shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with a specified number of random integers between 1 and 100.
// Parameters:
//    - arr: An integer array (capacity: 100) to store the random numbers.
//    - arrLength: A reference variable that will hold the number of elements entered by the user.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements to fill in the array.

    // Loop through the array indices from 0 to arrLength - 1,
    // and fill each element with a random number between 1 and 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//    - arr: The array to print.
//    - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through each element of the array and output it followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  // Print a newline after printing all the elements.
}

// Function: MaxNumberInArray
// Purpose: Finds and returns the maximum number in the given array.
// Parameters:
//    - arr: The array of integers.
//    - arrLength: The number of elements in the array.
// Returns: The maximum value found in the array.
int MaxNumberInArray(int arr[100], int arrLength)
{
    int Max = 0;  // Initialize Max to 0. (Note: This assumes array elements are positive.)

    // Loop through the array to find the maximum element.
    for (int i = 0; i < arrLength; i++)
    {
        // If the current element is greater than the current Max, update Max.
        if (arr[i] > Max)
        {
            Max = arr[i];
        }
    }
    return Max;  // Return the maximum number found.
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that each run produces different random numbers.
    srand((unsigned)time(NULL));

    int arr[100];    // Declare an array to hold up to 100 integers.
    int arrLength;   // Variable to store the number of elements in the array.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Display the filled array.
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Find and display the maximum number in the array.
    cout << "\nMax Number is : ";
    cout << MaxNumberInArray(arr, arrLength) << endl;

    return 0;  // Return 0 to indicate successful execution.
}