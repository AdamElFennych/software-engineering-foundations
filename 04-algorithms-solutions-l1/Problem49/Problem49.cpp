#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadPinCode
// Purpose: Prompts the user to enter a PIN code and reads it from input.
// Returns: A string containing the entered PIN code.
string ReadPinCode()
{
    string PinCode;  // Variable to store the entered PIN code.

    // Prompt the user to enter their PIN code.
    cout << "Please enter PIN code \n";
    cin >> PinCode;

    return PinCode;  // Return the entered PIN code.
}

// Function: Login
// Purpose: Authenticates the user by checking if the entered PIN matches "1234".
// Returns: true if login is successful, false otherwise.
bool Login()
{
    string PinCode;  // Variable to store the entered PIN code.

    // Keep prompting the user until the correct PIN is entered.
    do
    {
        PinCode = ReadPinCode();  // Read PIN from user.

        if (PinCode == "1234")  // Check if the entered PIN is correct.
        {
            return true;  // Return true if login is successful.
        }
        else
        {
            cout << "\nWrong PIN\n";  // Notify the user of an incorrect PIN.
            system("color 4F");  // Change console text to red (Windows-specific).
        }

    } while (PinCode != "1234");  // Keep looping until the correct PIN is entered.

    return false;  // This line is redundant, but kept for clarity.
}

// Main function: Program entry point.
int main()
{
    // Check if the user has successfully logged in.
    if (Login())
    {
        system("color 2F");  // Change console text to green (Windows-specific).
        cout << "\nYour account balance is " << 7500 << '\n';  // Display account balance.
    }

    return 0;  // Return 0 to indicate successful execution.
}