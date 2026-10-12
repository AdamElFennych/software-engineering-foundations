#include <iostream>
using namespace std;
class clsPerson
{
    int x;

public:
    string FirsName;
    string LastName;
    string FullName()
    {
        return FirsName + " " + LastName;
    }
};
int main()
{
    clsPerson Person1;
    Person1.FirsName = "Adam";
    Person1.LastName = "EL FENNYCH";
    cout << Person1.FullName();
}