#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to handle message prompts.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user to enter a positive number and ensures the input is non-negative.
// Parameter:
//   - Message: A string containing the prompt message to be displayed.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number;  // Variable to store the user's input.

    // Keep prompting the user until a positive number (>= 0) is entered.
    do
    {
        cout << Message << endl;  // Display the provided message.
        cin >> Number;  // Read the number entered by the user.

    } while (Number < 0);  // Repeat if the number is negative.

    return Number;  // Return the validated positive number.
}

// Function: Factorial
// Purpose: Computes the factorial of a given number N.
// Parameter:
//   - N: An integer for which the factorial is to be calculated.
// Returns: The computed factorial of N.
int Factorial(int N)
{
    int F = 1;  // Initialize the factorial result to 1.

    // Use a for loop to multiply the numbers from N down to 1.
    for (int Counter = N; Counter >= 1; Counter--)
    {
        F = F * Counter;  // Multiply the current value of F by Counter.
    }

    return F;  // Return the computed factorial value.
}

// Main function: Program entry point.
int main()
{
    // Prompt the user for a positive number, compute its factorial, and display the result.
    cout << Factorial(ReadPositiveNumber("Please enter a positive number???")) << endl;

    return 0;  // Return 0 to indicate successful execution.
}