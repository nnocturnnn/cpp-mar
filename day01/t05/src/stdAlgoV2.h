#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include <fstream>
#include <sstream>

bool CheckValidLine(std::string data);
void ReadFile (std::forward_list<std::string>& list, std::ifstream& fin);
void WriteNewFile(std::ofstream& fout, std::forward_list<std::string>& list);
void OutInfo(std::forward_list<std::string>& list, char* argv);

