#pragma once
#include<vector>
#include<list>
#include <climits>
#include<string>

using namespace std;

struct City {
	int ID;
	string cityCode;
	string cityName;
	int Population;
	int Elevation;
	int predecessorID = -1;

	vector<pair<int, int>> neighbors;

	City(int id, const string& code, const string& name, int population, int elevation) {
		ID = id;
		cityCode = code;
		cityName = name;
		Population = population;
		Elevation = elevation;
	}
};

class GraphCities {
private:
	vector<City> cities;
	vector<int> route;
	vector<int> predecessorCity;
	int sourceCity;

public:
	void addCity(int id, const string& code, const string& name, int population, int elevation);
	void addRoad(int fromCity, int toCity, int distance);
	void displayGraph() const;
	void printDistances() const;
	void printDistanceFromTo(int destinationC) const;
	void dijkstraSP(int fromCity);
};