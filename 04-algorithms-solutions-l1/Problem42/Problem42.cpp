#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Struct: strTaskDuration
// Purpose: Represents the duration of a task in days, hours, minutes, and seconds.
struct strTaskDuration
{
    int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number and ensures valid input.
// Parameter:
//   - Message: A string containing the prompt message to be displayed.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.

    // Keep prompting the user until a positive number (> 0) is entered.
    do
    {
        cout << Message << endl;  // Display the provided message.
        cin >> Number;  // Read the number entered by the user.
    } while (Number <= 0);  // Repeat if the number is non-positive.

    return Number;  // Return the validated positive number.
}

// Function: ReadTaskDuration
// Purpose: Prompts the user to enter task duration in days, hours, minutes, and seconds.
// Returns: A struct containing the task duration values.
strTaskDuration ReadTaskDuration()
{
    strTaskDuration TaskDuration;  // Variable to store the task duration.

    // Prompt the user to enter each time component of the task duration.
    TaskDuration.NumberOfDays = ReadPositiveNumber("Please Enter Number Of Days?");
    TaskDuration.NumberOfHours = ReadPositiveNumber("Please Enter Number Of Hours?");
    TaskDuration.NumberOfMinutes = ReadPositiveNumber("Please Enter Number Of Minutes?");
    TaskDuration.NumberOfSeconds = ReadPositiveNumber("Please Enter Number Of Seconds?");

    return TaskDuration;  // Return the filled struct.
}

// Function: TaskDurationInSeconds
// Purpose: Converts a given task duration into total seconds.
// Parameter:
//   - TaskDuration: A struct containing the task duration values.
// Returns: The total duration in seconds.
int TaskDurationInSeconds(strTaskDuration TaskDuration)
{
    int DurationInSeconds = 0;  // Initialize total duration in seconds.

    // Convert each time component to seconds and accumulate the total.
    DurationInSeconds = TaskDuration.NumberOfDays * 24 * 60 * 60;  // Convert days to seconds.
    DurationInSeconds += TaskDuration.NumberOfHours * 60 * 60;  // Convert hours to seconds.
    DurationInSeconds += TaskDuration.NumberOfMinutes * 60;  // Convert minutes to seconds.
    DurationInSeconds += TaskDuration.NumberOfSeconds;  // Add remaining seconds.

    return DurationInSeconds;  // Return the total duration in seconds.
}

// Main function: Program entry point.
int main()
{
    // Read task duration from user input and compute total seconds.
    cout << "\nTask Duration In Seconds: " << TaskDurationInSeconds(ReadTaskDuration());
    cout << endl;  // Print a new line for formatting.

    return 0;  // Return 0 to indicate successful execution.
}