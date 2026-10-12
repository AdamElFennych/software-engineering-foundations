#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use pow() for exponentiation.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadTriangleData
// Purpose: Prompts the user to enter the side length and base of an isosceles triangle and stores them using reference variables.
// Parameters: 
//   - A: Reference to the float variable representing one equal side of the isosceles triangle.
//   - B: Reference to the float variable representing the base of the triangle.
// Returns: None (values are stored in reference variables).
void ReadTriangleData(float& A, float& B)
{
    // Prompt the user to enter the length of one of the equal sides (A).
    cout << "Please enter triangle side A ? " << endl;
    cin >> A;

    // Prompt the user to enter the base (B) of the isosceles triangle.
    cout << "Please enter triangle base B ? " << endl;
    cin >> B;
}

// Function: CircleAreaByITriangle
// Purpose: Computes the area of a circle inscribed in an isosceles triangle using a specific formula.
// Parameters: 
//   - A: Float value representing one equal side of the isosceles triangle.
//   - B: Float value representing the base of the isosceles triangle.
// Returns: The computed area of the inscribed circle as a float.
float CircleAreaByITriangle(float A, float B)
{
    const float PI = 3.141592653589793238;  // Define the mathematical constant PI.

    // Compute the area using the given formula:
    // Area = π * (B² / 4) * ((2A - B) / (2A + B))
    float Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));

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
    float A, B;  // Declare two float variables to store the side and base of the isosceles triangle.

    // Read the triangle's side and base from the user.
    ReadTriangleData(A, B);

    // Compute the area of the inscribed circle and display the result.
    PrintResult(CircleAreaByITriangle(A, B));

    return 0;  // Return 0 to indicate successful execution.
}