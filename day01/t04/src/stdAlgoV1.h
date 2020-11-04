#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <fstream>
#include <sstream>

bool CheckValidLine(std::string data);
int ReadFile (std::forward_list<std::string>& list, std::ifstream& fin);
void OutInfo(std::forward_list<std::string>& list, int& size);

