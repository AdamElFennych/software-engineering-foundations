#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumbers
// Purpose: Prompts the user to enter three integer numbers and stores them using reference variables.
// Parameters: 
//   - A: Reference to the first integer variable.
//   - B: Reference to the second integer variable.
//   - C: Reference to the third integer variable.
// Returns: None (values are stored in reference variables).
void ReadNumbers(int& A, int& B, int& C)
{
    // Prompt the user to enter the first number and store it in A.
    cout << "Please enter Number A ? " << endl;
    cin >> A;

    // Prompt the user to enter the second number and store it in B.
    cout << "Please enter Number B ? " << endl;
    cin >> B;

    // Prompt the user to enter the third number and store it in C.
    cout << "Please enter Number C ? " << endl;
    cin >> C;
}

// Function: MaxOf3Numbers
// Purpose: Determines the maximum of three integer numbers.
// Parameters: 
//   - A: First integer value.
//   - B: Second integer value.
//   - C: Third integer value.
// Returns: The greatest of the three numbers.
int MaxOf3Numbers(int A, int B, int C)
{
    // Compare A with B and C to determine the maximum.
    if (A > B)
    {
        if (A > C)
            return A;  // A is the largest
        else
            return C;  // C is larger than A
    }
    else  // B >= A
    {
        if (B > C)
            return B;  // B is the largest
        else
            return C;  // C is larger than B
    }
}

// Function: PrintResults
// Purpose: Displays the maximum number found.
// Parameter: Max - the maximum number.
// Returns: None (prints the result).
void PrintResults(int Max)
{
    // Print the maximum number.
    cout << "\n The Maximum Number is: " << Max << endl;
}

// Main function: Program entry point.
int main()
{
    int A, B, C;  // Declare three integer variables to store user input.

    // Read three numbers from the user.
    ReadNumbers(A, B, C);

    // Compute the maximum and display the result.
    PrintResults(MaxOf3Numbers(A, B, C));

    return 0;  // Return 0 to indicate successful execution.
}