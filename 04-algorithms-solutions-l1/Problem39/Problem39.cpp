#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a custom message to enter a positive number and ensures valid input.
// Parameter:
//   - Message: A string containing the prompt message to be displayed.
// Returns: A positive float entered by the user.
float ReadPositiveNumber(string Message)
{
    float Number = 0;  // Variable to store the user's input.

    // Keep prompting the user until a positive number (> 0) is entered.
    do
    {
        cout << Message << endl;  // Display the provided message.
        cin >> Number;  // Read the number entered by the user.
    } while (Number <= 0);  // Repeat if the number is non-positive.

    return Number;  // Return the validated positive number.
}

// Function: CalculateRemainder
// Purpose: Computes the remainder (change) after paying a total bill.
// Parameters:
//   - TotalBill: The total bill amount.
//   - TotalCashPaid: The total amount of cash paid.
// Returns: The remaining amount after subtracting the bill from the paid cash.
float CalculateRemainder(float TotalBill, float TotalCashPaid)
{
    return TotalCashPaid - TotalBill;  // Compute and return the remainder.
}

// Main function: Program entry point.
int main()
{
    // Read the total bill amount from the user.
    float TotalBill = ReadPositiveNumber("Please Enter Total Bill?");

    // Read the total cash paid by the user.
    float TotalCashPaid = ReadPositiveNumber("Please Enter Total Cash Paid?");

    cout << endl;  // Print an empty line for formatting.

    // Display the total bill and total cash paid.
    cout << "Total Bill = " << TotalBill << endl;
    cout << "Total Cash Paid = " << TotalCashPaid << endl;

    cout << "***************************\n";  // Print a separator for readability.

    // Compute and display the remainder (change).
    cout << "Remainder = " << CalculateRemainder(TotalBill, TotalCashPaid) << endl;

    return 0;  // Return 0 to indicate successful execution.
}