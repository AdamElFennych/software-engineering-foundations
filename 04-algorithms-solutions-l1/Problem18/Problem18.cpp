#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use pow() for exponentiation.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadRadius
// Purpose: Prompts the user to enter the radius of a circle and reads it from input.
// Returns: The entered radius as a float.
float ReadRadius()
{
    float R;  // Variable to store the user's input.

    // Prompt the user to enter the circle's radius.
    cout << "Please enter radius R ? " << endl;
    cin >> R;

    return R;  // Return the entered radius.
}

// Function: CircleArea
// Purpose: Computes the area of a circle given its radius.
// Parameter: R - Float value representing the radius of the circle.
// Returns: The computed area of the circle as a float.
float CircleArea(float R)
{
    const float PI = 3.141592653589793238;  // Define the mathematical constant PI.

    // Compute the area using the formula: Area = ? * R².
    float Area = pow(R, 2) * PI;

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
    // Read the radius, compute the area, and display the result.
    PrintResult(CircleArea(ReadRadius()));

    return 0;  // Return 0 to indicate successful execution.
}