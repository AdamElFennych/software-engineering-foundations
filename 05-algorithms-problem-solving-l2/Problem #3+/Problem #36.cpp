#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadNumber
// Purpose: Prompts the user to enter a number and returns the entered number.
// Returns: The number entered by the user.
int ReadNumber()
{
    int Number;  // Variable to store the user's input.
    cout << "\nPlease enter a number? ";
    cin >> Number;  // Read the number from the user.
    return Number;  // Return the entered number.
}

// Function: AddArrayElement
// Purpose: Adds a new element to the array.
// Parameters:
//   - Number: The number to add to the array.
//   - arr: The array to which the number will be added.
//   - arrLength: A reference to the variable tracking the number of elements in the array.
// Behavior: Increments the array length and stores the new element at the new last position.
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    // Since it's a new element, increase the array length by 1.
    arrLength++;
    // Store the new element at the index corresponding to the updated length (using zero-based indexing).
    arr[arrLength - 1] = Number;
}

// Function: InputUserNumbersInArray
// Purpose: Allows the user to input numbers into an array until they choose to stop.
// Parameters:
//   - arr: The array where user numbers will be stored.
//   - arrLength: A reference to the variable tracking the number of elements in the array.
void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool AddMore = true;  // Boolean flag to control whether more numbers will be added.

    // Continue looping as long as the user wants to add more numbers.
    do
    {
        // Read a number from the user and add it to the array.
        AddArrayElement(ReadNumber(), arr, arrLength);

        // Ask the user if they want to add more numbers.
        // Input 0 for No, 1 for Yes.
        cout << "\nDo you want to add more numbers? [0]:No,[1]:yes? ";
        cin >> AddMore;  // Read user's decision (true if 1, false if 0).

    } while (AddMore);  // Continue looping if the user inputs true.
}

// Function: PrintArray
// Purpose: Prints all the elements of an array separated by spaces.
// Parameters:
//   - arr: The array to print.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline at the end.
}

// Main function: Program entry point.
int main()
{
    int arr[100];      // Declare an array to hold up to 100 integers.
    int arrLength = 0; // Initialize the array length to 0.

    // Prompt the user to input numbers into the array.
    InputUserNumbersInArray(arr, arrLength);

    // Print the final array length and its elements.
    cout << "\nArray Length: " << arrLength << endl;
    cout << "Array elements: ";
    PrintArray(arr, arrLength);

    return 0;  // Return 0 to indicate successful program execution.
}