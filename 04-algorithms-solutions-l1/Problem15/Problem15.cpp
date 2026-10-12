#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumbers
// Purpose: Prompts the user to enter the width and length of a rectangle and stores them using reference variables.
// Parameters: 
//   - A: Reference to the float variable representing the width.
//   - B: Reference to the float variable representing the length.
// Returns: None (values are stored in reference variables).
void ReadNumbers(float& A, float& B)
{
    // Prompt the user to enter the width (A) and store it.
    cout << "Please enter rectangle width A ? " << endl;
    cin >> A;

    // Prompt the user to enter the length (B) and store it.
    cout << "Please enter rectangle length B ? " << endl;
    cin >> B;
}

// Function: CalculateRectangleArea
// Purpose: Computes the area of a rectangle given its width and length.
// Parameters: 
//   - A: Float value representing the width.
//   - B: Float value representing the length.
// Returns: The computed area of the rectangle as a float.
float CalculateRectangleArea(float A, float B)
{
    return A * B;  // Compute and return the rectangle's area.
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
    float A, B;  // Declare two float variables to store the rectangle's width and length.

    // Read rectangle dimensions from the user.
    ReadNumbers(A, B);

    // Compute the area and display the result.
    PrintResult(CalculateRectangleArea(A, B));

    return 0;  // Return 0 to indicate successful execution.
}