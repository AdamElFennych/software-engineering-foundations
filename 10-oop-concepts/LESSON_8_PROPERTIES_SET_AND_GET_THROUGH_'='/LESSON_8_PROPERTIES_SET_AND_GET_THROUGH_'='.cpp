#include <iostream>

using namespace std;

class clsPerson
{
private:
    string _FirstName;

public:
    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
};

int main()
{
    clsPerson Person1;

    // Standard method access
    Person1.SetFirstName("Mohammed");
    cout << Person1.GetFirstName() << endl;

    // Property access (using __declspec)
    Person1.FirstName = "Mohammed";
    cout << Person1.FirstName << endl;

    system("pause>0");

    return 0;
}