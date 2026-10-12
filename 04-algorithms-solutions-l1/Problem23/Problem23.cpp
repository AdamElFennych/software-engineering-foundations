#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use sqrt() and pow() functions.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadTriangleData
// Purpose: Prompts the user to enter the three sides of a triangle and stores them using reference variables.
// Parameters: 
//   - A: Reference to the float variable representing the first side of the triangle.
//   - B: Reference to the float variable representing the second side of the triangle.
//   - C: Reference to the float variable representing the third side of the triangle.
// Returns: None (values are stored in reference variables).
void ReadTriangleData(float& A, float& B, float& C)
{
    // Prompt the user to enter the length of the first side (A).
    cout << "Please enter triangle side A ? " << endl;
    cin >> A;

    // Prompt the user to enter the length of the second side (B).
    cout << "Please enter triangle base B ? " << endl;
    cin >> B;

    // Prompt the user to enter the length of the third side (C).
    cout << "Please enter triangle side C ? " << endl;
    cin >> C;
}

// Function: CircleAreaByATriangle
// Purpose: Computes the area of a circle inscribed in a triangle using the formula:
//          Area = π * (T²), where T = (ABC) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)))
// Parameters: 
//   - A: Float value representing the first side of the triangle.
//   - B: Float value representing the second side of the triangle.
//   - C: Float value representing the third side of the triangle.
// Returns: The computed area of the inscribed circle as a float.
float CircleAreaByATriangle(float A, float B, float C)
{
    const float PI = 3.141592653589793238;  // Define the mathematical constant PI.

    // Compute the semi-perimeter of the triangle using P = (A + B + C) / 2.
    float P = (A + B + C) / 2;

    // Compute the radius (T) of the inscribed circle using:
    // T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)))
    float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));

    // Compute the area of the inscribed circle: Area = π * T².
    float Area = PI * pow(T, 2);

    return Area;  // Return the computed area.
}

// Function: PrintResult
// Purpose: Displays the computed area of the inscribed circle.
// Parameter: Area - the computed area.
// Returns: None (prints the result).
void PrintResult(float Area)
{
    // Print the computed area of the inscribed circle.
    cout << "\nCircle Area = " << Area << endl;
}

// Main function: Program entry point.
int main()
{
    float A, B, C;  // Declare three float variables to store the sides of the triangle.

    // Read the triangle's three sides from the user.
    ReadTriangleData(A, B, C);

    // Compute the area of the inscribed circle and display the result.
    PrintResult(CircleAreaByATriangle(A, B, C));

    return 0;  // Return 0 to indicate successful execution.
}