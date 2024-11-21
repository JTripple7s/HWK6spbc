
#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>
#include <string>
#include"GraphCities.h"


using namespace std;

void scanCityFile(const string& filename, GraphCities& graph);
void scanRoadsFile(const string& filename, GraphCities& graph);
