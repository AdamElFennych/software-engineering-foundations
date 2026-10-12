#include <iostream>   // Include the iostream library for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to common functions.

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the random range.
//   - To:   The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number using rand() and the modulus operator.
    // The expression "rand() % (To - From + 1)" gives a value between 0 and (To - From),
    // then adding From shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An integer array (capacity of 100) to store the random numbers.
//   - arrLength: A reference variable that holds the number of elements to fill.
// The function prompts the user for the number of elements and fills the array accordingly.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Loop through indices from 0 to arrLength - 1 and fill each element with a random number.
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

// Function: CopyArray
// Purpose: Copies the elements from the source array to the destination array.
// Parameters:
//   - arrSource: The array from which to copy elements.
//   - arrDestination: The array into which elements will be copied.
//   - arrLength: The number of elements to copy.
void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    // Loop through each element up to arrLength and copy from source to destination.
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that each run produces a different sequence of random numbers.
    srand((unsigned)time(NULL));

    int arr[100];    // Declare an array with capacity for 100 integers.
    int arrLength;   // Variable to store the number of elements to fill in the array.

    // Fill the first array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    int arr2[100];   // Declare a second array to hold the copied elements.

    // Copy the elements from the first array to the second array.
    CopyArray(arr, arr2, arrLength);

    // Display the contents of the first array.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Display the contents of the second array to confirm the copy.
    cout << "\nArray 2 elements after copy:\n";
    PrintArray(arr2, arrLength);

    return 0;  // Return 0 to indicate successful program execution.
}