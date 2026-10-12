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

// Function: PrintRangeFromNto1_UsingWhile
// Purpose: Prints numbers from N down to 1 using a while loop.
// Parameter: N - the starting number of the range.
// Returns: None (prints the numbers).
void PrintRangeFromNto1_UsingWhile(int N)
{
    int Counter = N + 1;  // Initialize the counter one step above N.

    // Print the header message.
    cout << "Range printed using While Statement:\n";

    // Use a while loop to print numbers from N to 1.
    while (Counter > 1)
    {
        Counter--;  // Decrement the counter.
        cout << Counter << endl;  // Print the current number.
    }
}

// Function: PrintRangeFromNto1_UsingDoWhile
// Purpose: Prints numbers from N down to 1 using a do-while loop.
// Parameter: N - the starting number of the range.
// Returns: None (prints the numbers).
void PrintRangeFromNto1_UsingDoWhile(int N)
{
    int Counter = N + 1;  // Initialize the counter one step above N.

    // Print the header message.
    cout << "Range printed using Do..While Statement:\n";

    // Use a do-while loop to print numbers from N to 1.
    do
    {
        Counter--;  // Decrement the counter.
        cout << Counter << endl;  // Print the current number.

    } while (Counter > 1);  // Loop until Counter reaches 1.
}

// Function: PrintRangeFromNto1_UsingFor
// Purpose: Prints numbers from N down to 1 using a for loop.
// Parameter: N - the starting number of the range.
// Returns: None (prints the numbers).
void PrintRangeFromNto1_UsingFor(int N)
{
    // Print the header message.
    cout << "Range printed using For Statement:\n";

    // Use a for loop to print numbers from N to 1.
    for (int Counter = N; Counter >= 1; Counter--)
    {
        cout << Counter << endl;  // Print the current number.
    }
}

// Main function: Program entry point.
int main()
{
    // Read the starting number N from the user.
    int N = ReadNumber();

    // Print numbers from N down to 1 using different loop types.
    PrintRangeFromNto1_UsingWhile(N);
    PrintRangeFromNto1_UsingDoWhile(N);
    PrintRangeFromNto1_UsingFor(N);

    return 0;  // Return 0 to indicate successful execution.
}