#include"GraphCities.h"
#include <iostream>

void GraphCities::addEdge(const string& fromCity, const string& toCity, int distance) {
	adjList[fromCity].push_back(make_pair(toCity, distance));
}
void GraphCities::displayGraph() {
	for (const auto& City : adjList) {
		cout << "From City: " << City.first << " ---> ";
		for (const auto& neighboor : City.second) {
			cout << "(" << neighboor.first << ", " << neighboor.second << ") ";
			cout << endl;
		}
	}
}