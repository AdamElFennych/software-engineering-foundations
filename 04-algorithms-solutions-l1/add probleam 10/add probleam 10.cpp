#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for potential future use.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumbers
// Purpose: Prompts the user to enter three exam marks and stores them using reference variables.
// Parameters: 
//   - Mark1: Reference to the first mark.
//   - Mark2: Reference to the second mark.
//   - Mark3: Reference to the third mark.
// Returns: None (values are stored in reference variables).
void ReadNumbers(int& Mark1, int& Mark2, int& Mark3)
{
    // Prompt the user to enter the first mark and store it in Mark1.
    cout << "Please enter Mark 1 ? " << endl;
    cin >> Mark1;

    // Prompt the user to enter the second mark and store it in Mark2.
    cout << "Please enter Mark 2 ? " << endl;
    cin >> Mark2;

    // Prompt the user to enter the third mark and store it in Mark3.
    cout << "Please enter Mark 3 ? " << endl;
    cin >> Mark3;
}

// Function: SumOf3Marks
// Purpose: Calculates the total sum of three marks.
// Parameters: 
//   - Mark1: First exam mark.
//   - Mark2: Second exam mark.
//   - Mark3: Third exam mark.
// Returns: The sum of the three marks as an integer.
int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
    return Mark1 + Mark2 + Mark3;  // Compute and return the sum.
}

// Function: CalculateAverage
// Purpose: Computes the average of three marks.
// Parameters: 
//   - Mark1: First exam mark.
//   - Mark2: Second exam mark.
//   - Mark3: Third exam mark.
// Returns: A float value representing the average of the marks.
float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
    // Compute the total sum using SumOf3Marks() and divide by 3 to get the average.
    return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

// Function: PrintResults
// Purpose: Displays the calculated average of the marks.
// Parameter: Average - the computed average of the three marks.
// Returns: None (prints the result).
void PrintResults(float Average)
{
    // Print the calculated average of the marks.
    cout << "\n The average is : " << Average << endl;
}

// Main function: Program entry point.
int main()
{
    int Mark1, Mark2, Mark3;  // Declare three integer variables to store exam marks.

    // Read three marks from the user.
    ReadNumbers(Mark1, Mark2, Mark3);

    // Compute the average and display the result.
    PrintResults(CalculateAverage(Mark1, Mark2, Mark3));

    return 0;  // Return 0 to indicate successful execution.
}
