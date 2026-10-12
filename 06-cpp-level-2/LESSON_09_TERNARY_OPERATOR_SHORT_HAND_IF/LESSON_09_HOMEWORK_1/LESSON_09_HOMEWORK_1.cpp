#include <iostream>
using namespace std;
int main()
{
    int Number = 0;
    string Result;
    Result = (Number == 0) ? "Zero" : ((Number > 0) ? "Positive" : "Negative");
    cout << "Number is " << Result;
}
