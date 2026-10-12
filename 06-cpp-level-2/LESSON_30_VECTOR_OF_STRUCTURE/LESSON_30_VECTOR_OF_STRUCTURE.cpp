#include <iostream>
#include <vector>
using namespace std;
struct stEmployee
{
    string name;
    string lastname;
    int salary;
};
int main()
{
    vector <stEmployee> vEmployee;
    stEmployee tempEmployee;
    tempEmployee.name = "adam";
    tempEmployee.lastname = "el fennych";
    tempEmployee.salary = 5000;
    vEmployee.push_back(tempEmployee);
    tempEmployee.name = "ares";
    tempEmployee.lastname = "fes";
    tempEmployee.salary = 1000;
    vEmployee.push_back(tempEmployee);
    tempEmployee.name = "adare";
    tempEmployee.lastname = "fersa";
    tempEmployee.salary = 3000;
    vEmployee.push_back(tempEmployee);
    cout << "Employees Vector: \n\n";
    for (stEmployee& Employee : vEmployee)
    {
        cout << "FirstName: " << Employee.name << endl;
        cout << "LastName : " << Employee.lastname << endl;
        cout << "Salary   : " << Employee.salary << endl << endl;
    }
    return 0;
}
