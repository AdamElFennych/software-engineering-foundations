#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    char x;
    char w;

    x = toupper('a');
    w = tolower('A');

    cout << "converting a to A: " << x << endl;
    cout << "converting A to a: " << w << endl;

    // isupper('A') checks if the character is uppercase (A-Z).
    // It returns a non-zero value if true, and 0 if false.
    cout << "isupper('A') " << isupper('A') << endl;

    // islower('A') checks if the character is lowercase (a-z).
    // It returns a non-zero value if true, and 0 if false.
    cout << "islower('A') " << islower('A') << endl;

    // isdigit('A') checks if the character is a digit (0-9).
    // It returns a non-zero value if true, and 0 if false.
    cout << "isdigit('A') " << isdigit('A') << endl;

    // ispunct('A') checks if the character is a punctuation mark.
    // It returns a non-zero value if true, and 0 if false.
    cout << "ispunct('A') " << ispunct('A') << endl;

    return 0;
}