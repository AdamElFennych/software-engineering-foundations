#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumbers
// Purpose: Prompts the user to enter the base and height of a triangle, storing them using reference variables.
// Parameters: 
//   - A: Reference to the float variable representing the base of the triangle.
//   - H: Reference to the float variable representing the height of the triangle.
// Returns: None (values are stored in reference variables).
void ReadNumbers(float& A, float& H)
{
    // Prompt the user to enter the base (A) and store it.
    cout << "Please enter triangle base A ? " << endl;
    cin >> A;

    // Prompt the user to enter the height (H) and store it.
    cout << "Please enter triangle height H ? " << endl;
    cin >> H;
}

// Function: TriangleArea
// Purpose: Computes the area of a triangle given its base and height.
// Parameters: 
//   - A: Float value representing the base of the triangle.
//   - H: Float value representing the height of the triangle.
// Returns: The computed area of the triangle as a float.
float TriangleArea(float A, float H)
{
    // Calculate the area using the formula: Area = (1/2) * Base * Height.
    float Area = (A / 2) * H;

    return Area;  // Return the computed area.
}

// Function: PrintResult
// Purpose: Displays the computed area of the triangle.
// Parameter: Area - the computed area.
// Returns: None (prints the result).
void PrintResult(float Area)
{
    // Print the triangle's computed area.
    cout << "\nTriangle Area = " << Area << endl;
}

// Main function: Program entry point.
int main()
{
    float A, H;  // Declare two float variables to store the triangle's base and height.

    // Read the triangle's base and height from the user.
    ReadNumbers(A, H);

    // Compute the area and display the result.
    PrintResult(TriangleArea(A, H));

    return 0;  // Return 0 to indicate successful execution.
}