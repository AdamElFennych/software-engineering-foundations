#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int& x = a;
    cout << &a << endl;
    cout << &x << endl;
    x = 20;
    cout << a << endl;
    cout << x << endl;
    return 0;
}