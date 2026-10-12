#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use pow() for exponentiation.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadDiameter
// Purpose: Prompts the user to enter the diameter of a circle and reads it from input.
// Returns: The entered diameter as a float.
float ReadDiameter()
{
    float D;  // Variable to store the user's input.

    // Prompt the user to enter the circle's diameter.
    cout << "Please enter diameter D ? " << endl;
    cin >> D;

    return D;  // Return the entered diameter.
}

// Function: CircleAreaByDiameter
// Purpose: Computes the area of a circle given its diameter using the formula: (? * D²) / 4.
// Parameter: D - Float value representing the diameter of the circle.
// Returns: The computed area of the circle as a float.
float CircleAreaByDiameter(float D)
{
    const float PI = 3.141592653589793238;  // Define the mathematical constant PI.

    // Compute the area using the formula: Area = (? * D²) / 4.
    float Area = (pow(D, 2) * PI) / 4;

    return Area;  // Return the computed area.
}

// Function: PrintResult
// Purpose: Displays the computed area of the circle.
// Parameter: Area - the computed area.
// Returns: None (prints the result).
void PrintResult(float Area)
{
    // Print the circle's computed area.
    cout << "\nCircle Area = " << Area << endl;
}

// Main function: Program entry point.
int main()
{
    // Read the diameter, compute the area, and display the result.
    PrintResult(CircleAreaByDiameter(ReadDiameter()));

    return 0;  // Return 0 to indicate successful execution.
}