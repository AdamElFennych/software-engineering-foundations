#include <iostream>
using namespace std;
class clsPerson
{
    // Members
public: // access specifier
    // data members (attributes)
    string FirsName;
    string LastName;
    // method members (functions)
    string FullName()
    {
        return FirsName + " " + LastName;
    }
};
int main()
{
    // Create an object from the class
    clsPerson Person1;
    // Set values to data members
    Person1.FirsName = "Adam";
    Person1.LastName = "EL FENNYCH";
    // Call method member
    cout << Person1.FullName();
}