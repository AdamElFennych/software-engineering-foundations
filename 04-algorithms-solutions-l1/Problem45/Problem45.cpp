#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to return month names.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Enum: enMonthOfYear
// Purpose: Represents the months of the year with corresponding numerical values.
enum enMonthOfYear {
    Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5,
    Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10,
    Nov = 11, Dec = 12
};

// Function: ReadNumberInRange
// Purpose: Prompts the user to enter a number within a specified range and ensures valid input.
// Parameters:
//   - Message: A string containing the prompt message to be displayed.
//   - From: The lower bound of the acceptable range.
//   - To: The upper bound of the acceptable range.
// Returns: A validated integer representing the user's input.
int ReadNumberInRange(string Message, int From, int To)
{
    int Number = 0;  // Variable to store the user's input.

    // Keep prompting the user until a valid number within the specified range is entered.
    do
    {
        cout << Message << endl;  // Display the provided message.
        cin >> Number;  // Read the number entered by the user.
    } while (Number < From || Number > To);  // Repeat if the input is out of range.

    return Number;  // Return the validated number.
}

// Function: ReadMonthOfYear
// Purpose: Prompts the user to enter a month number (1-12) and returns the corresponding enum value.
// Returns: The selected month as an enMonthOfYear enum.
enMonthOfYear ReadMonthOfYear()
{
    // Read a number between 1 and 12 and cast it to enMonthOfYear enum.
    return (enMonthOfYear)ReadNumberInRange("Please enter a month [1 to 12]:", 1, 12);
}

// Function: GetMonthOfYear
// Purpose: Converts an enMonthOfYear enum value into a string representing the month's name.
// Parameter:
//   - Month: An enMonthOfYear value representing the month.
// Returns: A string containing the name of the corresponding month.
string GetMonthOfYear(enMonthOfYear Month)
{
    // Use a switch statement to return the correct month name.
    switch (Month)
    {
    case enMonthOfYear::Jan:
        return "January";
    case enMonthOfYear::Feb:
        return "February";
    case enMonthOfYear::Mar:
        return "March";
    case enMonthOfYear::Apr:
        return "April";
    case enMonthOfYear::May:
        return "May";
    case enMonthOfYear::Jun:
        return "June";  // Fixed typo: Changed "Jun" to "June"
    case enMonthOfYear::Jul:
        return "July";
    case enMonthOfYear::Aug:
        return "August";
    case enMonthOfYear::Sep:
        return "September";
    case enMonthOfYear::Oct:
        return "October";
    case enMonthOfYear::Nov:
        return "November";
    case enMonthOfYear::Dec:
        return "December";
    default:
        return "Not a valid Month";  // Default case (should never be reached).
    }
}

// Main function: Program entry point.
int main()
{
    // Read a month number from the user, determine the corresponding month name, and display it.
    cout << GetMonthOfYear(ReadMonthOfYear()) << endl;

    return 0;  // Return 0 to indicate successful execution.
}