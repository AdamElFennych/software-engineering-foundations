#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S1 = "My Name is Mohammed Abu-Hadhoud, I Love Programming.";
    cout << S1.length() << endl;
    cout << S1.at(3) << endl;
    S1.append(" @ProgrammingAdvices");
    cout << S1 << endl;
    S1.insert(7, " Ali ");
    cout << S1 << endl;
    cout << S1.substr(16, 8) << endl;
    S1.push_back('x');
    cout << S1 << endl;
    S1.pop_back();
    cout << S1 << endl;
    cout << S1.find("Ali") << endl;
    cout << S1.find("ali") << endl;
    if (S1.find("ali") == S1.npos)
    {
        cout << "ali is not found";
    }
    S1.clear();
    cout << S1 << endl;

}