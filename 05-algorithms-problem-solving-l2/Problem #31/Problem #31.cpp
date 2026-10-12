#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: ReadPositiveNumber
// Purpose: Prompts the user to enter a positive number using the provided message.
//          It repeatedly prompts until a valid (positive) number is entered.
// Parameters:
//   - Message: The prompt message to display.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl; // Display the prompt message.
        cin >> Number;           // Read the number entered by the user.
    } while (Number <= 0);       // Continue looping if the number is not positive.
    return Number;  // Return the validated positive number.
}

// Function: Swap
// Purpose: Swaps the values of two integers.
// Parameters:
//   - A: Reference to the first integer.
//   - B: Reference to the second integer.
void Swap(int& A, int& B)
{
    int Temp;    // Temporary variable to hold the value of A.
    Temp = A;    // Save the value of A in Temp.
    A = B;       // Copy the value of B into A.
    B = Temp;    // Copy the value of Temp (original A) into B.
}

// Function: FillArrayWith1toN
// Purpose: Fills an array with sequential numbers from 1 to N, where N is the array length.
// Parameters:
//   - arr: The integer array to fill (capacity 100).
//   - arrLength: The number of elements to fill in the array.
void FillArrayWith1toN(int arr[100], int arrLength)
{
    // Loop through each index and assign the value (index + 1) to that element.
    for (int i = 0; i < arrLength; i++)
        arr[i] = i + 1;
}

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the random range.
//   - To: The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Use the modulus operator to get a random number within the range,
    // then shift it by adding From.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: ShuffleArray
// Purpose: Randomly shuffles the elements in the array.
// Parameters:
//   - arr: The array to shuffle.
//   - arrLength: The number of elements in the array.
void ShuffleArray(int arr[100], int arrLength)
{
    // Loop through each element of the array.
    // For each iteration, swap two randomly chosen elements.
    for (int i = 0; i < arrLength; i++)
    {
        // RandomNumber(1, arrLength) generates a random number between 1 and arrLength.
        // Subtract 1 to convert it to a valid 0-based index.
        int index1 = RandomNumber(1, arrLength) - 1;
        int index2 = RandomNumber(1, arrLength) - 1;
        // Swap the elements at the two randomly chosen indices.
        Swap(arr[index1], arr[index2]);
    }
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   - arr: The array to print.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator using the current time.
    // This ensures that the sequence of random numbers is different on each run.
    srand((unsigned)time(NULL));

    int arr[100];  // Declare an array with capacity for 100 integers.
    // Prompt the user to enter the number of elements in the array.
    int arrLength = ReadPositiveNumber("\nEnter number of elements : \n");

    // Fill the array with sequential numbers from 1 to arrLength.
    FillArrayWith1toN(arr, arrLength);

    // Print the array before shuffling.
    cout << "\nArray elements before shuffle:\n";
    PrintArray(arr, arrLength);

    // Shuffle the array elements randomly.
    ShuffleArray(arr, arrLength);

    // Print the array after shuffling.
    cout << "\nArray elements after shuffle:\n";
    PrintArray(arr, arrLength);

    return 0;  // Return 0 to indicate successful program execution.
}