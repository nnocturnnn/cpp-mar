#pragma once

#include "myFunction.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <ostream>
#include <sstream>

void ReadLineAndAdd(std::set<std::string>& uniqueWords, std::string& data);
void ReadFile (std::set<std::string>& uniqueWords, std::ifstream& fin);
void OutInfo(std::set<std::string>& uniqueWords, char* argv);

