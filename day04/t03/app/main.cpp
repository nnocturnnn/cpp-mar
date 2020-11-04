#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "src/calculate.h"

bool CheckArgument(std::string line) {
    std::vector<std::string> conteiner;
    std::stringstream input(line);
    while(getline(input, line, ' ')) {
        if (!line.empty())
            conteiner.push_back(line);
    }
    return conteiner.size() != 1 ;
}

int main(int argc, char** argv) {
    ContaineVarible content;
    while (true) {
        std::cout << ":>";
        std::string line;
        getline(std::cin, line);
        if (line.find("quit") != std::string::npos && CheckArgument(line)) {
            std::cerr << "invalid input\n";
        }
        else if (line.find("quit") != std::string::npos){
            return 0;
        }
        try {
            Calculate expressions(line, content);
        } catch (std::invalid_argument &e) {
            std::cerr << e.what();
        }
    }
    return 0;
}
