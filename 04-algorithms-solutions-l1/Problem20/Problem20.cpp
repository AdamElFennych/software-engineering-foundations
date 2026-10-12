#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use pow() for exponentiation.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadSquareSide
// Purpose: Prompts the user to enter the side length of a square and reads it from input.
// Returns: The entered side length as a float.
float ReadSquareSide()
{
    float A;  // Variable to store the user's input.

    // Prompt the user to enter the square's side length.
    cout << "Please enter square side A ? " << endl;
    cin >> A;

    return A;  // Return the entered side length.
}

// Function: CircleAreaInscribedInSquare
// Purpose: Computes the area of a circle that is inscribed inside a square using the formula: (? * A²) / 4.
// Parameter: A - Float value representing the side length of the square.
// Returns: The computed area of the inscribed circle as a float.
float CircleAreaInscribedInSquare(float A)
{
    const float PI = 3.141592653589793238;  // Define the mathematical constant PI.

    // Compute the area using the formula: Area = (? * A²) / 4.
    float Area = (PI * pow(A, 2)) / 4;

    return Area;  // Return the computed area.
}

// Function: PrintResult
// Purpose: Displays the computed area of the inscribed circle.
// Parameter: Area - the computed area.
// Returns: None (prints the result).
void PrintResult(float Area)
{
    // Print the inscribed circle's computed area.
    cout << "\nCircle Area = " << Area << endl;
}

// Main function: Program entry point.
int main()
{
    // Read the square's side length, compute the inscribed circle's area, and display the result.
    PrintResult(CircleAreaInscribedInSquare(ReadSquareSide()));

    return 0;  // Return 0 to indicate successful execution.
}