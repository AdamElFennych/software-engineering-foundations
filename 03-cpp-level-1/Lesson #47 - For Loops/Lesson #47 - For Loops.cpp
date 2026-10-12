#include <iostream>
#include <string>


using namespace std;


struct strInfo
{
    string FirstName;
    string LastName;
    int Age;
    string Phone;
};




void ReadInfo(strInfo& Info)
{
    
    cout << "Please enter FirstName?\n";
    cin >> Info.FirstName;


    cout << "Please enter LastName?\n";
    cin >> Info.LastName;


    cout << "Please enter Age?\n";
    cin >> Info.Age;


    cout << "Please enter Phone?\n";
    cin >> Info.Phone;


}


void PrintInfo(strInfo Info)
{


    cout << "\n**********************************\n";


    cout << "FirstName: " << Info.FirstName << endl;
    cout << "LastName: " << Info.LastName << endl;
    cout << "Age: " << Info.Age << endl;
    cout << "Phone: " << Info.Phone << endl;


    cout << "\n**********************************\n";




}



void ReadPersonsInfo(strInfo Persons[100],int &length)
{
    cout << "how many persons?\n";
    cin >> length;
    for (int i = 0; i <= length-1; i++)
    {
        cout << "Please enter person " << i + 1 << " info:\n\n";
        ReadInfo(Persons[i]);
    }
}



void PrintPersonsInfo(strInfo Persons[100],int length)
{
    cout << "\n**********************************\n";


    for (int i = 0; i <= length - 1; i++)
    {
        cout << "person " << i + 1 << " info:\n";
        PrintInfo(Persons[i]);
    }


}



int main()
{


    strInfo Persons[100];
    int length;

    ReadPersonsInfo(Persons,length);
    PrintPersonsInfo(Persons,length);

    return 0;
}
