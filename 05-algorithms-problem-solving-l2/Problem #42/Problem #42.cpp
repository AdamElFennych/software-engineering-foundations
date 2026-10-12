#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the random range.
//   - To: The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Calculate a random number using the modulus operator.
    // rand() % (To - From + 1) produces a value between 0 and (To - From).
    // Adding From shifts the value into the range [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArray
// Purpose: Fills an array with random numbers between 1 and 100.
// Parameters:
//   - arr: An integer array with a capacity of 100 elements.
//   - arrLength: A reference variable to store the number of elements in the array.
// The function first prompts the user for the number of elements, then fills the array.
void FillArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Loop from index 0 to arrLength - 1 and assign each element a random number between 1 and 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an array separated by spaces.
// Parameters:
//   - arr: The array to be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through each element in the array and print it followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: OddCount
// Purpose: Counts how many odd numbers exist in an array.
// Parameters:
//   - arr: The array to be examined.
//   - arrLength: The number of elements in the array.
// Returns: The count of odd numbers found in the array.
int OddCount(int arr[100], int arrLength)
{
    int Counter = 0;  // Initialize the odd number counter to 0.

    // Loop through each element in the array.
    for (int i = 0; i < arrLength; i++)
    {
        // Check if the element is odd (i.e., its remainder when divided by 2 is not 0).
        if (arr[i] % 2 != 0)
        {
            Counter++;  // Increment the counter if the element is odd.
        }
    }

    return Counter;  // Return the total count of odd numbers.
}

// Main function: Program entry point.
int main() {
    // Seed the random number generator with the current time.
    // This ensures a different sequence of random numbers for each run.
    srand((unsigned)time(NULL));

    int arr[100];     // Declare an array to hold up to 100 integers.
    int arrLength;    // Variable to store the number of elements in the array.

    // Fill the array with random numbers.
    FillArray(arr, arrLength);

    // Print the array elements.
    cout << "\nArray Elements: ";
    PrintArray(arr, arrLength);

    // Count and print the number of odd numbers in the array.
    cout << "\nOdd Numbers count is: ";
    cout << OddCount(arr, arrLength) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}