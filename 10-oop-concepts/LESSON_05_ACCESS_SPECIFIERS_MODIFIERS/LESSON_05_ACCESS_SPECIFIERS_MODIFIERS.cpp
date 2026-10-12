#include <iostream>

using namespace std;
class clsPerson
{
private:
    // Accessible only inside this class
    int Variable1 = 5;

    int Function1()
    {
        return 40;
    }

protected:
    // Accessible only inside this class and all inheriting classes
    int Variable2 = 100;

    int Function2()
    {
        return 50;
    }

public:
    // Accessible to everyone: outside, inside, and in inheriting classes
    string FirstName;
    string LastName;

    string FullName()
    {
        return FirstName + " " + LastName;
    }

    float Function3()
    {
        return Function1() * Variable1 * Variable2;
    }
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Adam";
    Person1.LastName = "EL FENNYCH";

    cout << "Person1: " << Person1.FullName() << endl;
    cout << Person1.Function3() << endl;

    return 0;
}