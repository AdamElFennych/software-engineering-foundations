// #Object - Oriented Programming(OOP)
// Memory Model Reference
//
//    1. Class vs.Object Definition : -When defining an Object from a Class,
//    you can instantiate(create) multiple Objects from that single Class.
//
// 2. Class Composition:
//   - A Class is composed of Members.
//   - These Members are divided into:
//     A. Data Members (Variables/Attributes)
//     B. Function Members (Methods/Behaviors)
//
// 3. Memory Allocation (The Critical Distinction):
//   - Data Members:
//     For every Object created, a unique and distinct space is allocated
//     in Memory to store its specific Data Members.
//   - Function Members:
//     Function Members exist in a single location in Memory. No matter how
//     many Objects you create, they all share this one common place for code.
//
// 4. Data Separation:
//   - The Object concept ensures data separation in Memory.
//   - Example: If you have Person1 and Person2, the Object structure
//     separates the data of Person1 from Person2 in Memory, even though
//     they come from the same Class.
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