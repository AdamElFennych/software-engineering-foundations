#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Enum: enOddOrEven
// Purpose: Defines two possible classifications for numbers: Odd (1) and Even (2).
enum enOddOrEven { Odd = 1, Even = 2 };

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

// Function: CheckOddOrEven
// Purpose: Determines whether a given number is odd or even.
// Parameter: Number - The integer to check.
// Returns: enOddOrEven::Odd if the number is odd, otherwise enOddOrEven::Even.
enOddOrEven CheckOddOrEven(int Number)
{
    // If the number is not divisible by 2, return Odd; otherwise, return Even.
    if (Number % 2 != 0)
        return enOddOrEven::Odd;
    else
        return enOddOrEven::Even;
}

// Function: SumEvenNumbersFrom1toN_UsingWhile
// Purpose: Computes the sum of all even numbers from 1 to N using a while loop.
// Parameter: N - The upper limit of the range.
// Returns: The sum of all even numbers from 1 to N.
int SumEvenNumbersFrom1toN_UsingWhile(int N)
{
    int Counter = 0;  // Initialize the counter.
    int Sum = 0;  // Initialize the sum accumulator.

    // Print the header message.
    cout << "Sum even numbers using While Statement:\n";

    // Use a while loop to sum all even numbers from 1 to N.
    while (Counter < N)
    {
        Counter++;  // Increment the counter.

        // Check if the number is even and add it to the sum if true.
        if (CheckOddOrEven(Counter) == enOddOrEven::Even)
        {
            Sum += Counter;
        }
    }
    return Sum;  // Return the computed sum.
}

// Function: SumEvenNumbersFrom1toN_UsingDoWhile
// Purpose: Computes the sum of all even numbers from 1 to N using a do-while loop.
// Parameter: N - The upper limit of the range.
// Returns: The sum of all even numbers from 1 to N.
int SumEvenNumbersFrom1toN_UsingDoWhile(int N)
{
    int Counter = 0;  // Initialize the counter.
    int Sum = 0;  // Initialize the sum accumulator.

    // Print the header message.
    cout << "Sum even numbers using Do..While Statement:\n";

    // Use a do-while loop to sum all even numbers from 1 to N.
    do
    {
        Counter++;  // Increment the counter.

        // Check if the number is even and add it to the sum if true.
        if (CheckOddOrEven(Counter) == enOddOrEven::Even)
        {
            Sum += Counter;
        }
    } while (Counter < N);  // Repeat until Counter reaches N.

    return Sum;  // Return the computed sum.
}

// Function: SumEvenNumbersFrom1toN_UsingFor
// Purpose: Computes the sum of all even numbers from 1 to N using a for loop.
// Parameter: N - The upper limit of the range.
// Returns: The sum of all even numbers from 1 to N.
int SumEvenNumbersFrom1toN_UsingFor(int N)
{
    int Sum = 0;  // Initialize the sum accumulator.

    // Print the header message.
    cout << "Sum even numbers using For Statement:\n";

    // Use a for loop to iterate from 1 to N and sum all even numbers.
    for (int Counter = 1; Counter <= N; Counter++)
    {
        // Check if the number is even and add it to the sum if true.
        if (CheckOddOrEven(Counter) == enOddOrEven::Even)
        {
            Sum += Counter;
        }
    }

    return Sum;  // Return the computed sum.
}

// Main function: Program entry point.
int main()
{
    // Read the upper limit N from the user.
    int N = ReadNumber();

    // Compute and print the sum of even numbers using different loop types.
    cout << SumEvenNumbersFrom1toN_UsingWhile(N) << endl;
    cout << SumEvenNumbersFrom1toN_UsingDoWhile(N) << endl;
    cout << SumEvenNumbersFrom1toN_UsingFor(N) << endl;

    return 0;  // Return 0 to indicate successful execution.
}