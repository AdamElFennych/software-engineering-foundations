#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for using std::string.
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for time() to seed the random generator.

using namespace std;  // Use the standard namespace to avoid using std:: prefix for standard library functions.

// Enumeration: enCharType
// Purpose: Defines various character types for generating random characters.
// The enumeration values represent different categories:
//   - SamallLetter: Lowercase letters (though the case label is misspelled, it represents lowercase).
//   - CapitalLetter: Uppercase letters.
//   - SpecialCharacter: Special characters.
//   - Digit: Numeric digits.
enum enCharType { SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

// Function: RandomNumber
// Purpose: Generates a random integer within a specified range [From, To] (inclusive).
// Parameters:
//   - From: The lower bound of the random range.
//   - To: The upper bound of the random range.
// Returns: A random integer between From and To.
int RandomNumber(int From, int To)
{
    // Generate a random number between 0 and (To - From), then add From to shift the range.
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

// Function: GetRandomCharacter
// Purpose: Returns a random character based on the specified character type.
// Parameters:
//   - CharType: An enCharType value indicating which type of character to generate.
// Returns: A random character from the given category.
char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SamallLetter:
    {
        // Generate a random lowercase letter (ASCII: 97 'a' to 122 'z').
        return char(RandomNumber(97, 122));
        break; // break is not necessary after return.
    }
    case enCharType::CapitalLetter:
    {
        // Generate a random uppercase letter (ASCII: 65 'A' to 90 'Z').
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        // Generate a random special character (ASCII: 33 '!' to 47 '/').
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        // Generate a random digit (ASCII: 48 '0' to 57 '9').
        return char(RandomNumber(48, 57));
        break;
    }
    }
    // If no valid type is provided, return a null character.
    return '\0';
}

// Function: ReadPositiveNumber
// Purpose: Prompts the user to enter a positive number and reads the input.
// Parameters:
//   - Message: A string containing the prompt to display.
// Returns: A positive integer entered by the user.
int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl; // Display the prompt message.
        cin >> Number;           // Read the number from the user.
    } while (Number <= 0);       // Continue prompting until a positive number is entered.
    return Number;
}

// Function: GenerateWord
// Purpose: Generates a random word of a specified length using characters from a given type.
// Parameters:
//   - CharType: The type of character to use (e.g., CapitalLetter).
//   - Length: The number of characters in the word.
// Returns: A string containing the generated word.
string GenerateWord(enCharType CharType, short Length)
{
    string Word;  // Initialize an empty string to build the word.

    // Loop for the number of characters specified by Length.
    for (int i = 1; i <= Length; i++)
    {
        // Append a random character of the specified type to the word.
        Word = Word + GetRandomCharacter(CharType);
    }
    return Word;
}

// Function: GenerateKey
// Purpose: Generates a key string composed of four groups of 4 uppercase letters separated by hyphens.
// Returns: A string representing the generated key.
string GenerateKey()
{
    string Key = "";  // Initialize an empty key string.

    // Concatenate four groups of 4 random uppercase letters, separated by hyphens.
    Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenerateWord(enCharType::CapitalLetter, 4);

    return Key;
}

// Function: GenerateKeys
// Purpose: Generates and prints a specified number of keys.
// Parameters:
//   - NumberOfKeys: The total number of keys to generate.
void GenerateKeys(short NumberOfKeys)
{
    // Loop from 1 to NumberOfKeys.
    for (int i = 1; i <= NumberOfKeys; i++)
    {
        // Print the current key number and the generated key.
        cout << "Key [" << i << "] : ";
        cout << GenerateKey() << endl;
    }
}

// Main function: Program entry point.
int main()
{
    // Seed the random number generator with the current time to ensure different results on each run.
    srand((unsigned)time(NULL));

    // Prompt the user to enter how many keys to generate, then generate that many keys.
    GenerateKeys(ReadPositiveNumber("Pleaes enter how many keys to generate? \n "));

    return 0;  // Return 0 to indicate successful program execution.
}