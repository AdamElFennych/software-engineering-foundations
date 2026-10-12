#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{
    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

  public:
    string FullName;
    stAddress Address;

    clsPerson()
    {
        FullName = "Mohammed Abu-Hadhoud";
        Address.AddressLine1 = "Building 10";
        Address.AddressLine2 = "Queen Rania Street";
        Address.City = "Amman";
        Address.Country = "Jordan";
    }

    void PrintAddress()
    {
        cout << "\nAddress:\n";
        cout << Address.AddressLine1 << endl;
        cout << Address.AddressLine2 << endl;
        cout << Address.City << endl;
        cout << Address.Country << endl;
    }
};

int main()

{
    clsPerson Person1;
    Person1.PrintAddress();

    system("pause>0");
    return 0;
}