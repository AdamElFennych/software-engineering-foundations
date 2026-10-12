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
    // Generate a random number using the modulus operator.
    // rand() % (To - From + 1) produces a value between 0 and (To - From),
    // then adding From shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an integer array with random numbers between 1 and 100.
// Parameters:
//   - arr: An array of integers with capacity 100.
//   - arrLength: A reference variable that will store the number of elements in the array.
// The function prompts the user for the number of elements, then fills each element with a random number.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Loop through the array from index 0 to arrLength - 1
    // and assign each element a random number between 1 and 100.
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
    // Loop through each element of the array and print it.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: FindNumberPositionInArray
// Purpose: Searches for a given number in an array and returns its index if found,
//          or -1 if the number does not exist in the array.
// Parameters:
//   - Number: The number to search for.
//   - arr: The array in which to search.
//   - arrLength: The number of elements in the array.
// Returns: The index (0-based) of the number if found, or -1 if not found.
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    // Loop through each element in the array.
    for (int i = 0; i < arrLength; i++)
    {
        // Check if the current element equals the searched number.
        if (arr[i] == Number)
            return i; // Return the index immediately when the number is found.
    }

    // If the loop completes without finding the number, return -1.
    return -1;
}

// Function: ReadNumber
// Purpose: Prompts the user to enter a number to search for.
// Returns: The number entered by the user.
int ReadNumber()
{
    int Number;
    cout << "\nPlease enter a number to search for?\n";
    cin >> Number;
    return Number;
}

// Main function: Entry point of the program.
int main()
{
    // Seed the random number generator with the current time.
    // This ensures that a different sequence of random numbers is generated each run.
    srand((unsigned)time(NULL));

    int arr[100];   // Declare an array to hold up to 100 integers.
    int arrLength;  // Variable to store the number of elements in the array.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the array elements.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Prompt the user for a number to search for.
    int Number = ReadNumber();
    cout << "\nNumber you are looking for is: " << Number << endl;

    // Find the position of the number in the array.
    short NumberPosition = FindNumberPositionInArray(Number, arr, arrLength);

    // Output the result.
    if (NumberPosition == -1)
        cout << "The number is not found :-(\n";
    else
    {
        cout << "The number found at position: " << NumberPosition << endl;
        cout << "The number found its order  : " << NumberPosition + 1 << endl;
    }

    return 0;  // Return 0 to indicate successful execution.
}