#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number.
//          Repeats the prompt until the user inputs a number greater than zero.
// Parameter: Message - a string containing the prompt message.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl;  // Display the prompt message.
        cin >> Number;            // Read the number from the user.
    } while (Number <= 0);        // Continue prompting if the number is not positive.

    return Number;  // Return the validated positive number.
}

// Function: CountDigitFrequency
// Purpose: Counts how many times a specific digit appears in the given number.
//          The function extracts each digit from the number and increments the count when a match is found.
// Parameters:
//    DigitToCheck - the digit (as a short) to look for.
//    Number - the main number in which the frequency of the digit is to be counted.
// Returns: The frequency (count) of the specified digit in the number.
int CountDigitFrequency(short DigitToCheck, int Number)
{
    int Freq = 0;       // Initialize frequency counter to zero.
    int Remainder = 0;  // Variable to store the digit extracted from the number.

    // Process each digit until the number becomes 0.
    while (Number > 0)
    {
        Remainder = Number % 10;  // Extract the last digit from the number.
        Number = Number / 10;     // Remove the last digit from the number.

        // If the extracted digit matches the digit we're checking, increment the frequency counter.
        if (DigitToCheck == Remainder)
        {
            Freq++;
        }
    }
    return Freq;  // Return the total count of the specified digit.
}

// Function: PrintAllDigitsFrequencey
// Purpose: Prints the frequency of each digit (0-9) present in the given number.
// Parameter: Number - the number for which digit frequencies are to be printed.
void PrintAllDigitsFrequencey(int Number)
{
    cout << endl;  // Print an empty line for formatting.

    // Loop through all digits from 0 to 9.
    for (int i = 0; i < 10; i++)
    {
        short DigitFrequency = 0;                         // Variable to hold frequency for the current digit.
        DigitFrequency = CountDigitFrequency(i, Number);    // Get the frequency of digit 'i' in the number.

        // Only print the result if the digit appears at least once.
        if (DigitFrequency > 0)
        {
            cout << "Digit " << i << " Frequencey is "  // Print the digit and its frequency.
                << DigitFrequency << " Time(s).\n";
        }
    }
}

// Main function: Program entry point.
int main()
{
    // Prompt the user to enter a number.
    int Number = ReadPositiveNumber("Please enter the a number?");
    // Print the frequency of each digit (0-9) in the entered number.
    PrintAllDigitsFrequencey(Number);

    return 0;  // Return 0 to indicate successful execution.
}