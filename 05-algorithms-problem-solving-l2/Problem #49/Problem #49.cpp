#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to simplify usage of standard functions.

// Function: GetFractionPart
// Purpose: Extracts the fractional part of a floating-point number.
// Parameters:
//   - Number: A floating-point number.
// Returns: The fractional part of the input number.
float GetFractionPart(float Number)
{
    // Subtract the integer part of the number from the original number to get the fractional part.
    return Number - int(Number);
}

// Function: MyCeil
// Purpose: Computes the ceiling value of a floating-point number.
// Parameters:
//   - Number: A floating-point number whose ceiling value is to be determined.
// Returns: The smallest integer greater than or equal to the input number.
int MyCeil(float Number)
{
    // If the number has a fractional part greater than zero, round up if positive.
    if (abs(GetFractionPart(Number)) > 0)
    {
        if (Number > 0)
            return int(Number) + 1;  // Round up for positive numbers.
        else
            return int(Number);  // Keep the integer part for negative numbers.
    }
    else
        return Number;  // If the number is already an integer, return it as is.
}

// Function: ReadNumber
// Purpose: Reads a floating-point number from the user.
// Returns: The number entered by the user.
float ReadNumber()
{
    float Number;  // Variable to store user input.

    // Prompt the user to enter a floating-point number.
    cout << "Please enter a number? ";
    cin >> Number;  // Read input from the user.

    return Number;  // Return the input number.
}

// Main function: Entry point of the program.
int main()
{
    float Number = ReadNumber();  // Read a number from the user.

    // Print the ceiling value using the custom MyCeil function.
    cout << "My MyCeil Result : " << MyCeil(Number) << endl;

    // Print the ceiling value using the built-in ceil function for comparison.
    cout << "C++ ceil Result: " << ceil(Number) << endl;

    return 0;  // Return 0 to indicate successful program execution.
}