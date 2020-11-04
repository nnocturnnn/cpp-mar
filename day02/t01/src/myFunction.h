#pragma once

#include <string>
#include <fstream>
#include <sstream>

std::string CreateNewNameFile(char *old_name);
void DeletePunctuationMarks(std::string& line);
