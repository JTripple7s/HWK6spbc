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
void GraphCities::printDistances(vector<int>& distances) const {
	for (int i = 0; i < distances.size(); ++i) {
		if (distances[i] == INT_MAX) {
			cout << "Not all cities are connected my road" << endl;
		}
		else {
			cout << "Distance to City " << cities[i].cityName << " (" << cities[i].cityCode << "): " << distances[i] << "\n";
		}
	}
}
vector<int> GraphCities::dijkstraSP(GraphCities& graph, City& city) {
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
	vector<int> dist;	//distance vector
	vector<int> unvisitedSet;
	dist[city.ID] = 0;
	for (int i = 0; i < cities.size(); i++) {
		if (cities[i].ID != city.ID) {
			dist[cities[i].ID] = INT_MAX;
		}
	}
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
				}
			}
		}

	}
	return dist;

}
City& GraphCities::getCity(int index) {
	return cities[index];
}