#pragma once

#include <iostream>
#include <sstream>
#include <deque>
#include <numeric>

struct Town {
    std::string name;
    int stamina;
    int distance;
    int position;
};

//parse
void CheckStoi(int value, std::string data, size_t index);
bool CheckArgument(std::deque<Town>& journey, char* argv);

//logic
bool GetTown(Town& town, std::string data, char* argv, int i);
bool GetAllTown(std::deque<Town>& journey, char** argv, int argc);
bool VisitAll(std::deque<Town>& journey);