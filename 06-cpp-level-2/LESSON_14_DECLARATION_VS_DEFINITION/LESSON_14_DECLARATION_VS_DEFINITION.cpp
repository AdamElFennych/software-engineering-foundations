#include <iostream>
using namespace std;
// function declaration
void add(int, int);
int main()
{
    add(12, 10);
    return 0;
}
//function definition
void add(int a, int b)
{
    cout << (a + b);
}