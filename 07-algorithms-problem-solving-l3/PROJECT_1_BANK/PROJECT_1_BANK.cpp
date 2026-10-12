#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";
enum enChoses
{
	ShowClients = 1,
	AddNew = 2,
	Delete = 3,
	Update = 4,
	Find = 5,
	Exit = 6,
};
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};
vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord;
	// define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		// store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1);
		// it adds last word of the string.
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
void PrintClientRecord(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}
void PrintAllClientsData(vector<sClient> vClients)
{
	system("cls");
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
	for (sClient Client : vClients)
	{
		PrintClientRecord(Client);
		cout << endl;
	}
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	system("pause>0");
}

bool FindClientByAccountNumber(string AccountNumber, const vector<sClient>& vClients)
{
	for (const sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			return true;
		}
	}
	return false;
}
bool FindClientByAccountNumber(string AccountNumber, const vector<sClient>& vClients, sClient& Client)
{
	for (const sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}
sClient ReadNewClient(const vector<sClient>& vClients)
{
	sClient Client;
	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);
	while (FindClientByAccountNumber(Client.AccountNumber, vClients)) {
		cout << "Client with [" << Client.AccountNumber << "] already exists, Enter another Account Number ? ";
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
sClient AddNewClient(vector<sClient>& vClients)
{
	sClient Client;
	Client = ReadNewClient(vClients);
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
	return Client;
}
void AddClients(vector<sClient>& vClients)
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";
		sClient Client = AddNewClient(vClients);
		vClients.push_back(Client);
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}
void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
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
			system("pause>0");
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		system("pause>0");
		return false;
	}
}
string ReadClientAccountNumber()
{
	system("cls");
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;
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
			system("pause>0");
			return true;

		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		system("pause>0");
		return false;
	}

}
void FindClient(string AccountNumber, vector<sClient>& vClients) {
	sClient Client;
	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
	system("pause>0");
}
enChoses IntToEnum(int chose)
{
	return enChoses(chose);
}
void MainMenue() {
	cout << "============================================================\n";
	cout << "\t\tMain Menuue Screen\n";
	cout << "============================================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "============================================================\n";
}
void Bank() {
	vector<sClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
	enChoses Choose;
	int choose;
	string AccountNumber;

	do
	{
		system("cls");
		MainMenue();
		do
		{
			cout << "Choose what do you want to do? [1 to 6]?";
			cin >> choose;
		} while (choose < 1 || choose >6);

		Choose = IntToEnum(choose);
		switch (Choose)
		{
		case enChoses::ShowClients:
			PrintAllClientsData(vClients);
			break;
		case enChoses::AddNew:
			AddClients(vClients);
			break;
		case enChoses::Delete:
			AccountNumber = ReadClientAccountNumber();
			DeleteClientByAccountNumber(AccountNumber, vClients);
			break;
		case enChoses::Update:
			AccountNumber = ReadClientAccountNumber();
			UpdateClientByAccountNumber(AccountNumber, vClients);
			break;
		case enChoses::Find:
			AccountNumber = ReadClientAccountNumber();
			FindClient(AccountNumber, vClients);
			break;
		}
	} while (Choose != enChoses::Exit);
}
int main()
{
	Bank();
	system("pause>0");
	return 0;
}
