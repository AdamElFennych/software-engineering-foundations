#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to use to_string() for formatted messages.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumber
// Purpose: Prompts the user with a custom message to enter a number and reads it from input.
// Parameter:
//   - Message: A string containing the prompt message to be displayed.
// Returns: A float representing the user's input number.
float ReadNumber(string Message)
{
    float Number = 0;  // Variable to store the user's input.

    // Display the provided message and prompt the user to enter a number.
    cout << Message << endl;
    cin >> Number;

    return Number;  // Return the entered number.
}

// Function: SumNumbers
// Purpose: Reads numbers from the user and sums them until the user enters -99 to stop.
// Returns: The total sum of entered numbers as a float.
float SumNumbers()
{
    int Sum = 0;       // Initialize the sum accumulator.
    int Number = 0;    // Variable to store user input.
    int Counter = 1;   // Counter to track the number of inputs.

    // Read the first number from the user.
    Number = ReadNumber("Please enter Number " + to_string(Counter));

    // Continue reading and summing numbers until the user enters -99.
    while (Number != -99)
    {
        Sum += Number;  // Add the number to the sum.
        Counter++;      // Increment the input counter.

        // Read the next number.
        Number = ReadNumber("Please enter Number " + to_string(Counter));
    };

    return Sum;  // Return the computed sum.
}

// Main function: Program entry point.
int main()
{
    // Compute the sum of entered numbers and display the result.
    cout << endl << "Result = " << SumNumbers() << endl;

    return 0;  // Return 0 to indicate successful execution.
}