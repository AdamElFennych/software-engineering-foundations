#include <iostream>   // Include the iostream library for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to common functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number.
//          It repeatedly asks until the user inputs a number greater than zero.
// Parameter: Message - a string containing the prompt to display.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl; // Display the prompt message.
        cin >> Number;           // Read the number entered by the user.
    } while (Number <= 0);       // Continue prompting if the number is not positive.

    return Number;  // Return the validated positive number.
}

// Function: ReadArray
// Purpose: Reads an array of integers from the user.
//          First, it asks for the number of elements, then it reads each element.
// Parameters:
//   - arr: An integer array (with a maximum capacity of 100 elements) to store user inputs.
//   - arrLength: A reference variable to hold the number of elements entered by the user.
void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the total number of elements the user wishes to input.

    cout << "\nEnter array elements: \n";
    // Loop from 0 to arrLength - 1 to read each array element.
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";  // Display a prompt for each element (using 1-based indexing for clarity).
        cin >> arr[i];                           // Read the current element into the array.
    }
    cout << endl;  // Print an extra newline for formatting.
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

// Function: TimesRepeated
// Purpose: Counts how many times a specified number appears in the array.
// Parameters:
//   - Number: The number to search for in the array.
//   - arr: The array in which to count occurrences.
//   - arrLength: The number of elements in the array.
// Returns: The count of occurrences of the specified number in the array.
int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int count = 0;  // Initialize a counter to zero.
    // Loop through the array indices from 0 to arrLength - 1.
    for (int i = 0; i <= arrLength - 1; i++)
    {
        if (Number == arr[i])  // If the current element equals the number we're checking,
        {
            count++;  // Increment the counter.
        }
    }
    return count;  // Return the total count.
}

// Main function: Entry point of the program.
int main() {

    int arr[100];      // Declare an array to hold up to 100 integers.
    int arrLength;     // Variable to store the number of elements in the array.
    int NumberToCheck; // The number whose frequency will be checked in the array.

    // Read array elements from the user.
    ReadArray(arr, arrLength);

    // Prompt the user to enter the number for which frequency is to be checked.
    NumberToCheck = ReadPositiveNumber("Enter the number you want to check: ");

    // Display the original array.
    cout << "\nOriginal array: ";
    PrintArray(arr, arrLength);

    // Display the frequency count for the specified number.
    cout << "\nNumber " << NumberToCheck;
    cout << " is repeated ";
    cout << TimesRepeated(NumberToCheck, arr, arrLength) << " time(s)\n";

    return 0;  // Return 0 to indicate successful program execution.
}