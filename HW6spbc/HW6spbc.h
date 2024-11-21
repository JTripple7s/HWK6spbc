// HW6spbc.h : Include file for standard system include files,
// or project specific include files.

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

void scanCityFile(string filename, unordered_map<string, City>& cities);
void scanRoadsFile(const string& filename, GraphCities& graph, const unordered_map<string, City>& cities);


// TODO: Reference additional headers your program requires here.
