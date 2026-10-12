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

// Function: TotalMonths
// Purpose: Calculates the total number of months required to pay off a loan based on monthly installment.
// Parameters:
//   - LoanAmount: The total loan amount.
//   - MonthlyInstallment: The monthly installment amount.
// Returns: The total number of months required to repay the loan.
float TotalMonths(float LoanAmount, float MonthlyInstallment)
{
    return LoanAmount / MonthlyInstallment;  // Compute and return the total months.
}

// Main function: Program entry point.
int main()
{
    // Read the total loan amount from the user.
    float LoanAmount = ReadPositiveNumber("Please Enter Loan Amount?");

    // Read the monthly installment amount from the user.
    float MonthlyInstallment = ReadPositiveNumber("Please Enter Monthly Installment?");

    // Compute and display the total months required to repay the loan.
    cout << "\nTotal Months to pay = " << TotalMonths(LoanAmount, MonthlyInstallment) << endl;

    return 0;  // Return 0 to indicate successful execution.
}