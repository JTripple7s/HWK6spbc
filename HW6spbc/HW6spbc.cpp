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

int dijkstraSP(GraphCities& graph, City& city) {
	/*
	vector<int> distance, vector<City> unvisitedSet;		
	vector<City> tempVec = graph.getCities();			
	distance.push_back(cityID.ID);


	for (int i = 0; i < graph.getCities().size(); i++) {	
		if (tempVec[i].ID != cityID.ID) {
			distance[i] = INT_MAX;
			unvisitedSet.push_back(tempVec[i]);
		}

		while (!unvisitedSet.empty()) {		
			City smallest = unvisitedSet[0];
			for (int i = 0; i < unvisitedSet.size(); i++) {
				if (unvisitedSet[i] < smallest) {
					smallest = unvisitedSet[i];
				}

			}
			int path = smallest; 
			for (int i = 0; i < unvisitedSet.size(); i++) {
				if (unvisitedSet[i] == smallest) {
					unvisitedSet.erase(unvisitedSet.begin() + i);	
				}
				else {
					cerr << "Error in dijkstra algorithm" << endl;
					exit(1);
				}
			}
			for(int i = 0; i < tempVec[])
		}
	}
	*/
	vector<int> distance, vector<int> unvisitedSet;
	vector<City> tempVec = graph.getCities();
	distance[city.ID] = 0;
	for (int i = 0; i < tempVec.size(); i++) {
		if (tempVec[i].ID != city.ID) {
			distance[tempVec[i].ID] = INT_MAX;
		}
	}
	for (const auto& city : tempVec) {
		unvisitedSet.push_back(city.ID);
	}
	while (!unvisitedSet.empty()) {
		int minDist = INT_MAX;
		int smallestIndex = -1;
		for (int i = 0; i < unvisitedSet.size(); ++i) {
			int smallestID = unvisitedSet[i];
			if (distance[smallestID] < minDist) {
				minDist = distance[smallestID];
				smallestIndex = i;
			}
		}
		if (minDist == INT_MAX) {
			break;
		}
		int smallestID = unvisitedSet[smallestIndex];
		unvisitedSet.erase(unvisitedSet.begin() + smallestIndex);

		for (const auto& neighbor : tempVec[smallestID].neighbors) {
			int neighborID = neighbor.first;
			int distance = neighbor.second;
		}
	}

	
}

int main()
{
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

	scanCityFile("city.txt", graph);
	scanRoadsFile("roads.txt", graph);

	graph.displayGraph();
	
	/*Heap* something = new Heap;
	for (int i = 20; i > 0; i--)
		something->insert(i);
	something->printHeap();*/


	return 0;
}


