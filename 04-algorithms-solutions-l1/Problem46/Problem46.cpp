#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: PrintLettersAtoZ
// Purpose: Prints uppercase letters from 'A' to 'Z' using their ASCII values.
// Returns: None (prints the result to the console).
void PrintLettersAtoZ()
{
    // Loop through ASCII values of uppercase letters (65 to 90).
    for (int i = 65; i <= 90; i++)
    {
        cout << char(i) << endl;  // Convert the ASCII value to a character and print it.
    }
}

// Main function: Program entry point.
int main()
{
    // Call the function to print uppercase letters from 'A' to 'Z'.
    PrintLettersAtoZ();

    return 0;  // Return 0 to indicate successful execution.
}