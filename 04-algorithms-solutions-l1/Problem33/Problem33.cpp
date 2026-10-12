#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumberInRange
// Purpose: Prompts the user to enter a grade within a specified range and ensures valid input.
// Parameters:
//   - From: The lower bound of the acceptable range.
//   - To: The upper bound of the acceptable range.
// Returns: A validated integer representing the grade.
int ReadNumberInRange(int From, int To)
{
    int Grade;  // Variable to store the user's input.

    // Keep prompting the user until a valid grade (between From and To) is entered.
    do
    {
        cout << "Please enter a Grade between " << From << " and " << To << "? " << endl;
        cin >> Grade;
    } while (Grade < From || Grade > To);  // Repeat if the input is out of range.

    return Grade;  // Return the validated grade.
}

// Function: GetGradeLetter
// Purpose: Determines the letter grade corresponding to the numeric grade.
// Parameter:
//   - Grade: The numeric grade to be converted to a letter grade.
// Returns: A character representing the letter grade.
char GetGradeLetter(int Grade)
{
    if (Grade >= 90)
        return 'A';
    else if (Grade >= 80)
        return 'B';
    else if (Grade >= 70)
        return 'C';
    else if (Grade >= 60)
        return 'D';
    else if (Grade >= 50)
        return 'E';
    else
        return 'F';  // If the grade is below 50, return 'F' (Fail).
}

// Main function: Program entry point.
int main()
{
    // Read a valid grade from the user, determine the corresponding letter grade, and display the result.
    cout << endl << "Result = " << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;

    return 0;  // Return 0 to indicate successful execution.
}