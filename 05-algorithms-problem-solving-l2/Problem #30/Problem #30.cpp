#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: RandomNumber
// Purpose: Generates a random integer between the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the random range.
//   - To:   The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number using the modulus operator.
    // rand() % (To - From + 1) produces a value between 0 and (To - From),
    // then adding From shifts the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a message to enter a positive number.
//          Repeats the prompt until the user enters a number greater than zero.
// Parameters:
//   - Message: A string containing the prompt to display.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl;  // Display the prompt message.
        cin >> Number;            // Read the number entered by the user.
    } while (Number <= 0);        // Continue prompting if the number is not positive.

    return Number;  // Return the validated positive number.
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An integer array (capacity 100) that will be filled with random numbers.
//   - arrLength: The number of elements in the array to be filled.
void FillArrayWithRandomNumbers(int arr[100], int arrLength)
{
    // Loop through the array from index 0 to arrLength - 1.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);  // Assign each element a random number between 1 and 100.
}

// Function: SumOf2Arrays
// Purpose: Computes the element-wise sum of two arrays and stores the result in a third array.
// Parameters:
//   - arr1: The first source array.
//   - arr2: The second source array.
//   - arrSum: The destination array that will store the sum of corresponding elements.
//   - arrLength: The number of elements in each array.
void SumOf2Arrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength)
{
    // Loop through each index and add the corresponding elements from arr1 and arr2.
    for (int i = 0; i < arrLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];  // Store the sum in the arrSum array.
    }
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array, separated by spaces.
// Parameters:
//   - arr: The array to be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and output each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << "\n";  // Print a newline after all elements are printed.
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that the sequence of random numbers is different on each run.
    srand((unsigned)time(NULL));

    // Declare three arrays to store integers.
    int arr[100], arr2[100], arrSum[100];

    // Read a positive number from the user, which determines the number of elements in the arrays.
    int arrLength = ReadPositiveNumber("How many elements ?\n");

    // Fill both arr and arr2 with random numbers between 1 and 100.
    FillArrayWithRandomNumbers(arr, arrLength);
    FillArrayWithRandomNumbers(arr2, arrLength);

    // Compute the element-wise sum of arr and arr2, and store the results in arrSum.
    SumOf2Arrays(arr, arr2, arrSum, arrLength);

    // Print the elements of the first array.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Print the elements of the second array.
    cout << "\nArray 2 elements:\n";
    PrintArray(arr2, arrLength);

    // Print the elements of the array that contains the sums of arr and arr2.
    cout << "\nSum of array1 and array2 elements:\n";
    PrintArray(arrSum, arrLength);

    return 0;  // Return 0 to indicate successful program execution.
}