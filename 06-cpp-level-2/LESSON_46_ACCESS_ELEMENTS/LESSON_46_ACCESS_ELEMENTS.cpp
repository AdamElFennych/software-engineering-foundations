#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vNum{ 1,2,3,4,5 };
    cout << "element at index 1 " << vNum.at(0) << endl;
    cout << "element at index 1 " << vNum[0] << endl;
}
