#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use round() for calculations.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Enum: enPrimNotPrime
// Purpose: Represents whether a number is Prime (1) or Not Prime (2).
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number and ensures valid input.
// Parameter:
//   - Message: A string containing the prompt message to be displayed.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.

    // Keep prompting the user until a positive number (> 0) is entered.
    do
    {
        cout << Message << endl;  // Display the provided message.
        cin >> Number;  // Read the number entered by the user.
    } while (Number <= 0);  // Repeat if the number is non-positive.

    return Number;  // Return the validated positive number.
}

// Function: CheckPrime
// Purpose: Determines if a given number is prime or not.
// Parameter:
//   - Number: The integer to check for primality.
// Returns: enPrimNotPrime::Prime if the number is prime, otherwise enPrimNotPrime::NotPrime.
enPrimNotPrime CheckPrime(int Number)
{
    // A prime number must be greater than 1.
    if (Number < 2)
        return enPrimNotPrime::NotPrime;

    // Find the middle point to reduce iterations.
    int M = round(Number / 2);

    // Loop from 2 to M to check for factors.
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)  // If Number is divisible, it's not prime.
            return enPrimNotPrime::NotPrime;
    }

    return enPrimNotPrime::Prime;  // If no factors are found, it's prime.
}

// Function: PrintNumberType
// Purpose: Prints whether a given number is prime or not based on the CheckPrime function.
// Parameter:
//   - Number: The integer whose primality is checked.
// Returns: None (prints the result).
void PrintNumberType(int Number)
{
    // Use a switch statement to determine the number type and print the result.
    switch (CheckPrime(Number))
    {
    case enPrimNotPrime::Prime:
        cout << "The number is Prime\n";
        break;
    case enPrimNotPrime::NotPrime:
        cout << "The number is Not Prime\n";
        break;
    }
}

// Main function: Program entry point.
int main()
{
    // Read a positive number from the user and check if it's prime.
    PrintNumberType(ReadPositiveNumber("Please enter a positive number?"));

    return 0;  // Return 0 to indicate successful execution.
}