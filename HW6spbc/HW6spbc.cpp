// HW6spbc.cpp : Defines the entry point for the application.
//

#include "HW6spbc.h"
#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

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

	return 0;
}
