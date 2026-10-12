#include <iostream>   // Include the iostream library for input and output operations.
using namespace std;  // Use the standard namespace to simplify usage of standard library functions.

// Enumeration: enPrimNotPrime
// Purpose: Classifies a number as either Prime or NotPrime.
// Values:
//   - Prime: Assigned the value 1, indicates that the number is prime.
//   - NotPrime: Assigned the value 2, indicates that the number is not prime.
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

// Function: CheckPrime
// Purpose: Checks whether a given number is prime.
// Parameters:
//   - Number: The integer to check for primality.
// Returns: enPrimNotPrime::Prime if the number is prime, otherwise enPrimNotPrime::NotPrime.
// Note: This implementation checks divisibility from 2 up to round(Number/2),
// which is a simple (though not optimal) method for small numbers.
enPrimNotPrime CheckPrime(int Number)
{
    // Calculate M as an approximate half of Number.
    // Using round(Number / 2) is not the most efficient method (usually sqrt(Number) is used),
    // but it works for small values.
    int M = round(Number / 2);

    // Loop from 2 to M (inclusive) to test if any number divides Number evenly.
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime; // If divisible, Number is not prime.
    }

    // If no divisors are found, return Prime.
    return enPrimNotPrime::Prime;
}

// Function: RandomNumber
// Purpose: Generates a random integer within the inclusive range [From, To].
// Parameters:
//   - From: The lower bound of the random range.
//   - To:   The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number using rand() and the modulus operator.
    // rand() % (To - From + 1) yields a number between 0 and (To - From),
    // and then adding From shifts the result to the range [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: FillArrayWithRandomNumbers
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An integer array with a maximum capacity of 100.
//   - arrLength: A reference variable that will hold the number of elements to be filled.
// The function prompts the user to input the desired number of elements, then fills each element.
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // Loop over the array indices from 0 to arrLength - 1,
    // assigning each element a random number between 1 and 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array separated by spaces.
// Parameters:
//   - arr: The array to be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    // Loop through the array and print each element followed by a space.
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  // Print a newline after printing all elements.
}

// Function: AddArrayElement
// Purpose: Adds a new element to the end of an array and updates its length.
// Parameters:
//   - Number: The integer to add to the array.
//   - arr: The array where the number will be added.
//   - arrLength: A reference variable representing the current number of elements.
// Behavior: Increments arrLength by 1 and assigns Number to the new last position.
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    // Increase the array length since we are adding a new element.
    arrLength++;
    // Place the new element at the index (arrLength - 1) (because array indexing starts at 0).
    arr[arrLength - 1] = Number;
}

// Function: CopyPrimeNumbers
// Purpose: Copies only the prime numbers from a source array into a destination array.
// Parameters:
//   - arrSource: The source array containing the original numbers.
//   - arrDestination: The destination array where prime numbers will be copied.
//   - arrLength: The number of elements in the source array.
//   - arrDestinationLength: A reference variable to track the number of prime numbers copied.
// Behavior: Iterates over the source array; if a number is prime, it is added to the destination array.
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    // Loop through each element of the source array.
    for (int i = 0; i < arrLength; i++)
    {
        // Check if the current element is prime using the CheckPrime function.
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            // If the number is prime, add it to the destination array.
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}

// Main function: Program entry point.
int main() {
    // Seed the random number generator with the current time.
    // This ensures that the sequence of random numbers is different each time the program is run.
    srand((unsigned)time(NULL));

    int arr[100];      // Declare the source array with a capacity of 100 integers.
    int arrLength = 0; // Initialize the source array length to 0.
    int arr2[100];     // Declare the destination array for prime numbers.
    int arr2Length = 0; // Initialize the destination array length to 0.

    // Fill the source array with random numbers.
    FillArrayWithRandomNumbers(arr, arrLength);

    // Copy only the prime numbers from the source array to the destination array.
    CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    // Print the original array.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Print the destination array containing only prime numbers.
    cout << "\nArray 2 Prime numbers:\n";
    PrintArray(arr2, arr2Length);

    return 0;  // Return 0 to indicate successful program execution.
}