#include <iostream>
#include <string>
using namespace std;
enum enColor
{
    red,
    black,
    white,
    grean,
    yellow,
    brown,
    pink,
};

int main()
{
    int array[5] = { 0 , 1 , 2 , 3 , 4 };
    string student[3] = { "adam" , "salah" ," omar " };
    cout << student[0] << endl;
    cout << array[1];
    int x;
    enColor color;
    cin >> x;
    color = enColor(x);
    if (color == enColor::black)
    {
        cout << "it is black\n";
    }
    else if (color == enColor::brown)
    {
        cout << "it is brown\n";
    }
    switch (color)
    {
    case 1:
        cout << "it is brown";
        break;
    case enColor::pink:
        cout << "it is pink\n";
        break;

    default:
        cout << "error";
    }
}
