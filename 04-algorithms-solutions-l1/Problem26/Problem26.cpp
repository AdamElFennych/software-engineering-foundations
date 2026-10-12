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

// Function: PrintRangeFrom1toN_UsingWhile
// Purpose: Prints numbers from 1 to N using a while loop.
// Parameter: N - the upper limit of the range.
// Returns: None (prints the numbers).
void PrintRangeFrom1toN_UsingWhile(int N)
{
    int Counter = 0;  // Initialize the counter.

    // Print the header message.
    cout << "Range printed using While Statement:\n";

    // Use a while loop to print numbers from 1 to N.
    while (Counter < N)
    {
        Counter++;  // Increment the counter.
        cout << Counter << endl;  // Print the current number.
    }
}

// Function: PrintRangeFrom1toN_UsingDoWhile
// Purpose: Prints numbers from 1 to N using a do-while loop.
// Parameter: N - the upper limit of the range.
// Returns: None (prints the numbers).
void PrintRangeFrom1toN_UsingDoWhile(int N)
{
    int Counter = 0;  // Initialize the counter.

    // Print the header message.
    cout << "Range printed using Do..While Statement:\n";

    // Use a do-while loop to print numbers from 1 to N.
    do
    {
        Counter++;  // Increment the counter.
        cout << Counter << endl;  // Print the current number.
    } while (Counter < N);  // Loop until the counter reaches N.
}

// Function: PrintRangeFrom1toN_UsingFor
// Purpose: Prints numbers from 1 to N using a for loop.
// Parameter: N - the upper limit of the range.
// Returns: None (prints the numbers).
void PrintRangeFrom1toN_UsingFor(int N)
{
    // Print the header message.
    cout << "Range printed using For Statement:\n";

    // Use a for loop to print numbers from 1 to N.
    for (int Counter = 1; Counter <= N; Counter++)
    {
        cout << Counter << endl;  // Print the current number.
    }
}

// Main function: Program entry point.
int main()
{
    // Read the upper limit N from the user.
    int N = ReadNumber();

    // Print numbers from 1 to N using different loop types.
    PrintRangeFrom1toN_UsingWhile(N);
    PrintRangeFrom1toN_UsingDoWhile(N);
    PrintRangeFrom1toN_UsingFor(N);

    return 0;  // Return 0 to indicate successful execution.
}