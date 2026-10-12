#include <iostream>   // Include iostream for input and output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the range.
//   - To:   The upper bound of the range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number using the modulus operator.
    // rand() % (To - From + 1) produces a value between 0 and (To - From),
    // then adding From shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An integer array (capacity 100) to store the random numbers.
//   - arrLength: A reference variable that will store the number of elements in the array.
// The function prompts the user for the number of elements and then fills the array accordingly.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Loop through the array indices from 0 to arrLength - 1
    // and assign each element a random number between 1 and 100.
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
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  // Print a newline after all elements are printed.
}

// Function: CopyArrayInReverseOrder
// Purpose: Copies the elements from the source array into the destination array in reverse order.
// Parameters:
//   - arrSource: The source array whose elements are to be reversed.
//   - arrDestination: The destination array where the reversed elements will be stored.
//   - arrLength: The number of elements in the source array.
void CopyArrayInReverseOrder(int arrSource[100], int arrDestination[100], int arrLength)
{
    // Loop through each element of the source array.
    // For each index i, copy the element at position (arrLength - 1 - i)
    // from the source array into the destination array at index i.
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[arrLength - 1 - i];
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures a different sequence of random numbers on each run.
    srand((unsigned)time(NULL));

    int arr[100];      // Declare an array to hold up to 100 integers.
    int arrLength;     // Variable to store the number of elements in the array.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];     // Declare a second array to hold the reversed elements.
    // Copy the elements of arr into arr2 in reverse order.
    CopyArrayInReverseOrder(arr, arr2, arrLength);

    // Print the original array.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Print the reversed array.
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arrLength);

    return 0;  // Return 0 to indicate successful program execution.
}