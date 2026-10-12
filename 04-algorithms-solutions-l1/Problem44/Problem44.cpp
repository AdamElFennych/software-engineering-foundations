#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to return day names.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Enum: enDayOfWeek
// Purpose: Represents the days of the week with corresponding numerical values.
enum enDayOfWeek { Sat = 1, Sun = 2, Mon = 3, Tue = 4, Wed = 5, Thu = 6, Fri = 7 };

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

// Function: ReadDayOfWeek
// Purpose: Prompts the user to enter a day number (1-7) and returns the corresponding enum value.
// Returns: The selected day as an enDayOfWeek enum.
enDayOfWeek ReadDayOfWeek()
{
    // Read a number between 1 and 7 and cast it to enDayOfWeek enum.
    return (enDayOfWeek)ReadNumberInRange("Please enter day number (Sat=1, Sun=2, Mon=3, Tue=4, Wed=5, Thu=6, Fri=7)?", 1, 7);
}

// Function: GetDayOfWeek
// Purpose: Converts an enDayOfWeek enum value into a string representing the day of the week.
// Parameter:
//   - Day: An enDayOfWeek value representing the day.
// Returns: A string containing the name of the corresponding day.
string GetDayOfWeek(enDayOfWeek Day)
{
    // Use a switch statement to return the correct day name.
    switch (Day)
    {
    case enDayOfWeek::Sat:
        return "Saturday";
    case enDayOfWeek::Sun:
        return "Sunday";
    case enDayOfWeek::Mon:
        return "Monday";
    case enDayOfWeek::Tue:
        return "Tuesday";
    case enDayOfWeek::Wed:
        return "Wednesday";
    case enDayOfWeek::Thu:
        return "Thursday";
    case enDayOfWeek::Fri:
        return "Friday";
    default:
        return "Not a valid Day";  // Default case (should never be reached).
    }
}

// Main function: Program entry point.
int main()
{
    // Read a day number from the user, determine the corresponding day name, and display it.
    cout << GetDayOfWeek(ReadDayOfWeek()) << endl;

    return 0;  // Return 0 to indicate successful execution.
}