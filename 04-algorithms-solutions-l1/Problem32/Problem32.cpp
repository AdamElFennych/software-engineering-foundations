#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumber
// Purpose: Prompts the user to enter a base number and reads it from input.
// Returns: The entered base number as an integer.
int ReadNumber()
{
    int Number;  // Variable to store the user's input.

    // Prompt the user to enter a number.
    cout << "Please enter a number? " << endl;
    cin >> Number;

    return Number;  // Return the entered number.
}

// Function: ReadPower
// Purpose: Prompts the user to enter an exponent value (power) and reads it from input.
// Returns: The entered power as an integer.
int ReadPower()
{
    int Number;  // Variable to store the power.

    // Prompt the user to enter the power.
    cout << "Please enter the power? " << endl;
    cin >> Number;

    return Number;  // Return the entered power.
}

// Function: PowerOfM
// Purpose: Computes the power of a given number using an iterative loop.
// Parameters:
//   - Number: The base number.
//   - M: The exponent to raise the base to.
// Returns: The computed power result.
int PowerOfM(int Number, int M)
{
    // Any number raised to the power of 0 is always 1.
    if (M == 0)
    {
        return 1;
    }

    int P = 1;  // Initialize the result.

    // Use a for loop to multiply the base number 'M' times.
    for (int i = 1; i <= M; i++)
    {
        P = P * Number;  // Multiply the current value of P by Number.
    }

    return P;  // Return the computed power.
}

// Main function: Program entry point.
int main()
{
    // Read a number (base) and its power (exponent) from the user.
    // Compute the result and display it.
    cout << endl << "Result = " << PowerOfM(ReadNumber(), ReadPower()) << endl;

    return 0;  // Return 0 to indicate successful execution.
}