#pragma once

#include <iostream>
#include <unordered_map>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void loadAliases();
extern unordered_map<string, string> aliasMap;