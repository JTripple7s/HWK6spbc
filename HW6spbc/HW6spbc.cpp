#include "minHeap.h"
#include "HW6spbc.h"


void scanCityFile(const string& filename, GraphCities& graph) {
	ifstream inputFile(filename);

	if (!inputFile) {
		cerr << "Unable to open city.txt file " << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);
		int ID, Population, Elevation;
		string cityCode, CityName;

		ss >> ID >> cityCode >> CityName >> Population >> Elevation;
		graph.addCity(ID, cityCode, CityName, Population, Elevation);
	}
	inputFile.close();
}

void scanRoadsFile(const string& filename, GraphCities& graph) {
	ifstream inputFile(filename);
	if (!inputFile) {
		cerr << "Unable to open roads.txt file" << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line)) {
		string fromCity, toCity;
		int distance;

		stringstream ss(line);

		ss >> fromCity >> toCity >> distance;

		graph.addRoad(stoi(fromCity), stoi(toCity), distance);
	}
	inputFile.close();
}
void headerOut() {
	auto now = chrono::system_clock::now();
	time_t currentTime = chrono::system_clock::to_time_t(now);
	tm localTime;
	localtime_s(&localTime, &currentTime);

	cout << "Author: Joel Burlingame and Paul Sihavong" << endl;
	cout << "Date:" << put_time(&localTime, "%m/%d/%Y") << endl;
	cout << "Course: CS311 (Data structures and Algorithms)" << endl;
	cout << "Description: Program to find the shortest route between cities" << endl;
	cout << "---------------------------------------------------------------" << endl;
}

int main(int argc, char* argv[])
{
	//string s1 = argv[1];

	GraphCities graph;

	if (argv[1] != nullptr) {
		cout << "this is a test\n";
	}
	headerOut();
	scanCityFile("city.txt", graph);
	scanRoadsFile("roads.txt", graph);

	graph.displayGraph();
	cout << "---------------------------------------------------------------" << endl;
	graph.dijkstraSP(graph, 0);
	graph.printDistances();

	cout << "---------------------------------------------------------------" << endl;
	cout << "we made it" << endl;
	cout << argc << endl;
	//cout << s1 << endl;
	//printf("%s", argv[1]);


	return 0;
}


