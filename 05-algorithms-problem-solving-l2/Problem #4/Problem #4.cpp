#include <iostream>   // Include the iostream library for input and output operations.
#include <string>     // Include the string library to work with std::string.
using namespace std;  // Use the standard namespace to simplify usage of standard library functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number.
//          The function repeatedly asks until the user enters a number greater than zero.
// Parameter: Message - a string that will be displayed to the user as a prompt.
// Returns: An integer representing the positive number input by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Initialize a variable to store the user's input.

    // Use a do-while loop to ensure that the prompt is shown at least once.
    do
    {
        cout << Message << endl; // Display the prompt message.
        cin >> Number;           // Read the number from user input.
    } while (Number <= 0);       // Repeat if the entered number is not positive.

    return Number;  // Return the valid positive number.
}

// Function: isPerfectNumber
// Purpose: Determines whether a given integer is a perfect number.
//          A perfect number is one that equals the sum of its proper divisors (excluding itself).
// Parameter: Number - the integer to be checked.
// Returns: A boolean value: true if Number is perfect, false otherwise.
bool isPerfectNumber(int Number)
{
    int Sum = 0;  // Initialize the sum of proper divisors.

    // Loop through all numbers from 1 to Number-1.
    // These numbers are potential proper divisors of Number.
    for (int i = 1; i < Number; i++)
    {
        // If 'i' divides Number without a remainder, it is a proper divisor.
        if (Number % i == 0)
            Sum += i;  // Add the divisor to the sum.
    }

    // A number is perfect if the sum of its proper divisors equals the number itself.
    return Number == Sum;
}

// Function: PrintPerfectNumbersFrom1ToN
// Purpose: Prints all perfect numbers between 1 and a given upper limit (inclusive).
// Parameter: Number - the upper limit for checking perfect numbers.
void PrintPerfectNumbersFrom1ToN(int Number)
{
    // Loop through each number from 1 to the given upper limit.
    for (int i = 1; i <= Number; i++)
    {
        // Check if the current number is a perfect number.
        if (isPerfectNumber(i))
        {
            // If it is perfect, output the number.
            cout << i << endl;
        }
    }
}

// Main function: Entry point of the program.
int main()
{
    // Call ReadPositiveNumber with a prompt message to obtain a positive number from the user.
    // Then pass that number to PrintPerfectNumbersFrom1ToN to print all perfect numbers within the range.
    PrintPerfectNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  // Return 0 to indicate successful execution.
}