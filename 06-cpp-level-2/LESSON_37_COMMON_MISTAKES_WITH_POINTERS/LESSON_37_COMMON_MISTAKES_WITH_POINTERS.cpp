#include <iostream>
using namespace std;
int main()
{
	int x, * p;
	p = &x;
	*p = x;
}