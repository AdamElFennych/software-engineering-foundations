#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vNumbers;

    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);
    //cout << vNumbers.size() << endl;how many elements in the stack
    //vNumbers.clear();clear the stack
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();
    vNumbers.pop_back();

    cout << "Numbers Vector: \n\n";

    // ranged loop
    for (int& Number : vNumbers) {
        cout << Number << endl;
    }

    cout << endl;

    return 0;
}