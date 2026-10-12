#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;  // Variable to store the user's input.
    do
    {
        cout << Message << endl;  // Display the prompt message.
        cin >> Number;            // Read the number entered by the user.
    } while (Number <= 0);        // Repeat if the number is not positive.

    return Number;  // Return the valid positive number.
}
int ReverseNumber(int Number)
{
    int Remainder = 0;
    int Revers = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Revers = Revers * 10 + Remainder;
    }
    return Revers;
}
bool IsPalindromeNumber(int Number)
{
    return Number == ReverseNumber(Number);
}
int main()
{
    if (IsPalindromeNumber(ReadPositiveNumber("Please enter a positive number ? \n")))
        cout << "\nYes , it is a Palindrome number.\n";
    else
        cout << "\nNo , it is NOt a Palindrome number.\n";
    return 0;

}

