#pragma once

#include "myFunction.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <ostream>
#include <sstream>

struct Words {
    std::set<std::string> uniqueWords;
    std::multiset<std::string> countUniqueWords;
};

void ReadLineAndAdd(Words& words, std::string& data);
void ReadFile (Words& words, std::ifstream& fin);
void OutInfo(Words& words, char* argv);

