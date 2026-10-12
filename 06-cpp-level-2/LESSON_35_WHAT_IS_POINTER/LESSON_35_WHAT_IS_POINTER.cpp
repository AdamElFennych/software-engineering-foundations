#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 50;
    cout << "a vaue    = " << a << endl;
    cout << "a address = " << &a << endl;
    int* p = &a;
    p = &b;
    cout << "Pointer Value = " << p;
    cout << endl;
    return 0;
}