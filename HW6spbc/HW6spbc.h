
#pragma once

#include "HW6spbc.h"
#include "GraphCities.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

struct City {
	int ID;
	string cityCode;
	string cityName;
	int Population;
	int Elevation;

	City() : ID(0), cityCode(" "), cityName(" "), Population(0), Elevation(0) {}

	City(int id, const string& code, const string& name, int population, int elevation) {
		ID = id;
		cityCode = code;
		cityName = name;
		Population = population;
		Elevation = elevation;
	}
};

void scanCityFile(string filename, unordered_map<string, City>& cities);
void scanRoadsFile(const string& filename, GraphCities& graph, const unordered_map<string, City>& cities);
