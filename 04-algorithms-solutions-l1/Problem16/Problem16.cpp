#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.
#include <cmath>      // Include cmath to use sqrt() and pow() functions.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumbers
// Purpose: Prompts the user to enter a rectangle's side and diagonal, storing them using reference variables.
// Parameters: 
//   - A: Reference to the float variable representing one side of the rectangle.
//   - D: Reference to the float variable representing the diagonal of the rectangle.
// Returns: None (values are stored in reference variables).
void ReadNumbers(float& A, float& D)
{
    // Prompt the user to enter the rectangle's side (A) and store it.
    cout << "Please enter rectangle side A ? " << endl;
    cin >> A;

    // Prompt the user to enter the rectangle's diagonal (D) and store it.
    cout << "Please enter rectangle diagonal D ? " << endl;
    cin >> D;
}

// Function: RectangleAreaBySideAndDiagonal
// Purpose: Computes the area of a rectangle using one side and the diagonal.
// Parameters: 
//   - A: Float value representing one side of the rectangle.
//   - D: Float value representing the diagonal of the rectangle.
// Returns: The computed area of the rectangle as a float.
float RectangleAreaBySideAndDiagonal(float A, float D)
{
    // Calculate the area using the formula: Area = A * sqrt(D² - A²)
    float Area = A * sqrt(pow(D, 2) - pow(A, 2));

    return Area;  // Return the computed area.
}

// Function: PrintResult
// Purpose: Displays the computed area of the rectangle.
// Parameter: Area - the computed area.
// Returns: None (prints the result).
void PrintResult(float Area)
{
    // Print the rectangle's computed area.
    cout << "\nRectangle Area = " << Area << endl;
}

// Main function: Program entry point.
int main()
{
    float A, D;  // Declare two float variables to store the rectangle's side and diagonal.

    // Read the rectangle's side and diagonal from the user.
    ReadNumbers(A, D);

    // Compute the area and display the result.
    PrintResult(RectangleAreaBySideAndDiagonal(A, D));

    return 0;  // Return 0 to indicate successful execution.
}