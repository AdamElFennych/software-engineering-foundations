#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumber
// Purpose: Prompts the user to enter a number and reads it from input.
// Returns: The entered number as an integer.
int ReadNumber()
{
    int Number;  // Variable to store the user's input.

    // Prompt the user to enter a number.
    cout << "Please enter a number? " << endl;
    cin >> Number;

    return Number;  // Return the entered number.
}

// Function: PowerOf2_3_4
// Purpose: Computes and prints the square, cube, and fourth power of a given number.
// Parameter:
//   - Number: The integer whose powers will be calculated.
// Returns: None (prints the results).
void PowerOf2_3_4(int Number)
{
    int a, b, c;  // Variables to store the computed powers.

    // Compute square, cube, and fourth power of the given number.
    a = Number * Number;                  // Square of the number.
    b = Number * Number * Number;          // Cube of the number.
    c = Number * Number * Number * Number; // Fourth power of the number.

    // Print the results.
    cout << a << " " << b << " " << c << endl;
}

// Main function: Program entry point.
int main()
{
    // Read a number from the user and compute its powers.
    PowerOf2_3_4(ReadNumber());

    return 0;  // Return 0 to indicate successful execution.
}