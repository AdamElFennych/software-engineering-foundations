#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};
enum enTransactionsMenueOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eShowTotalBalance = 3,
    eShowMainMenue = 4
};

enum enMainMenueOptions
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eShowTransactionsMenue = 6,
    eManageUsers = 7,
    eLogout = 8
};
enum enPermition
{
    eAdmin = -1,
    eListClientsPermission = 1,
    eAddNewClientPermission = 2,
    eDeleteClientPermission = 4,
    eUpdateClientPermission = 8,
    eFindClientPermission = 16,
    eShowTransactionsMenuePermission = 32,
    eManageUsersPermission = 64,
};
enum enManageUsersMenueOptions
{
    eListUsers = 1,
    eAddNewUser = 2,
    eDeleteUser = 3,
    eUpdateUser = 4,
    eFindUser = 5,
    eMainMenue = 6
};
struct stUser
{
    string UserName;
    string Password;
    int Permition;
    bool MarkForDelete = false;
};
stUser CurrentUser;
void ShowMainMenue();
void ShowTransactionsMenue();
void ShowLoginScreen();
void ShowManageUsersMenue();
string ReadString(string Message)
{
    string UserInput = "";

    cout << Message;
    getline(cin >> ws, UserInput);

    return UserInput;
}
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;

    size_t pos = 0;
    string sWord;

    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        S1.erase(0, pos + Delim.length()); // erase until position and move to next word
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;

    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double

    return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName)
{
    vector<sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);
            if (Client.AccountNumber == AccountNumber)
            {
                MyFile.close();
                return true;
            }

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return false;
}

