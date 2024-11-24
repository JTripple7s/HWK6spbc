#include"GraphCities.h"
#include <iostream>
using namespace std;
/*
* addCity takes data from scanner and adds them to a cities object vector
* arguments consist of data to be applied to the City object within the city vector
*/
void GraphCities::addCity(int id, const string& code, const string& name, int population, int elevation) {
	cities.emplace_back(id, code, name, population, elevation);
}
/*
* addRoad takes data from scanner and adds them to a cities object pair class
* arguments consist of source city from which the distance and destination city data will be put 
* in pair linking that city object with its neighboring city and the distance to that city
*/
void GraphCities::addRoad(int fromCity, int toCity, int distance) {
	cities[fromCity].neighbors.push_back({ toCity, distance });
}
/*
* displayGraph will display the contents of the entire graph and the edges(roads) between nodes(cities)
*/
void GraphCities::displayGraph() const {
	for (const auto& city : cities) {
		cout << "FromCity: " << city.cityName << ", population " << city.Population << ", elevation " << city.Elevation << endl;
		for (const auto& neighbor : city.neighbors) {
			cout << "To City: " << cities[neighbor.first].cityName << ", Population: " << cities[neighbor.first].Population << ", Elevation: " << cities[neighbor.first].Elevation << endl;
		}
		cout << endl;
	}
}
/*
* printDistances will display the contents of route vector
* source city will be displayed followed by the shortest path between all connected cities
*/
void GraphCities::printDistances() const {
	for (int i = 0; i < route.size(); ++i) {
		if (route[i] == INT_MAX) {
			cout << "Not all cities are connected my road" << endl;
		}
		else {
			cout << "Distance from " << cities[sourceCity].cityName << " to -> " << cities[i].cityName << " (" << cities[i].cityCode << ") : " << route[i] << endl;
		}
	}
}
void GraphCities::printDistanceFromTo(string destinationC) const {
	int toCitytoInt = -1;
	for (int i = 0; i < cities.size(); i++) {
		if (destinationC == cities[i].cityCode) {
			toCitytoInt = cities[i].ID;
			break;
		}
	}
	if (toCitytoInt == -1) {
		cout << "The destination city does not exist within the graph" << endl;
		exit(1);
	}
	cout << "From City: " << cities[sourceCity].cityName << ", population " << cities[sourceCity].Population << ", elevation " << cities[sourceCity].Elevation << endl;
	cout << "To City: " << cities[toCitytoInt].cityName << ", population " << cities[toCitytoInt].Population << ", elevation " << cities[toCitytoInt].Elevation << endl;
	cout << "Shortest distance from " << cities[sourceCity].cityName << " to " << cities[toCitytoInt].cityName << " is " << route[toCitytoInt] << endl;
	cout << "Through the route: ";
	vector<int> travel;
	for (int i = cities[toCitytoInt].ID; i != -1; i = predecessorCity[i]) {
		travel.push_back(i);
	}
	reverse(travel.begin(), travel.end());
	for (int i = 0; i < travel.size(); i++) {
		cout << "->" << cities[travel[i]].cityName;
	}
	
}
/*
* dijskstraSP function is the implementation of the shortest past algorithim the program uses to find
* the shortest path between city structs within the graph. 
* code is based of psudo code prived from handout as well as addition psudo code found online
* agruments consist of the source city
*/
void GraphCities::dijkstraSP(const string& fromCity) {
	vector<int> dist(cities.size(), INT_MAX);
	vector<int>predecessor(cities.size(), -1);
	vector<int> unvisitedSet;
	int fromCityToInt = -1;
	//cout << fromCity << " " << cities[0].cityCode;
	for (int i = 0; i < cities.size(); i++) {
		if (fromCity == cities[i].cityCode) {
			fromCityToInt = cities[i].ID;
			break;
		}
	}
	if (fromCityToInt == -1) {
		cout << "The source city does not exist within the graph" << endl;
		exit(1);
	}
	dist[fromCityToInt] = 0;
	for (const auto& city : cities) {
		unvisitedSet.push_back(city.ID);
	}
	while (!unvisitedSet.empty()) {
		int minDist = INT_MAX;
		int smallestIndex = -1;
		for (int i = 0; i < unvisitedSet.size(); ++i) {
			int smallestID = unvisitedSet[i];
			if (dist[smallestID] < minDist) {
				minDist = dist[smallestID];
				smallestIndex = i;
			}
		}
		if (minDist == INT_MAX) {
			break;
		}
		int smallestID = unvisitedSet[smallestIndex];
		unvisitedSet.erase(unvisitedSet.begin() + smallestIndex);

		for (const auto& neighbor : cities[smallestID].neighbors) {
			int neighborID = neighbor.first;
			int distance = neighbor.second;

			if (dist[smallestID] != INT_MAX) {
				int alt = dist[smallestID] + distance;
				if (alt < dist[neighborID]) {
					dist[neighborID] = alt;
					predecessor[neighborID] = smallestID;
				}
			}
		}
	}
	this->route = dist;
	this->sourceCity = fromCityToInt;
	this->predecessorCity = predecessor;
}