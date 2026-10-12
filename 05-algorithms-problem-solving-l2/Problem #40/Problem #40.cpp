#include <iostream>   // Include iostream for input/output operations.
using namespace std;  // Use the standard namespace to avoid prefixing std:: to common functions.

// Function: FillArray
// Purpose: Initializes the source array with predefined numbers, some of which are duplicates.
// Parameters:
//   - arr: The source array to be filled (with capacity of 100).
//   - arrLength: A reference variable to store the number of elements filled in the array.
void FillArray(int arr[100], int& arrLength)
{
    arrLength = 10;  // Set the array length to 10 elements.

    // Manually assign values to the array elements.
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}

// Function: PrintArray
// Purpose: Prints the elements of an integer array, separated by spaces.
// Parameters:
//   - arr: The array to be printed.
//   - arrLength: The number of elements in the array.
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";  // Print each element followed by a space.
    cout << "\n";  // Move to the next line after printing the array.
}

// Function: FindNumberPositionInArray
// Purpose: Searches for a given number in an array and returns its index if found.
// Parameters:
//   - Number: The number to search for.
//   - arr: The array in which to search.
//   - arrLength: The number of elements in the array.
// Returns: The index of the number if found; otherwise, returns -1.
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;  // Return the index as soon as the number is found.
    }
    // If the number is not found, return -1.
    return -1;
}

// Function: IsNumberInArray
// Purpose: Determines if a given number exists in an array.
// Parameters:
//   - Number: The number to search for.
//   - arr: The array in which to search.
//   - arrLength: The number of elements in the array.
// Returns: true if the number is found; false otherwise.
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

// Function: AddArrayElement
// Purpose: Adds a new element to the end of an array and updates its length.
// Parameters:
//   - Number: The number to add.
//   - arr: The array to which the number will be added.
//   - arrLength: A reference variable representing the current number of elements in the array.
// Behavior: Increments arrLength and places the new element at the last index.
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;             // Increase the array length by 1.
    arr[arrLength - 1] = Number;  // Place the new element at the new last index.
}

// Function: CopyDistinctNumbersToArray
// Purpose: Copies only distinct (non-duplicate) numbers from the source array to the destination array.
// Parameters:
//   - arrSource: The source array from which numbers will be copied.
//   - arrDestination: The destination array where distinct numbers will be stored.
//   - SourceLength: The number of elements in the source array.
//   - DestinationLength: A reference variable that tracks the number of elements in the destination array.
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
    // Loop through each element in the source array.
    for (int i = 0; i < SourceLength; i++)
    {
        // If the current element is not already in the destination array...
        if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
        {
            // ...then add it to the destination array.
            AddArrayElement(arrSource[i], arrDestination, DestinationLength);
        }
    }
}
int main()
{
    int arr1[100] ,Length;
    FillArray(arr1, Length);
    int Length2 = 0;
    int arr2[100];
    cout << "Array 1 elements:\n";
    PrintArray(arr1, Length);
    CopyDistinctNumbersToArray(arr1, arr2, Length, Length2);
    cout << "array 2 elements:\n";
    PrintArray(arr2, Length2);
    cout << Length2 ;
}
