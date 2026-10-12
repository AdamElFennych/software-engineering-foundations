#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
const string ClientsFileName = "Clients.txt";
void ShowTransactionsMenueScrean();
void ShowMainMenue();

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};
short ReadShort(short From, short To)
{
	short Number;
	while (true)
	{
		cin >> Number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Input! Please enter a number: ";
			continue;
		}

		if (Number >= From && Number <= To)
		{
			return Number;
		}
		else
		{
			cout << "Please enter a number between " << From << " and " << To << ": ";
		}
	}
}
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

		S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
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
	Client.AccountBalance = stod(vClientData[4]);//cast string to double
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
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode

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
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);//read Mode

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
void ShowAllClientsScreen()
{
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Accout Number";
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
void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------\n";
}
bool FindClientByAccountNumber(string AccountNumber, vector <sClient> vClients, sClient& Client)
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
bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
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
vector <sClient> SaveCleintsDataToFile(string FileName, vector <sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);//overwrite

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{

			if (C.MarkForDelete == false)
			{
				//we only write records that are not marked for delete.  
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}

		}

		MyFile.close();
	}

	return vClients;
}
void AddDataLineToFile(string FileName, string  stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << stDataLine << endl;

		MyFile.close();
	}
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
		//system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;

	} while (toupper(AddMore) == 'Y');

}
bool DeleteClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
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

			//Refresh Clients 
			vClients = LoadCleintsDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}
bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
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

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
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

	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);
}
void ShowUpdateClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------\n";

	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
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

	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
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
enum enMainMenueOptions
{
	eListClients = 1, eAddNewClient = 2,
	eDeleteClient = 3, eUpdateClient = 4,
	eFindClient = 5, eTransactios = 6,
	eExit = 7
};
void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ShowMainMenue();

}
short ReadMainMenueOption()
{
	cout << "Choose what do you want to do? [1 to 7]? ";
	return ReadShort(1, 7);
}
short ReadTransactionsMenueOption() {
	cout << "Choose what do you want to do? [1 to 4]? ";
	return ReadShort(1, 4);
}
enum enTransactionsMenueOptions {
	eDeposet = 1, eWithdraw = 2,
	eTotalBalances = 3, eMainMenue = 4
};
void GoBackToTransactionMenue() {
	cout << "\n\nPress any key to go back to Transactions Menue...";
	system("pause>0");
	system("cls");
	ShowTransactionsMenueScrean();
}
bool ProcessTransaction(string AccountNumber, vector<sClient>& vClients, sClient& Client, bool Withdraw) {
	char Answer = 'n';
	double amounth = 0;
	if (Withdraw)
	{
		cout << "Please enter withdraw amount? ";
		cin >> amounth;
		while (Client.AccountBalance < amounth) {
			cout << "amount exceeds the balance , you can withdraw up to : " << Client.AccountBalance << endl;

			cout << "Please enter a another amounth : ";
			cin >> amounth;
		}
		amounth *= -1;
	}
	else
	{
		cout << "Please enter deposit amount? ";
		cin >> amounth;
		while (amounth <= 0) {
			cout << "Please enter a positive amounth : ";
			cin >> amounth;
		}
	}
	cout << "\n\nAre you sure you want perfrom this transaction? y/n ? ";
	cin >> Answer;
	if (toupper(Answer) == 'Y')
	{
		for (sClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += amounth;
				Client.AccountBalance = C.AccountBalance;
				return true;
			}
		}
	}
	return false;
}
//withdrow and deposet both use this function
void EditAccountBalance(string AccountNumber, vector <sClient>& vClients, bool Withdraw = false) {
	sClient Client;
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{

		PrintClientCard(Client);
		if (ProcessTransaction(AccountNumber, vClients, Client, Withdraw)) {
			cout << "Don New Ballance is : " << Client.AccountBalance << endl;
			SaveCleintsDataToFile(ClientsFileName, vClients);
		}
		else
		{
			cout << "\nOperation Cancelled.\n";
		}

	}
	else
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.";

	}

}

void ShowDepositeScreen() {
	cout << "\n-----------------------------------\n";
	cout << "\tDeposit Screen";
	cout << "\n-----------------------------------\n";
	string AccountNumber = ReadClientAccountNumber();
	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	EditAccountBalance(AccountNumber, vClients);
}
void ShowWithdrawScreen() {
	cout << "\n-----------------------------------\n";
	cout << "\tWithdraw Screen";
	cout << "\n-----------------------------------\n";
	string AccountNumber = ReadClientAccountNumber();
	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	EditAccountBalance(AccountNumber, vClients, true);
}
void PrintTransactionsRecordLine(const sClient& Client)
{
	cout << "| " << setw(25) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(24) << left << Client.AccountBalance;
}
void ShowTotalBalances()
{
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	double Balance = 0;
	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(25) << "Accout Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(24) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In the System!";
	else

		for (const sClient& Client : vClients)
		{
			Balance += Client.AccountBalance;
			PrintTransactionsRecordLine(Client);
			cout << endl;
		}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "\n\t\t\t\t\tTotal Balances = " << Balance << endl;
}
void PerfromTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOptions) {
	switch (TransactionsMenueOptions) {
	case enTransactionsMenueOptions::eDeposet:
		system("cls");
		ShowDepositeScreen();
		GoBackToTransactionMenue();
		break;
	case enTransactionsMenueOptions::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionMenue();
		break;
	case enTransactionsMenueOptions::eTotalBalances:
		system("cls");
		ShowTotalBalances();
		GoBackToTransactionMenue();
		break;
	case enTransactionsMenueOptions::eMainMenue:
		ShowMainMenue();
		break;
	}
}
void ShowTransactionsMenueScrean() {
	cout << "===========================================\n";
	cout << "\t\tTransaction Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menue.\n";
	cout << "===========================================\n";
	PerfromTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
}
void PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
{
	switch (MainMenueOption)
	{
	case enMainMenueOptions::eListClients:
	{
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenue();
		break;
	}
	case enMainMenueOptions::eAddNewClient:
		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenue();
		break;

	case enMainMenueOptions::eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenue();
		break;
	case enMainMenueOptions::eTransactios:
		system("cls");
		ShowTransactionsMenueScrean();
		break;
	case enMainMenueOptions::eExit:
		system("cls");
		ShowEndScreen();
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
	cout << "\t[7] Exit.\n";
	cout << "===========================================\n";
	PerfromMainMenueOption((enMainMenueOptions)ReadMainMenueOption());
}
int main()
{
	ShowMainMenue();
	system("pause>0");
	return 0;
}