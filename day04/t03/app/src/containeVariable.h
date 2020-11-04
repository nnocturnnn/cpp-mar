#pragma once
#include <iostream>
#include <map>
#include <sstream>

class ContaineVarible {
public:

    bool HasVariable(const std::string& operand);
    int GetValue(const std::string& operand);
    void SetValue(const std::string& key, int value);
private:
    std::map<std::string, int> container;
};

