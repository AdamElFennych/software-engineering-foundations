#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: before standard functions.

// Enumeration: enPrimNotPrime
// Purpose: To classify a number as either Prime or NotPrime.
// Values:
//   Prime    = 1 (indicating the number is prime)
//   NotPrime = 2 (indicating the number is not prime)
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

// Function: CheckPrime
// Purpose: Checks whether a given integer is a prime number.
// Parameters:
//   - Number: The integer to check for primality.
// Returns: enPrimNotPrime::Prime if Number is prime,
//          enPrimNotPrime::NotPrime if Number is not prime.
enPrimNotPrime CheckPrime(int Number)
{
    // Compute M as roughly half of Number.
    // Note: Using round(Number / 2) here might not be the best approach
    // since for small numbers it may not be accurate; typically, we check until sqrt(Number).
    int M = round(Number / 2);

    // Loop from 2 to M to test for divisibility.
    for (int Counter = 2; Counter <= M; Counter++)
    {
        // If Number is divisible by any Counter, then it is not a prime.
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;  // Return NotPrime immediately.
    }

    // If no divisors were found, return Prime.
    return enPrimNotPrime::Prime;
}

// Function: RandomNumber
// Purpose: Generates a random integer between the inclusive range [From, To].
// Parameters:
//   - From: Lower bound of the random range.
//   - To:   Upper bound of the random range.
// Returns: A random integer within the specified range.
int RandomNumber(int From, int To)
{
    // Calculate random number using modulus operator.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: FillArray
// Purpose: Fills an array with random integers between 1 and 100.
// Parameters:
//   - arr: An integer array (with a capacity of 100) that will hold the random numbers.
//   - arrLength: A reference variable that will store the number of elements in the array.
// The user is prompted to enter the desired number of elements.
void FillArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;  // Read the number of elements from the user.

    // For each position in the array (from 0 to arrLength - 1),
    // fill the element with a random number between 1 and 100.
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

// Function: CopyOnlyPrimaryNumbers
// Purpose: Copies only the prime numbers from a source array into a destination array.
// Parameters:
//   - arrSource: The source array from which numbers will be checked.
//   - arrDestination: The destination array where prime numbers will be stored.
//   - arrLength: The number of elements in the source array.
//   - arr2Lenght: A reference variable that will hold the number of prime numbers copied.
// Note: The function uses the CheckPrime function to determine if a number is prime.
void CopyOnlyPrimaryNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Lenght)
{
    int Counter = 0;  // Initialize a counter for the destination array index.

    // Loop through each element in the source array.
    for (int i = 0; i < arrLength; i++)
    {
        // If the current element is prime...
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            // Copy it to the destination array at the current counter index.
            arrDestination[Counter] = arrSource[i];
            Counter++;  // Increment the counter.
        }
    }

    // The code decrements Counter by 1 before assigning it to arr2Lenght.
    // Note: This is unusual as it reduces the count by one. It may be intended to adjust for 0-based indexing,
    // but typically the counter already reflects the number of primes found.
    arr2Lenght = --Counter;
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

    cout << "\n";  // Print a newline at the end.
}

// Main function: Entry point of the program.
int main() {
    // Seed the random number generator with the current time to ensure different sequences on each run.
    srand((unsigned)time(NULL));

    int arr[100];      // Declare the source array.
    int arrLength;     // Will hold the number of elements in the source array.

    // Fill the source array with random numbers.
    FillArray(arr, arrLength);

    int arr2[100];     // Declare the destination array for prime numbers.
    int arr2Length = 0;  // Initialize the length of the destination array.

    // Copy only the prime numbers from the source array to the destination array.
    CopyOnlyPrimaryNumbers(arr, arr2, arrLength, arr2Length);

    // Print the source array.
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);

    // Print the destination array containing only prime numbers.
    cout << "\nPrime Numbers in Array2:\n";
    PrintArray(arr2, arr2Length);

    return 0;  // Return 0 to indicate successful program execution.
}