#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Struct: stPiggyBankContent
// Purpose: Represents the different types of coins and dollar bills in the piggy bank.
struct stPiggyBankContent
{
    int Pennies, Nickels, Dimes, Quarters, Dollars;
};

// Function: ReadPiggyBankContent
// Purpose: Prompts the user to enter the number of different coins and dollar bills in the piggy bank.
// Returns: A struct containing the number of each type of coin/bill.
stPiggyBankContent ReadPiggyBankContent()
{
    stPiggyBankContent PiggyBankContent;  // Variable to store the piggy bank content.

    // Prompt the user to enter the quantity of each type of coin and dollar bill.
    cout << "Please enter the total number of Pennies: " << endl;
    cin >> PiggyBankContent.Pennies;
    cout << "Please enter the total number of Nickels: " << endl;
    cin >> PiggyBankContent.Nickels;
    cout << "Please enter the total number of Dimes: " << endl;
    cin >> PiggyBankContent.Dimes;
    cout << "Please enter the total number of Quarters: " << endl;
    cin >> PiggyBankContent.Quarters;
    cout << "Please enter the total number of Dollar bills: " << endl;
    cin >> PiggyBankContent.Dollars;

    return PiggyBankContent;  // Return the filled struct.
}

// Function: CalculateTotalPennies
// Purpose: Converts all coins and dollar bills in the piggy bank to the equivalent value in pennies.
// Parameter:
//   - PiggyBankContent: A struct containing the number of each type of coin/bill.
// Returns: The total value in pennies.
int CalculateTotalPennies(stPiggyBankContent PiggyBankContent)
{
    // Compute total pennies by converting each coin type to its equivalent in pennies.
    int TotalPennies = PiggyBankContent.Pennies * 1
        + PiggyBankContent.Nickels * 5
        + PiggyBankContent.Dimes * 10
        + PiggyBankContent.Quarters * 25
        + PiggyBankContent.Dollars * 100;

    return TotalPennies;  // Return the total value in pennies.
}

// Main function: Program entry point.
int main()
{
    // Read the piggy bank content and calculate the total value in pennies.
    int TotalPennies = CalculateTotalPennies(ReadPiggyBankContent());

    // Display the total amount in pennies.
    cout << endl << "Total Pennies = " << TotalPennies << endl;

    // Display the total amount in dollars by converting pennies to dollars.
    cout << endl << "Total Dollars = $" << (float)TotalPennies / 100 << endl;

    return 0;  // Return 0 to indicate successful execution.
}