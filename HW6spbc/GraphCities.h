#pragma once
#include<vector>
#include<list>
#include <climits>
#include<string>
#include<algorithm>

using namespace std;
/*
* struct we use to store data from city.txt
*/
struct City {
	int ID;
	string cityCode;
	string cityName;
	int Population;
	int Elevation;

	vector<pair<int, int>> neighbors;	//this neighbors vector stores the neighboring cityID and distance to that city
										//collected from the roads.txt creating an array of arraylists (graph) after the city struct
										//is stored within a city vector

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
	void printDistanceFromTo(string destinationC) const;
	void dijkstraSP(const string& fromCity);
};