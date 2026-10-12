#include <iostream>   // Include the iostream library for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumber
// Purpose: Prompts the user to enter a number to search for.
// Returns: The number entered by the user.
int ReadNumber()
{
    int Number;  // Variable to hold the user's input.
    cout << "\nPlease enter a number to search for?\n";
    cin >> Number;  // Read the input number.
    return Number;  // Return the entered number.
}

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the range.
//   - To:   The upper bound of the range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Use modulus to generate a random number within the desired range.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An array of integers with capacity 100.
//   - arrLength: A reference variable to store the number of elements to fill.
// The function first prompts the user for the number of elements, then fills the array.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the desired number of elements.

    // Loop through the array indices and assign each element a random number from 1 to 100.
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
    // Loop through each element of the array and print it.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: FindNumberPositionInArray
// Purpose: Searches for a given number in an array and returns its index if found,
//          or returns -1 if the number is not in the array.
// Parameters:
//   - Number: The number to search for.
//   - arr: The array in which to search.
//   - arrLength: The number of elements in the array.
// Returns: The index of the number if found; otherwise, -1.
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    // Loop through the array to check for the number.
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;  // Return the index if the number is found.
    }
    // If the loop completes, the number was not found.
    return -1;
}

// Function: IsNumberInArray
// Purpose: Determines if a given number exists in the array.
// Parameters:
//   - Number: The number to search for.
//   - arr: The array to search in.
//   - arrLength: The number of elements in the array.
// Returns: true if the number is found; false otherwise.
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    // Use FindNumberPositionInArray and check if the result is not -1.
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

// Main function: Program entry point.
int main()
{
    // Seed the random number generator with the current time.
    // This ensures different random sequences on each run.
    srand((unsigned)time(NULL));

    int arr[100];   // Declare an array to hold up to 100 integers.
    int arrLength;  // Variable to store the number of elements in the array.

    // Fill the array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Print the array's elements.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Prompt the user for a number to search for in the array.
    int Number = ReadNumber();
    cout << "\nNumber you are looking for is: " << Number << endl;

    // Check if the number is in the array and output the result.
    if (!IsNumberInArray(Number, arr, arrLength))
        cout << "No, The number is not found :-(\n";
    else
        cout << "Yes it is found :-)\n";

    return 0;  // Return 0 to indicate successful execution.
}