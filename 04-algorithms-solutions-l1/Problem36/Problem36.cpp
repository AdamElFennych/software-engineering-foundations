#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for handling messages.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Enum: enOperationType
// Purpose: Represents four basic arithmetic operations.
enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

// Function: ReadNumber
// Purpose: Prompts the user to enter a number and reads it from input.
// Parameter:
//   - Message: A string containing the prompt message to be displayed.
// Returns: A float representing the user's input number.
float ReadNumber(string Message)
{
    float Number = 0;  // Variable to store the user's input.

    // Prompt the user to enter a number.
    cout << Message << endl;
    cin >> Number;

    return Number;  // Return the entered number.
}

// Function: ReadOpType
// Purpose: Prompts the user to enter an arithmetic operation type and reads it from input.
// Returns: The chosen operation as an enOperationType enum.
enOperationType ReadOpType()
{
    char OT = '+';  // Default operation type.

    // Prompt the user to enter the operation type.
    cout << "Please enter Operation Type ( +, - , * , / )?\n";
    cin >> OT;

    // Cast the input character to enOperationType and return it.
    return (enOperationType)OT;
}

// Function: Calculate
// Purpose: Performs the selected arithmetic operation on two numbers.
// Parameters:
//   - Number1: The first operand.
//   - Number2: The second operand.
//   - OpType: The arithmetic operation to perform.
// Returns: The computed result as a float.
float Calculate(float Number1, float Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;  // Perform addition.
    case enOperationType::Subtract:
        return Number1 - Number2;  // Perform subtraction.
    case enOperationType::Multiply:
        return Number1 * Number2;  // Perform multiplication.
    case enOperationType::Divide:
        return Number1 / Number2;  // Perform division.
    default:
        return Number1 + Number2;  // Default case (fallback to addition).
    }
}

// Main function: Program entry point.
int main()
{
    // Read the first and second numbers from the user.
    float Number1 = ReadNumber("Please enter the first number?");
    float Number2 = ReadNumber("Please enter the second number?");

    // Read the operation type from the user.
    enOperationType OpType = ReadOpType();

    // Perform the selected operation and display the result.
    cout << endl << "Result = " << Calculate(Number1, Number2, OpType) << endl;

    return 0;  // Return 0 to indicate successful execution.
}