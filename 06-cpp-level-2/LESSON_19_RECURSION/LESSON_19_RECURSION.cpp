#include <iostream>
using namespace std;
int Pow(int Base, int Power)
{
	if (Power==0)
		return 1;
	else
	{
		return (Base * Pow(Base, Power - 1));
	}
}
int main()
{
	cout << Pow(3, 6) << endl;

}
