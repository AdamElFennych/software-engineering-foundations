// Disable warning 4996 regarding unsafe functions (specific to Visual Studio)
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	// Local Time
	time_t t = time(0); // Get time now

	// Convert date and time to string
	char* dt = ctime(&t);
	cout << "Local date and time is : " << dt << "\n";

	// Greenwich Mean Time (GMT/UTC)
	// Converting now to tm struct for UTC date/time
	tm* gmtm = gmtime(&t);

	// Convert data from struct to string
	dt = asctime(gmtm);
	cout << "UTC date and time is : " << dt << "\n";

	return 0;
}