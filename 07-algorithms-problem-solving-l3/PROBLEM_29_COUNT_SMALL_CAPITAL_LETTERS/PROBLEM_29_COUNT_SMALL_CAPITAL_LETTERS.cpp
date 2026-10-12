/*
ProgrammingAdvices.com
© Copyright 2022
Problem # 29/3 Solution Using C++
*/

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

// Problem #23
string ReadString() {
	string S1 = " ";
	cout << "Please Enter your string ? \n";
	getline(cin, S1);
	return S1;
}

// Problem #29
short CountCapitalLetters(string S1) {
	short Counter = 0;
	for (int i = 0; i < S1.length(); i++) {
		if (isupper(S1[i]))
			Counter++;
	}
	return Counter;
}

short CountSmallLetters(string S1) {
	short Counter = 0;
	for (int i = 0; i < S1.length(); i++) {
		// islower returns true if the letter is small, otherwise false
		if (islower(S1[i]))
			Counter++;
	}
	return Counter;
}

// Solution using another method: Combining Functions together
enum enWhatToCount {
	SmallLetters = 0, CapitalLetters = 1, All = 3
};

short CountLetters(string S5, enWhatToCount WhatToCount = enWhatToCount::All) {
	// If no comparison option is specified, it automatically returns All
	if (WhatToCount == enWhatToCount::All) {
		return S5.length();
	}
	short Counter = 0;
	for (int i = 0; i < S5.length(); i++) {
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S5[i]))
			Counter++;
		if (WhatToCount == enWhatToCount::SmallLetters && islower(S5[i]))
			Counter++;
	}
	return Counter;
}

int main() {
	// Problem #29
	string S5 = ReadString();
	cout << "\nString Length = " << S5.length();
	cout << "\nCapital Letters Count = " << CountCapitalLetters(S5);
	cout << "\nSmall Letters Count = " << CountSmallLetters(S5);

	cout << "\n\nMethod \n";
	cout << "\nString Length = " << CountLetters(S5);
	cout << "\nCapital Letters Count = " << CountLetters(S5, enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count = " << CountLetters(S5, enWhatToCount::SmallLetters);
	system("pause>0");
}