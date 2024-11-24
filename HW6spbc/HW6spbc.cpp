#include "minHeap.h"
#include "HW6spbc.h"

/*
* Scan function that reads city.txt and stores them to graph -> city vector
* arguments consist of name of file to be read and the graph object
*/
void scanCityFile(const string& filename, GraphCities& graph) {
	ifstream inputFile(filename);

	if (!inputFile) {
		cerr << "Unable to open city.txt file " << endl;
		exit(1);
	}

	string line;
	while (getline(inputFile, line)) {
		stringstream ss(line);	//stringstream stores the data from txt into var
		int ID, Population, Elevation;
		string cityCode, CityName;

		ss >> ID >> cityCode >> CityName >> Population >> Elevation;
		graph.addCity(ID, cityCode, CityName, Population, Elevation);
	}
	inputFile.close();
}
/*
* Scan function that reads road.txt and stores them to graph -> cities struct -> pair object
* arguments consist of name of file to be read and the graph object
*/
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

		stringstream ss(line);	//stringstream stores the data from txt into var

		ss >> fromCity >> toCity >> distance;

		graph.addRoad(stoi(fromCity), stoi(toCity), distance);
	}
	inputFile.close();
}
/*
* Displays the header of the output to console
* imported ctime and chrono to utilize the accurate display of the date 
* based on user computer date and time data
*/
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
	graph.dijkstraSP(0);
	graph.printDistances();

	cout << "---------------------------------------------------------------" << endl;
	/*
	* exe will always have at least one argument passed through being the exe itself
	* multiple agrs can be passed and stored into argv array
	*/
	cout << "number of arguments passed with executeble: " << argc << endl;	
	cout << "test1";
	//cout << s1 << endl;

	return 0;
}


