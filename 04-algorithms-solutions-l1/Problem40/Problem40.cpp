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

// Function: TotalBillAfterServiceAndTax
// Purpose: Computes the total bill amount after adding service and tax charges.
// Parameter:
//   - TotalBill: The initial total bill amount before service and tax.
// Returns: The final total bill after applying service charge and tax.
float TotalBillAfterServiceAndTax(float TotalBill)
{
    TotalBill = TotalBill * 1.1;   // Add 10% service charge.
    TotalBill = TotalBill * 1.16;  // Add 16% tax.

    return TotalBill;  // Return the final bill amount.
}

// Main function: Program entry point.
int main()
{
    // Read the total bill amount from the user.
    float TotalBill = ReadPositiveNumber("Please Enter Total Bill?");

    cout << endl;  // Print an empty line for formatting.

    // Display the initial total bill.
    cout << "Total Bill = " << TotalBill << endl;

    // Compute and display the final bill after service and tax.
    cout << "Total Bill After Service and Tax = "
        << TotalBillAfterServiceAndTax(TotalBill) << endl;

    return 0;  // Return 0 to indicate successful execution.
}