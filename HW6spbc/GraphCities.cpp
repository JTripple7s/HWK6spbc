#include"GraphCities.h"
#include <iostream>
using namespace std;

void GraphCities::addCity(int id, const string& code, const string& name, int population, int elevation) {
	cities.emplace_back(id, code, name, population, elevation);
}
void GraphCities::addRoad(int fromCity, int toCity, int distance) {
	cities[fromCity].neighbors.push_back({ toCity, distance });
}
void GraphCities::displayGraph() const {
	for (const auto& city : cities) {
		cout << "FromCity: " << city.cityName << ", population " << city.Population << ", elevation " << city.Elevation << endl;
		for (const auto& neighbor : city.neighbors) {
			cout << "To City: " << cities[neighbor.first].cityName << ", Population: " << cities[neighbor.first].Population << ", Elevation: " << cities[neighbor.first].Elevation << endl;
		}
		cout << endl;
	}
}