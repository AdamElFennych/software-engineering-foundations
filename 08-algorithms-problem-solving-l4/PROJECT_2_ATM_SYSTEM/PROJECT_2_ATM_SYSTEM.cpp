#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const string ClientsFileName = "Clients.txt";
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
enum enATMMainMenueOptions
{
    eQuickWithdraw = 1,
    eNormalWithdraw = 2,
    eDeposit = 3,
    eCheckBalance = 4,
    eLogout = 5
};
enum enQuickWithdrawAmount
{
    e20 = 1,
    e50 = 2,
    e100 = 3,
    e200 = 4,
    e400 = 5,
    e600 = 6,
    e800 = 7,
    e1000 = 8,
    eExit = 9
};
stClient CurrentClient;
void ShowATMMainMenue(vector<stClient>& vClients);
void ShowQuickWithdrawScreen(vector<stClient>& vClients);
void ShowNormalWithdrawScreen(vector<stClient>& vClients);
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length()); /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}
stClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double

    return Client;
}
string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}
vector<stClient> LoadCleintsDataFromFile(string FileName)
{
    vector<stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}
vector<stClient> SaveCleintsDataToFile(string FileName, vector<stClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (const stClient& C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}
bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, const vector<stClient>& vClient,
                                         stClient& Client)
{
    for (const stClient& C : vClient)
    {
        if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
        {
            Client = C;
            return true;
        }
    }
    return false;
}
bool LoadClientInfo(string Username, string Password, const vector<stClient>& vClients)
{
    if (FindClientByAccountNumberAndPinCode(Username, Password, vClients, CurrentClient))
        return true;
    else
        return false;
}
short ReadATMMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 5]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}
short ReadQucikWithdrawOption()
{
    short Choice = 0;

    while (Choice < 1 || Choice > 9)
    {
        cout << "Choose what to withdraw from [1] to [9] ? ";
        cin >> Choice;
    }

    return Choice;
}
short GetQuickWithdrawAmount(enQuickWithdrawAmount AmountOption)
{
    switch (AmountOption)
    {
    case enQuickWithdrawAmount::e20:
        return 20;
    case enQuickWithdrawAmount::e50:
        return 50;
    case enQuickWithdrawAmount::e100:
        return 100;
    case enQuickWithdrawAmount::e200:
        return 200;
    case enQuickWithdrawAmount::e400:
        return 400;
    case enQuickWithdrawAmount::e600:
        return 600;
    case enQuickWithdrawAmount::e800:
        return 800;
    case enQuickWithdrawAmount::e1000:
        return 1000;
    default:
        return 0;
    }
}
bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<stClient>& vClients)
{
    char Answer = 'n';
    cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        for (stClient& C : vClients)
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientsFileName, vClients);

                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance;

                return true;
            }
        }

        return false;
    }
    return false;
}
void GoBackToATMMainMenue(vector<stClient>& vClients)
{
    cout << "\n\nPress any key to go back to ATM Main Menue...";
    system("pause>0");
    ShowATMMainMenue(vClients);
}
int returnValidAmnountMultipleOfx(vector<stClient>& vClients, short Multiple = 5)
{
    int WithdrawAmount = 0;
    do
    {
        cout << "Enter an amount multiple of " << Multiple << "'s ? ";
        cin >> WithdrawAmount;
    } while (!(WithdrawAmount % Multiple == 0));
    if (WithdrawAmount > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "\nPress any key to continue...";
        system("pause>0");
        return 0;
    }
    return WithdrawAmount;
}
void PerformQuickWithdrawOption(short Choice, vector<stClient>& vClients)
{
    if (Choice == 9)
        return;

    short WithdrawAmount = GetQuickWithdrawAmount((enQuickWithdrawAmount)Choice);

    if (WithdrawAmount > CurrentClient.AccountBalance)
    {
        cout << "\nThe amount exceeds your balance, make another choice.\n";
        cout << "\nPress any key to continue...";
        system("pause>0");
        ShowQuickWithdrawScreen(vClients);
        return;
    }
    if (DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount * -1, vClients))
        CurrentClient.AccountBalance -= WithdrawAmount;
}
void ShowChechBalanceScreen()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tCheck Balance Screen\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;
}
void ShowDepositBalanceScreen(vector<stClient>& vClients)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tDeposit Screen\n";
    cout << "===========================================\n";
    int WithdrawAmount = 0;
    do
    {
        cout << "Enter a positive Deposit Amount? ";
        cin >> WithdrawAmount;
    } while (WithdrawAmount <= 0);
    if (DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount, vClients))
        CurrentClient.AccountBalance += WithdrawAmount;
}
void ShowNormalWithdrawScreen(vector<stClient>& vClients)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tNormal Withdraw Screen\n";
    cout << "===========================================\n";
    int WithdrawAmount = returnValidAmnountMultipleOfx(vClients);
    if (DepositBalanceToClientByAccountNumber(CurrentClient.AccountNumber, WithdrawAmount * -1, vClients))
        CurrentClient.AccountBalance -= WithdrawAmount;
}
void ShowQuickWithdrawScreen(vector<stClient>& vClients)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tQuick Withdraw\n";
    cout << "===========================================\n";
    cout << "\t[1] 20\t\t[2] 50\n";
    cout << "\t[3] 100\t\t[4] 200\n";
    cout << "\t[5] 400\t\t[6] 600\n";
    cout << "\t[7] 800\t\t[8] 1000\n";
    cout << "\t[9] Exit\n";
    cout << "===========================================\n";
    cout << "Your Balance is " << CurrentClient.AccountBalance << endl;
    PerformQuickWithdrawOption(ReadQucikWithdrawOption(), vClients);
}
void PerfromATmMainMenueOption(enATMMainMenueOptions ATMMainMenueOptions, vector<stClient>& vClients)
{
    switch (ATMMainMenueOptions)
    {
    case enATMMainMenueOptions::eQuickWithdraw:
        system("cls");
        ShowQuickWithdrawScreen(vClients);
        GoBackToATMMainMenue(vClients);
        break;
    case enATMMainMenueOptions::eNormalWithdraw:
        system("cls");
        ShowNormalWithdrawScreen(vClients);
        GoBackToATMMainMenue(vClients);
        break;

    case enATMMainMenueOptions::eDeposit:
        system("cls");
        ShowDepositBalanceScreen(vClients);
        GoBackToATMMainMenue(vClients);
        break;

    case enATMMainMenueOptions::eCheckBalance:
        system("cls");
        ShowChechBalanceScreen();
        GoBackToATMMainMenue(vClients);
        break;
    case enATMMainMenueOptions::eLogout:
        system("Cls");
        break;
    }
}
void ShowATMMainMenue(vector<stClient>& vClients)
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tATM Main Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Quick Withdraw.\n";
    cout << "\t[2] Normal Withdraw.\n";
    cout << "\t[3] Deposit.\n";
    cout << "\t[4] Chech Balance.\n";
    cout << "\t[5] Logout.\n";
    cout << "===========================================\n";
    PerfromATmMainMenueOption((enATMMainMenueOptions)ReadATMMainMenueOption(), vClients);
}
void Login()
{
    bool LoginFaild = false;
    vector<stClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber, PinCode;
    do
    {
        system("cls");

        cout << "\n---------------------------------\n";
        cout << "\tLogin Screen";
        cout << "\n---------------------------------\n";

        if (LoginFaild)
        {
            cout << "Invlaid Account Number/PinCode!\n";
        }

        cout << "Enter Account Number? ";
        cin >> AccountNumber;

        cout << "Enter Pin? ";
        cin >> PinCode;

        LoginFaild = !LoadClientInfo(AccountNumber, PinCode, vClients);

    } while (LoginFaild);

    ShowATMMainMenue(vClients);
}

int main()

{
    while (true)
    {
        Login();
    }

    system("pause>0");
    return 0;
}