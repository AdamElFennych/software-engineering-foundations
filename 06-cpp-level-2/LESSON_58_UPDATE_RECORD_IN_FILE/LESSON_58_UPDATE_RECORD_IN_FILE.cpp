#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadDataFromFileToVector(string FileName, vector<string>& vFileContent)
{
	fstream MyFile;
	// Open for reading only
	MyFile.open(FileName, ios::in); // Read Mode

	// Check if the file works
	if (MyFile.is_open())
	{
		string Line;
		// Get the first line from the file and save it in this Line string
		while (getline(MyFile, Line))
		{
			// Each line in the file is added to the Vector
			vFileContent.push_back(Line);
		}
		// Must close the file after finishing
		MyFile.close();
	}
}

void SaveVectorToFile(string FileName, vector<string> vFileContent)
{
	// Do not use & for vector in parameter: because it is read-only and not for modification
	fstream MyFile;

	// To open a new file or save new info in the file with every Run
	MyFile.open(FileName, ios::out); // Write Mode

	// Check if the file works
	if (MyFile.is_open())
	{
		// Use & to avoid creating another copy - Go to Address
		for (string& Line : vFileContent)
		{
			// Ensure the input is not empty
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
		// Must close the file after finishing
		MyFile.close();
	}
}

void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
{
	vector<string> vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);

	// Must use & to modify the Vector
	for (string& Line : vFileContent)
	{
		// Swap data
		if (Line == Record)
		{
			Line = UpdateTo;
		}
	}
	SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContent(string FileName)
{
	fstream MyFile;
	// Open for reading only
	MyFile.open(FileName, ios::in); // Read Mode

	// Check if the file works
	if (MyFile.is_open())
	{
		string Line;
		// Get the first line from the file and save it in this Line string
		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}
		// Must close the file after finishing
		MyFile.close();
	}
}

int main()
{
	cout << "File Content Before Update. \n";
	// Fixed typo .tet -> .txt for consistency
	PrintFileContent("MyFile.txt");

	UpdateRecordInFile("MyFile.txt", "Saeed", "Riyadh");

	cout << "\nFile Content After Update. \n";
	PrintFileContent("MyFile.txt");

	return 0;
}