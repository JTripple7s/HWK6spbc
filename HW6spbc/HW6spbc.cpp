// HW6spbc.cpp : Defines the entry point for the application.
//

#include "HW6spbc.h"

void scanCityFile(string filename, unordered_map<string, City>& cities) {
	ifstream inputFile(filename);

	if (!inputFile) {
		cerr << "Unable to open file " << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);
		int ID, Population, Elevation;
		string cityCode, CityName;

		ss >> ID >> cityCode >> CityName >> Population >> Elevation;
		City city(ID, cityCode, CityName, Population, Elevation);
		cities[cityCode] = city;
	}
	inputFile.close();
}

void scanRoadsFile(const string& filename, GraphCities& graph, const unordered_map<string, City>& cities) {
	ifstream inputFile(filename);
	if (!inputFile) {
		cerr << "Unable to open file" << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line)) {
		string fromCity, toCity;
		int distance;

		stringstream ss(line);

		ss >> fromCity >> toCity >> distance;

		graph.addEdge(fromCity, toCity, distance);
	}
	inputFile.close();
}

int main()
{
	unordered_map<string, City> cities;
	GraphCities graph;
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

	scanCityFile("city.txt", cities);
	scanRoadsFile("road.txt", graph, cities);

	graph.displayGraph();

	return 0;
}


