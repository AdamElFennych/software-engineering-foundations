#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadTotalSales
// Purpose: Prompts the user to enter the total sales amount and reads it from input.
// Returns: The entered total sales as a float.
float ReadTotalSales()
{
    float TotalSales;  // Variable to store the user's input.

    // Prompt the user to enter the total sales.
    cout << "Please enter Total Sales? " << endl;
    cin >> TotalSales;

    return TotalSales;  // Return the entered total sales amount.
}

// Function: GetCommissionPercentage
// Purpose: Determines the commission percentage based on the total sales amount.
// Parameter:
//   - TotalSales: The total sales amount.
// Returns: The commission percentage as a float.
float GetCommissionPercentage(float TotalSales)
{
    if (TotalSales >= 1000000)
        return 0.01;  // 1% commission for sales ≥ 1,000,000
    else if (TotalSales >= 500000)
        return 0.02;  // 2% commission for sales between 500,000 and 999,999
    else if (TotalSales >= 100000)
        return 0.03;  // 3% commission for sales between 100,000 and 499,999
    else if (TotalSales >= 50000)
        return 0.05;  // 5% commission for sales between 50,000 and 99,999
    else
        return 0.00;  // No commission for sales below 50,000
}

// Function: CalculateTotalCommission
// Purpose: Computes the total commission amount based on total sales.
// Parameter:
//   - TotalSales: The total sales amount.
// Returns: The total commission amount as a float.
float CalculateTotalCommission(float TotalSales)
{
    return GetCommissionPercentage(TotalSales) * TotalSales;  // Multiply sales by commission percentage.
}

// Main function: Program entry point.
int main()
{
    // Read the total sales amount from the user.
    float TotalSales = ReadTotalSales();

    // Display the commission percentage.
    cout << endl << "Commission Percentage = " << GetCommissionPercentage(TotalSales) * 100 << "%" << endl;

    // Display the total commission amount.
    cout << endl << "Total Commission = " << CalculateTotalCommission(TotalSales) << endl;

    return 0;  // Return 0 to indicate successful execution.
}