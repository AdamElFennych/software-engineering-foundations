#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumbers
// Purpose: Prompts the user to enter three integer numbers and stores them using reference variables.
// Parameters: 
//   - Num1: Reference to the first integer variable.
//   - Num2: Reference to the second integer variable.
//   - Num3: Reference to the third integer variable.
// Returns: None (values are stored in reference variables).
void ReadNumbers(int& Num1, int& Num2, int& Num3)
{
    // Prompt the user to enter the first number and store it in Num1.
    cout << "Please enter your Number 1 ? " << endl;
    cin >> Num1;

    // Prompt the user to enter the second number and store it in Num2.
    cout << "Please enter your Number 2 ? " << endl;
    cin >> Num2;

    // Prompt the user to enter the third number and store it in Num3.
    cout << "Please enter your Number 3 ? " << endl;
    cin >> Num3;
}

// Function: SumOf3Numbers
// Purpose: Calculates the sum of three integer numbers.
// Parameters: 
//   - Num1: First integer value.
//   - Num2: Second integer value.
//   - Num3: Third integer value.
// Returns: The sum of the three numbers as an integer.
int SumOf3Numbers(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;  // Compute and return the sum.
}

// Function: PrintResults
// Purpose: Displays the sum of the three numbers.
// Parameter: Total - the total sum of the numbers.
// Returns: None (prints the result).
void PrintResults(int Total)
{
    // Print the calculated sum of the numbers.
    cout << "\n The total sum of numbers is: " << Total << endl;
}

// Main function: Program entry point.
int main()
{
    int Num1, Num2, Num3;  // Declare three integer variables to store user input.

    // Read three numbers from the user.
    ReadNumbers(Num1, Num2, Num3);

    // Compute the sum and display the result.
    PrintResults(SumOf3Numbers(Num1, Num2, Num3));

    return 0;  // Return 0 to indicate successful execution.
}