#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to use std::string.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number.
//          It repeatedly asks until the user inputs a number greater than zero.
// Parameter: Message - a string containing the prompt to display.
// Returns: A positive integer provided by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl;  // Display the prompt message.
        cin >> Number;            // Read the number entered by the user.
    } while (Number <= 0);        // Continue prompting if the number is not positive.

    return Number;  // Return the validated positive number.
}

// Function: PrintNumberPattern
// Purpose: Prints a number pattern where each line prints the line number repeated as many times as the line number.
//          The pattern is fixed to 5 lines, regardless of the input parameter.
// Parameter: Number -  intended to be the basis for pattern size.
void PrintNumberPattern(int Number)
{
    cout << "\n";  // Print an empty line for formatting.

    // Outer loop: Iterates from 1 to 5, representing each line of the pattern.
    for (int i = 1; i <= Number; i++)
    {
        // Inner loop: Prints the current number 'i' exactly 'i' times.
        for (int j = 1; j <= i; j++)
        {
            cout << i;  // Print the number i without any separator.
        }
        cout << "\n";  // Move to the next line after printing the current line's pattern.
    }
}

// Main function: Program entry point.
int main()
{
    // Prompt the user to enter a positive number (though it is not used in the pattern)
    // and then call PrintNumberPattern to print the number pattern.
    PrintNumberPattern(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  // Return 0 to indicate successful program execution.
}