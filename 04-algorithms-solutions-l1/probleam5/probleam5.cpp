#include <iostream>   // Include iostream for input/output operations.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Struct: stInfo
// Purpose: Stores candidate information including age, driving license status, and recommendation status.
struct stInfo
{
    int Age;                  // Stores the candidate's age.
    bool HasDrivingLicense;   // Stores whether the candidate has a driving license (true/false).
    bool HasRecommendation;   // Stores whether the candidate has a recommendation (true/false).
};

// Function: ReadInfo
// Purpose: Prompts the user to enter their age, driving license status, and recommendation status.
// Returns: A struct containing the entered candidate information.
stInfo ReadInfo()
{
    stInfo Info;  // Declare a variable of type stInfo to store user input.

    // Prompt the user to enter their age and store it in the struct.
    cout << "Please Enter Your Age?" << endl;
    cin >> Info.Age;

    // Prompt the user to enter whether they have a driver's license (expects 1 for true, 0 for false).
    cout << "Do you have a driver’s license? (1 for Yes, 0 for No)" << endl;
    cin >> Info.HasDrivingLicense;

    // Prompt the user to enter whether they have a recommendation (expects 1 for true, 0 for false).
    cout << "Do you have a recommendation? (1 for Yes, 0 for No)" << endl;
    cin >> Info.HasRecommendation;

    return Info;  // Return the filled struct.
}

// Function: IsAccepted
// Purpose: Determines if the candidate is accepted based on age, license, and recommendation status.
// Parameter: Info - struct containing the candidate's details.
// Returns: true if the candidate meets the criteria, otherwise false.
bool IsAccepted(stInfo Info)
{
    // If the candidate has a recommendation, they are automatically accepted.
    if (Info.HasRecommendation)
    {
        return true;
    }
    else
    {
        // Otherwise, the candidate must be older than 21 and have a driving license.
        return (Info.Age > 21 && Info.HasDrivingLicense);
    }
}

// Function: PrintResult
// Purpose: Prints whether the candidate is hired or rejected based on eligibility.
// Parameter: Info - struct containing the candidate's details.
void PrintResult(stInfo Info)
{
    // Check eligibility using IsAccepted function and print the corresponding message.
    if (IsAccepted(Info))
        cout << "\n Hired" << endl;
    else
        cout << "\n Rejected" << endl;
}

// Main function: Program entry point.
int main()
{
    // Read candidate information, check eligibility, and print the result.
    PrintResult(ReadInfo());

    return 0;  // Return 0 to indicate successful execution.
}