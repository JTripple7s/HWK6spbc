#include"GraphCities.h"

void GraphCities::addEdge(const string& fromCity, const string& toCity, int distance) {
	adjList[fromCity].push_back(make_pair(toCity, distance));
}