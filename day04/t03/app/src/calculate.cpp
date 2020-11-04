#include <regex>
#include "calculate.h"

int CheckOperand(const std::string &operand, ContaineVarible &content, int f) {
    int returned = 0;
    if (content.HasVariable(operand)) {
        return content.GetValue(operand);
    } else {
        try {
            returned = std::stoi(operand);
        } catch (std::invalid_argument &) {
            throw (std::invalid_argument(
                "invalid operand" + std::to_string(f) + "\n"));
        } catch (std::out_of_range &) {
            throw (std::invalid_argument(
                "operand" + std::to_string(f) + " is out of range\n"));
        }
        return returned;
    }
}

Calculate::Operation AddOperation(const std::string &operation) {
    if (operation == "+") {
        return Calculate::Operation::addition;
    } else if (operation == "-") {
        return Calculate::Operation::subtraction;
    } else if (operation == "*") {
        return Calculate::Operation::multiplication;
    } else {
        return Calculate::Operation::division;
    }
}

Calculate::Calculate(std::string &line, ContaineVarible &content)
    : table(content) {
    std::smatch result;
    bool value = std::regex_match(line, result, std::regex(REGEX));
    if (!value) {
        throw (std::invalid_argument("invalid input\n"));
    }
    operand1 = CheckOperand(result.str(1), table, 1);
    operation = AddOperation(result.str(2));
    operand2 = CheckOperand(result.str(3), table, 2);
    if (operand2 == 0) {
        throw (std::invalid_argument("division by zero\n"));
    }
    res = result;
    if (size(res) == 5 && !res.str(4).empty()) {
        table.SetValue(res.str(4),
                       static_cast<int>(SolveExpression(operation)));
        std::cout << SolveExpression(operation) << std::endl;
    } else {
        std::cout << SolveExpression(operation) << std::endl;
    }
}

long long Calculate::SolveExpression(const Operation &operation) {
    return std::invoke(table_func.at(operation), this);
}
long long Calculate::Addition() const {
    return static_cast<long long>(operand1) + operand2;
}
long long Calculate::Subtraction() const {
    return static_cast<long long>(operand1) - operand2;
}
long long Calculate::Multiplication() const {
    return static_cast<long long>(operand1) * operand2;
}
long long Calculate::Division() const {
    long long buffer = static_cast<long long>(operand1) / operand2;
    if (operand2 == 0) {
        throw (std::invalid_argument("division by zero\n"));
    }
    return buffer;
}
