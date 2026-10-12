// ProgrammingAdivces.com
// Mohammed Abu-Hadhoud
#include <iostream>
using namespace std;
#include <cstdlib>
#include <string>

class clsPerson
{
    class clsAddress
    {
      public:
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;

        void Print()
        {
            cout << "\nAddress:\n";
            cout << AddressLine1 << endl;
            cout << AddressLine2 << endl;
            cout << City << endl;
            cout << Country << endl;
        }
    };

  public:
    string FullName;
    clsAddress Address;

    clsPerson()
    {
        FullName = "Mohammed Abu-Hadhoud";
        Address.AddressLine1 = "Building 10";
        Address.AddressLine2 = "Queen Rania Street";
        Address.City = "Amman";
        Address.Country = "Jordan";
    }
};

int main()

{
    clsPerson Person1;

    Person1.Address.Print();

    system("pause>0");
    return 0;
}