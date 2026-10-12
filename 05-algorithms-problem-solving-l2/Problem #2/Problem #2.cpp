#include <iostream>   // Include the iostream library for input/output operations
#include <string>     // Include the string library to use std::string
using namespace std;  // Use the standard namespace to avoid writing std:: before standard functions

// Define an enumeration to represent whether a number is prime or not.
// enPrimNotPrime::Prime has a value of 1 and enPrimNotPrime::NotPrime has a value of 2.
enum enPrimNotPrime { Prime = 1, NotPrime = 2 };

// Function: ReadPositiveNumber
// Purpose: Prompts the user with a message to enter a positive number.
//          It keeps asking until the user provides a number greater than 0.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input, initialized to 0.
    do
    {
        // Display the prompt message to the user.
        cout << Message << endl;
        // Read the number entered by the user.
        cin >> Number;
    } while (Number <= 0);  // Continue prompting if the number is not positive.

    return Number;  // Return the valid positive number.
}

// Function: CheckPrime
// Purpose: Checks if a given number is prime.
// It does this by trying to divide the number by all integers from 2 up to half of the number.
enPrimNotPrime CheckPrime(int Number)
{
    // Calculate half of the number. 
    // The use of round() here ensures we work with an approximate half even though integer division could be used.
    int M = round(Number / 2);

    // Loop from 2 to M to check if any number divides Number evenly.
    for (int Counter = 2; Counter <= M; Counter++)
    {
        // If Number is divisible by Counter (remainder is 0), then it is not prime.
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;  // Return NotPrime if a divisor is found.
    }

    // If no divisors were found, the number is prime.
    return enPrimNotPrime::Prime;
}

// Function: PrintPrimeNumbersFrom1ToN
// Purpose: Prints all the prime numbers from 1 up to a given number.
// It first displays a header message and then checks each number in the range.
void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\n";  // Print a newline for better formatting.
    // Display a header indicating the range being considered.
    cout << "Prime Numbers from " << 1 << " To " << Number;
    cout << " are : " << endl;

    // Loop through all numbers from 1 to Number.
    for (int i = 1; i <= Number; i++)
    {
        // Use the CheckPrime function to determine if the current number i is prime.
        if (CheckPrime(i) == enPrimNotPrime::Prime)
        {
            // If i is prime, print it on a new line.
            cout << i << endl;
        }
    }
}

// Main function: Program's entry point.
int main()
{
    // Prompt the user to enter a positive number by calling ReadPositiveNumber,
    // then print all prime numbers from 1 up to that number.
    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Please enter a positive number ? "));

    // Return 0 to indicate that the program executed successfully.
    return 0;
}