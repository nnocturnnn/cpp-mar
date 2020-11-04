#pragma once
#include "containeVariable.h"
#include <iostream>
#include <map>
#include <regex>

#define REGEX R"lit(\s*([a-zA-Z]+|[\-\+]?[\d]+)\s*([\+\/\-\*])\s*([a-zA-Z]+|[\-\+]?[\d]+)\s*(?:=?\s*([a-zA-Z])+)?\s*)lit"
class Calculate {
    public:
    enum Operation {
        addition,
        subtraction,
        multiplication,
        division,
    };
    explicit Calculate(std::string &line, ContaineVarible& content);
    long long SolveExpression(const Operation &operation);
    long long Addition() const;
    long long Subtraction() const;
    long long Multiplication() const;
    long long Division() const;
    private:
    inline const static std::map<Operation, long long (Calculate::*)() const>
        table_func {
        {Operation::addition, &Calculate::Addition},
        {Operation::subtraction, &Calculate::Subtraction},
        {Operation::multiplication, &Calculate::Multiplication},
        {Operation::division, &Calculate::Division}
    };
    int operand1, operand2;
    ContaineVarible& table;
    Operation operation;
    std::smatch res;
};
