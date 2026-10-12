#include <iostream>
using namespace std;

struct stEmployee {
    string FirstName;
    string LastName;
    int Salary;
};

int main() {
    stEmployee Employee1, * ptr;
    Employee1.FirstName = "Mohammed Abu-Hadhoude";
    Employee1.Salary = 5000;

    cout << Employee1.FirstName << endl;
    cout << Employee1.Salary << endl;

    ptr = &Employee1;

    cout << "\nUsing Pointer:\n";
    cout << ptr->FirstName << endl;
    cout << ptr->Salary << endl;

    return 0;
}
