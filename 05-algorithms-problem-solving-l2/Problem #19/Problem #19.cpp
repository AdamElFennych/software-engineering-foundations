#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string to use std::string (though not used in this example).
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for the time() function.

using namespace std;  // Use the standard namespace to avoid prefixing std:: to standard functions.

// Function: RandomNumber
// Purpose: Generates a random integer between the specified range [From, To].
// Parameters:
//    From - the lower bound of the range.
//    To   - the upper bound of the range.
// Returns: A random integer between From and To (inclusive).
int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From) using rand(),
    // then add From to shift the range to [From, To].
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}

int main() {
    // Seed the random number generator with the current time.
    // This ensures that we get a different sequence of random numbers on each run.
    srand((unsigned)time(NULL));

    // Call RandomNumber three times to generate random numbers between 1 and 10,
    // and output each number on a new line.
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;
    cout << RandomNumber(1, 10) << endl;

    return 0;  // Return 0 to indicate successful execution.
}