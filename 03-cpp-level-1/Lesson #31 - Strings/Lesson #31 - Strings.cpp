#include <iostream>
#include <string>
using namespace std;
int x = 10;
void printString()
{
	cout << "Hello, World!" << endl; // Print a simple message
}
int area()
{
	int length = 5;
	int width = 10;
	return length * width; // Calculate area of a rectangle
}
int area(int &lengeth, int &width)
{
	return lengeth * width; // Calculate area with given parameters
}
int main()
{
	string str1 = "ABXDEFJHIGKLMNOPQRSTUVWXYZ";
	cout << str1.length() << endl; // Output: 26
	cout << str1[10] << endl; // Output: H
	cout << str1.back() << endl; // Output: Z
	string str2;
	cout << "Enter a string: ";
	//cin >> str2; // Read a single word (up to the first space)
	getline(cin, str2); // Read a line of text including spaces
	cout << "You entered: " << str2 << endl; // Output the entered string
	printString(); // Call the function to print a message
	int lengeth = 5, width = 10;
	cout << "area = " << area(lengeth, width) << endl; // Output the area using the function with parameters
	cout << "the global value of x : " << ::x + 10 << endl;
	cout << "enter global variable " << endl;
	cin >> ::x;
	cout << ::x << endl;
	string name = "adam el fennych";
	cout << name[0] << endl;
	cout << name[12] << endl;
	int x[5] = { 1 , 2 , 3 , 4 ,5 };
	cout << x[0] << endl;
}