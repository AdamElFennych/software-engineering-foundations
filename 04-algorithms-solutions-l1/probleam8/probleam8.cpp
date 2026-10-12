#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Enum: enPassFail
// Purpose: Defines two possible outcomes for the mark evaluation: Pass (1) and Fail (2).
enum enPassFail { Pass = 1, Fail = 2 };

// Function: ReadMark
// Purpose: Prompts the user to enter their exam mark and reads it from input.
// Returns: The entered integer mark.
int ReadMark()
{
    int Mark;  // Variable to store the user's input.

    // Prompt the user to enter their mark.
    cout << "Please enter your mark? " << endl;

    cin >> Mark;  // Read the mark entered by the user.

    return Mark;  // Return the entered mark.
}

// Function: CheckMark
// Purpose: Determines whether a given mark is a passing or failing grade.
// Parameter: Mark - the integer mark to be checked.
// Returns: enPassFail::Pass if the mark is 50 or greater, otherwise enPassFail::Fail.
enPassFail CheckMark(int Mark)
{
    // If the mark is 50 or above, return Pass; otherwise, return Fail.
    if (Mark >= 50)
        return enPassFail::Pass;
    else
        return enPassFail::Fail;
}

// Function: PrintResults
// Purpose: Displays whether the student has passed or failed based on the entered mark.
// Parameter: Mark - the integer mark provided by the user.
void PrintResults(int Mark)
{
    // Check if the mark qualifies as a passing grade.
    if (CheckMark(Mark) == enPassFail::Pass)
        cout << "\n You Passed" << endl;
    else
        cout << "\n You Failed" << endl;
}

// Main function: Program entry point.
int main()
{
    // Read the user's mark, check their result, and print the corresponding message.
    PrintResults(ReadMark());

    return 0;  // Return 0 to indicate successful execution.
}