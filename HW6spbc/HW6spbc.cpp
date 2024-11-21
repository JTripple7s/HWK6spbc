// HW6spbc.cpp : Defines the entry point for the application.
//

#include "HW6spbc.h"

void scanFile(string filename) {
	ifstream inputFile(filename);

	if (!inputFile) {
		cerr << "Unable to open file " << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line)) {
		cout << line << endl;
	}
	inputFile.close();
}

int main()
{
	auto now = chrono::system_clock::now();
	time_t currentTime = chrono::system_clock::to_time_t(now);
	tm localTime;

	if (localtime_s(&localTime, &currentTime) != 0) {
			cerr << "No local time" << endl;
			return 1;
	}

	cout << "Author: Joel Burlingame and Paul Sihavong" << endl;
	cout << "Date:" << put_time(&localTime, "%m/%d/%Y") << endl;
	cout << "Course: CS311 (Data structures and Algorithms)" << endl;
	cout << "Description: Program to find the shortest route between cities" << endl;
	cout << "---------------------------------------------------------------" << endl;

	scanFile("city.txt");
	cout << "---------------------------------------------------------------" << endl;
	scanFile("road.txt");

	return 0;
}