sClient ReadNewClient()
{
    sClient Client;

    cout << "Enter Account Number? ";

    // Usage of std::ws will extract allthe whitespace character
    getline(cin >> ws, Client.AccountNumber);

    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
    {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

vector<sClient> LoadCleintsDataFromFile(string FileName)
{
    vector<sClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        sClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLinetoRecord(Line);

            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

void PrintClientRecordLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientRecordBalanceLine(sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void ShowAllClientsScreen()
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {
            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

void ShowTotalBalances()
{
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (sClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;

            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
}

void PrintClientCard(sClient Client)
{
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number: " << Client.AccountNumber;
    cout << "\nPin Code     : " << Client.PinCode;
    cout << "\nName         : " << Client.Name;
    cout << "\nPhone        : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
{
    for (sClient C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

sClient ChangeClientRecord(string AccountNumber)
{
    sClient Client;

    Client.AccountNumber = AccountNumber;

    cout << "\n\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    for (sClient& C : vClients)
    {
        if (C.AccountNumber == AccountNumber)
        {
            C.MarkForDelete = true;
            return true;
        }
    }

    return false;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (sClient C : vClients)
        {
            if (C.MarkForDelete == false)
            {
                // we only write records that are not marked for delete.
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }

    return vClients;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
}
string ConvertUserToLine(stUser User, string Seperator = "#//#")
{
    string stUserRecord = "";
    stUserRecord += User.UserName + Seperator;
    stUserRecord += User.Password + Seperator;
    stUserRecord += to_string(User.Permition) + Seperator;
    return stUserRecord;
}
void AddNewClient()
{
    sClient Client;
    Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
    char AddMore = 'Y';
    do
    {
        // system("cls");
        cout << "Adding New Client:\n\n";

        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";

        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want delete this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientsFileName, vClients);

            // Refresh Clients
            vClients = LoadCleintsDataFromFile(ClientsFileName);

            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
        return false;
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClientCard(Client);
        cout << "\n\nAre you sure you want update this client? y/n ? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            for (sClient& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveCleintsDataToFile(ClientsFileName, vClients);

            cout << "\n\nClient Updated Successfully.";
            return true;
        }
        return false;
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClients)
{
    char Answer = 'n';

    cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
        for (sClient& C : vClients)
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

string ReadClientAccountNumber()
{
    string AccountNumber = "";

    cout << "\nPlease enter AccountNumber? ";
    cin >> AccountNumber;
    return AccountNumber;
}

void ShowDeleteClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowAddNewClientsScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    AddNewClients();
}

void ShowFindClientScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    sClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number[" << AccountNumber << "] is not found!";
}

void ShowEndScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)";
    cout << "\n-----------------------------------\n";
}

void ShowDepositScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowWithDrawScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    sClient Client;

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        AccountNumber = ReadClientAccountNumber();
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    // Validate that the amount does not exceeds the balance
    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void ShowTotalBalancesScreen()
{
    ShowTotalBalances();
}

void GoBackToMainMenue()
{
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}
void GoBackToTransactionsMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenue();
}
short ReadTransactionsMenueOption()
{
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
{
    switch (TransactionMenueOption)
    {
    case enTransactionsMenueOptions::eDeposit:
    {
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eWithdraw:
    {
        system("cls");
        ShowWithDrawScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eShowTotalBalance:
    {
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenue();
        break;
    }

    case enTransactionsMenueOptions::eShowMainMenue:
    {
        ShowMainMenue();
    }
    }
}

void ShowTransactionsMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "===========================================\n";
    PerfromTranactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}

short ReadMainMenueOption()
{
    cout << "Choose what do you want to do? [1 to 8]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}
void ShowAccessDeniedMessage()
{
    system("cls");
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}
bool CheckAccessRights(enPermition Permission)
{
    if (CurrentUser.Permition == enPermition::eAdmin)
        return true;
    if ((CurrentUser.Permition & Permission) == Permission)
        return true;

    return false;
}
stUser ConvertLinetoUser(string Line, string Seperator = "#//#")
{
    stUser User;
    vector<string> vUserData;

    vUserData = SplitString(Line, Seperator);

    User.UserName = vUserData[0];
    User.Password = vUserData[1];
    User.Permition = stoi(vUserData[2]);

    return User;
}
bool FindUser(const vector<stUser>& vUsers, stUser& User, bool ByPassword = true)
{
    for (const stUser& U : vUsers)
    {
        if (U.UserName == User.UserName)
        {
            if (ByPassword)
            {
                if (U.Password == User.Password)
                {
                    User.Permition = U.Permition;
                    return true;
                }
                return false;
            }
            User.Permition = U.Permition;
            User.Password = U.Password;
            return true;
        }
    }
    return false;
}
vector<stUser> LoadUsersDataFromFile(string FileName)
{
    vector<stUser> vUser;

    fstream MyFile;
    MyFile.open(FileName, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        stUser User;

        while (getline(MyFile, Line))
        {
            User = ConvertLinetoUser(Line);

            vUser.push_back(User);
        }

        MyFile.close();
    }

    return vUser;
}
stUser ReadUsernameAndPassword()
{
    stUser User;
    cout << "Enter Username? ";
    getline(cin >> ws, User.UserName);
    cout << "Enter Password? ";
    cin >> User.Password;
    return User;
}
short ReadManageUsersMenueOption()
{
    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}
void GoBackToManageUsersMenue()
{
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowManageUsersMenue();
}
void PrintUserRecordLine(stUser User)
{
    cout << "| " << setw(25) << left << User.UserName;
    cout << "| " << setw(30) << left << User.Password;
    cout << "| " << setw(12) << left << User.Permition;
}
void ShowListUsersScreen()
{
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);

    cout << "\n\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(25) << "User Name";
    cout << "| " << left << setw(30) << "Password";
    cout << "| " << left << setw(12) << "Permissions";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    for (stUser User : vUsers)
    {
        PrintUserRecordLine(User);
        cout << endl;
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}
bool UserExistsByUsername(string Username, string FileName = UsersFileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open())
    {
        string Line;
        stUser User;
        while (getline(MyFile, Line))
        {
            User = ConvertLinetoUser(Line);
            if (User.UserName == Username)
            {
                MyFile.close();
                return true;
            }
        }
        MyFile.close();
    }

    return false;
}
bool CheckUserAnswer(string Message)
{
    char Answer = 'n';
    cout << Message << " y/n? ";
    cin >> Answer;
    return (tolower(Answer) == 'y');
}
int ReadPermissionsToSet()
{
    int Permissions = 0;
    if (CheckUserAnswer("Do you want to give full access?"))
    {
        return -1;
    }

    cout << "\nDo you want to give access to : \n";
    if (CheckUserAnswer("Show Client List?"))
        Permissions |= enPermition::eListClientsPermission;

    if (CheckUserAnswer("Add New Client?"))
        Permissions |= enPermition::eAddNewClientPermission;

    if (CheckUserAnswer("Delete Client?"))
        Permissions |= enPermition::eDeleteClientPermission;

    if (CheckUserAnswer("Update Client?"))
        Permissions |= enPermition::eUpdateClientPermission;

    if (CheckUserAnswer("Find Client?"))
        Permissions |= enPermition::eFindClientPermission;

    if (CheckUserAnswer("Transactions?"))
        Permissions |= enPermition::eShowTransactionsMenuePermission;

    if (CheckUserAnswer("Manage Users?"))
        Permissions |= enPermition::eManageUsersPermission;

    return Permissions;
}
stUser ReadNewUser()
{
    stUser User;
    cout << "Enter Username? ";
    getline(cin >> ws, User.UserName);
    while (UserExistsByUsername(User.UserName))
    {
        cout << "User With [" << User.UserName << "] already exists,Enter another Username? ";
        getline(cin, User.UserName);
    }
    cout << "Enter Password? ";
    cin >> User.Password;
    User.Permition = ReadPermissionsToSet();
    return User;
}
void AddNewUser()
{
    stUser User = ReadNewUser();
    AddDataLineToFile(UsersFileName, ConvertUserToLine(User));
}
void ShowNewUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New User Screen";
    cout << "\n-----------------------------------\n";
    char Answer = 'n';
    do
    {
        AddNewUser();
        cout << "User Added Successfully,Do you want to add more Users? Y/N? ";
        cin >> Answer;
    } while (tolower(Answer) == 'y');
}
void PrintUserCard(stUser User)
{
    cout << "\nThe following are the user details:\n";
    cout << "-----------------------------------";
    cout << "\nUsername    : " << User.UserName;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permition;
    cout << "\n-----------------------------------\n";
}
bool MarkUserForDeleteByUsername(string Username, vector<stUser>& vUsers)
{
    for (stUser& User : vUsers)
    {
        if (User.UserName == Username)
        {
            User.MarkForDelete = true;
            return true;
        }
    }

    return false;
}
void SaveUsersDataToFile(string FileName, const vector<stUser>& vUsers)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out); // overwrite

    string DataLine;

    if (MyFile.is_open())
    {
        for (const stUser& User : vUsers)
        {
            if (User.MarkForDelete == false)
            {
                DataLine = ConvertUserToLine(User);
                MyFile << DataLine << endl;
            }
        }

        MyFile.close();
    }
}
bool DeleteUserByUsername(string Username, vector<stUser>& vUsers)
{
    stUser User;
    User.UserName = Username;
    if (FindUser(vUsers, User, false))
    {
        PrintUserCard(User);
        char answer;
        cout << "Are you sure you want delete this User? y/n ? ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            MarkUserForDeleteByUsername(Username, vUsers);
            SaveUsersDataToFile(UsersFileName, vUsers);
            vUsers = LoadUsersDataFromFile(UsersFileName);
            cout << "\n\nUser Deleted Successfully.";
            return true;
        }
        return false;
    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
        return false;
    }
}
void ShowDeleteUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tDelete User Screen";
    cout << "\n-----------------------------------\n";
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadString("Please enter Username? ");
    if (Username != "Admin")
    {
        DeleteUserByUsername(Username, vUsers);
    }
    else
    {
        cout << "You can't Delete this User" << endl;
    }
}
void EditUserRecord(stUser& User)
{
    cout << "Enter Password? ";
    cin >> User.Password;
    User.Permition = ReadPermissionsToSet();
}
bool UpdateUserByUsername(string Username, vector<stUser>& vUsers)
{
    stUser User;
    User.UserName = Username;
    if (FindUser(vUsers, User, false))
    {
        PrintUserCard(User);
        char answer;
        cout << "\n\nAre you sure you want update this User? y/n ? ";
        cin >> answer;
        if (tolower(answer) == 'y')
        {
            for (stUser& U : vUsers)
            {
                if (U.UserName == Username)
                {
                    EditUserRecord(U);
                    break;
                }
            }
            SaveUsersDataToFile(UsersFileName, vUsers);
            cout << "\n\nUser Updated Successfully.";
            return true;
        }
        return false;
    }
    else
    {
        cout << "\nUser with Username (" << Username << ") is Not Found!";
        return false;
    }
}
void ShowUpdateUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate User Screen";
    cout << "\n-----------------------------------\n";
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    string Username = ReadString("Please enter Username? ");
    UpdateUserByUsername(Username, vUsers);
}
void ShowFindUserScreen()
{
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate User Screen";
    cout << "\n-----------------------------------\n";
    stUser User;
    User.UserName = ReadString("Please enter Username? ");
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    if (FindUser(vUsers, User, false))
    {
        PrintUserCard(User);
    }
    else
    {
        cout << "\nUser with Username (" << User.UserName << ") is Not Found!";
    }
}
void PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
{
    switch (ManageUsersMenueOption)
    {
    case enManageUsersMenueOptions::eListUsers:
    {
        system("cls");
        ShowListUsersScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eAddNewUser:
    {
        system("cls");
        ShowNewUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eDeleteUser:
    {
        system("cls");
        ShowDeleteUserScreen();
        GoBackToManageUsersMenue();
        break;
    }
    case enManageUsersMenueOptions::eUpdateUser:
    {
        system("cls");
        ShowUpdateUserScreen();
        GoBackToManageUsersMenue();
        break;
    }
    case enManageUsersMenueOptions::eFindUser:
    {
        system("cls");
        ShowFindUserScreen();
        GoBackToManageUsersMenue();
        break;
    }

    case enManageUsersMenueOptions::eMainMenue:
    {
        ShowMainMenue();
    }
    }
}
void ShowManageUsersMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\tManage Users Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] List Users.\n";
    cout << "\t[2] Add New User.\n";
    cout << "\t[3] Delete User.\n";
    cout << "\t[4] Update User.\n";
    cout << "\t[5] Find User.\n";
    cout << "\t[6] Main Menue.\n";
    cout << "===========================================\n";
    PerfromManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
}

void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
    switch (MainMenueOption)
    {
    case enMainMenueOptions::eListClients:
    {
        system("cls");
        if (CheckAccessRights(enPermition::eListClientsPermission))
        {
            ShowAllClientsScreen();
        }
        else
        {
            ShowAccessDeniedMessage();
        }

        GoBackToMainMenue();
        break;
    }
    case enMainMenueOptions::eAddNewClient:
        system("cls");

        if (CheckAccessRights(enPermition::eAddNewClientPermission))
        {
            ShowAddNewClientsScreen();
        }
        else
        {
            ShowAccessDeniedMessage();
        }
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eDeleteClient:
        system("cls");
        if (CheckAccessRights(enPermition::eDeleteClientPermission))
        {
            ShowDeleteClientScreen();
        }
        else
        {
            ShowAccessDeniedMessage();
        }

        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eUpdateClient:
        system("cls");
        if (CheckAccessRights(enPermition::eUpdateClientPermission))
        {
            ShowUpdateClientScreen();
        }
        else
        {
            ShowAccessDeniedMessage();
        }

        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eFindClient:
        system("cls");

        if (CheckAccessRights(enPermition::eFindClientPermission))
        {
            ShowFindClientScreen();
        }
        else
        {
            ShowAccessDeniedMessage();
        }
        GoBackToMainMenue();
        break;

    case enMainMenueOptions::eShowTransactionsMenue:
        system("cls");
        if (CheckAccessRights(enPermition::eShowTransactionsMenuePermission))
        {
            ShowTransactionsMenue();
        }
        else
        {
            ShowAccessDeniedMessage();
        }
        break;
    case enMainMenueOptions::eManageUsers:
        system("cls");
        if (CheckAccessRights(enPermition::eManageUsersPermission))
        {
            ShowManageUsersMenue();
        }
        else
        {
            ShowAccessDeniedMessage();
        }
        break;
    case enMainMenueOptions::eLogout:
        system("cls");
        break;
    }
}

void ShowMainMenue()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menue Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Manage Users.\n";
    cout << "\t[8] Logout.\n";
    cout << "===========================================\n";
    PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}

void ShowLoginDraw()
{
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tLogin Screen\n";
    cout << "===========================================\n";
}
void ShowLoginScreen()
{
    system("cls");
    vector<stUser> vUsers = LoadUsersDataFromFile(UsersFileName);
    ShowLoginDraw();
    stUser User = ReadUsernameAndPassword();
    while (!FindUser(vUsers, User))
    {
        ShowLoginDraw();
        cout << "Invalid Username/Password!" << endl;
        User = ReadUsernameAndPassword();
    }
    CurrentUser = User;
    ShowMainMenue();
}
int main()

{
    while (true)
    {
        ShowLoginScreen();
    }

    system("pause>0");
    return 0;
}