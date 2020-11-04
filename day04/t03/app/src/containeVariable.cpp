#include "containeVariable.h"

bool ContaineVarible::HasVariable(const std::string& operand) {
    return container.count(operand) != 0;
}

int  ContaineVarible::GetValue(const std::string& operand) {
    int buffer = container[operand];
    if (buffer == 0)
        throw (std::invalid_argument("division by zero\n"));
    return buffer;
}

void ContaineVarible::SetValue(const std::string& key, int value) {
    container[key] = value;
}
