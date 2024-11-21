#pragma once
#include<vector>
#include<unordered_map>
#include<list>
#include<string>

using namespace std;

class GraphCities {
private:
	unordered_map<string, list<pair<string, int>>> adjList;

public:
	void addEdge(const string& fromCity, const string& toCity, int distance);
	void displayGraph();
};