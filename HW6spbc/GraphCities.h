#pragma once
#include<vector>
#include<list>
#include<string>

using namespace std;

struct City {
	int ID;
	string cityCode;
	string cityName;
	int Population;
	int Elevation;

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

public:
	void addCity(int id, const string& code, const string& name, int population, int elevation);
	void addRoad(int fromCity, int toCity, int distance);
	void displayGraph() const;
};