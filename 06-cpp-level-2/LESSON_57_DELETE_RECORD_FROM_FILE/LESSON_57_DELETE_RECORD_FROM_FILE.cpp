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

	// Check if the file opened successfully
	if (MyFile.is_open())
	{
		string Line;
		// Read the file line by line and store it in the 'Line' variable
		while (getline(MyFile, Line))
		{
			// Add each line from the file to the Vector
			vFileContent.push_back(Line);
		}
		// Always close the file when finished
		MyFile.close();
	}
}

void SaveVectorToFile(string FileName, vector<string> vFileContent)
{
	// Note: No reference (&) used for the vector parameter because it is read-only here
	fstream MyFile;

	// Open in write mode (creates new file or overwrites existing one)
	MyFile.open(FileName, ios::out); // Write Mode

	// Check if the file opened successfully
	if (MyFile.is_open())
	{
		// Use reference (&) to access the address directly and avoid creating a copy
		for (string& Line : vFileContent)
		{
			// Ensure the line is not empty before writing
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}
		// Always close the file when finished
		MyFile.close();
	}
}

void DeleteRecordFromFile(string FileName, string Record)
{
	vector<string> vFileContent;
	LoadDataFromFileToVector(FileName, vFileContent);

	// Must use reference (&) here to modify the actual content in the Vector
	for (string& Line : vFileContent)
	{
		// If the record matches, "delete" it by setting it to an empty string
		if (Line == Record)
		{
			Line = "";
		}
	}
	SaveVectorToFile(FileName, vFileContent);
}

void PrintFileContent(string FileName)
{
	fstream MyFile;
	// Open for reading only
	MyFile.open(FileName, ios::in); // Read Mode

	// Check if the file opened successfully
	if (MyFile.is_open())
	{
		string Line;
		// Read the file line by line
		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}
		// Always close the file when finished
		MyFile.close();
	}
}

int main()
{
	// Create a dummy file for testing purposes
	fstream TestFile;
	TestFile.open("MyFile.txt", ios::out);
	TestFile << "Ali\nOmar\nAhmed\nSami";
	TestFile.close();

	cout << "File Content Before Delete: \n";
	PrintFileContent("MyFile.txt");

	// Delete "Omar" from the file
	DeleteRecordFromFile("MyFile.txt", "Omar");

	cout << "\nFile Content After Delete: \n";
	PrintFileContent("MyFile.txt");

	return 0;
}