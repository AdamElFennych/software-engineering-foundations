#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use pow() for exponentiation.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadCircumference
// Purpose: Prompts the user to enter the circumference of a circle and reads it from input.
// Returns: The entered circumference as a float.
float ReadCircumference()
{
    float L;  // Variable to store the user's input.

    // Prompt the user to enter the circle's circumference.
    cout << "Please enter Circumference? \n";
    cin >> L;

    return L;  // Return the entered circumference.
}

// Function: CircleAreaByCircumference
// Purpose: Computes the area of a circle given its circumference using the formula: Area = (L²) / (4π).
// Parameter: L - Float value representing the circumference of the circle.
// Returns: The computed area of the circle as a float.
float CircleAreaByCircumference(float L)
{
    const float PI = 3.141592653589793238;  // Define the mathematical constant PI.

    // Compute the area using the formula: Area = (L²) / (4π).
    float Area = pow(L, 2) / (4 * PI);

    return Area;  // Return the computed area.
}

// Function: PrintResult
// Purpose: Displays the computed area of the circle.
// Parameter: Area - the computed area.
// Returns: None (prints the result).
void PrintResult(float Area)
{
    // Print the computed area of the circle.
    cout << "\nCircle Area = " << Area << endl;
}

// Main function: Program entry point.
int main()
{
    // Read the circumference, compute the area, and display the result.
    PrintResult(CircleAreaByCircumference(ReadCircumference()));

    return 0;  // Return 0 to indicate successful execution.
}