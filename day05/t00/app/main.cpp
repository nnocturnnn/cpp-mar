#include "src/Draugr.h"
#include <regex>


int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "usage: ./draugr [shoutNumber]" << std::endl;
        return 1;
    }
    std::string line = std::string(argv[1]);
    std::smatch result;
    std::regex_match(line, result, std::regex(R"lit(\s*([0-8])\s*)lit"));
    try {
        Draugr draugr;
        draugr.shoutPhrase(std::stoi(result.str(1)));
    }
    catch(...) {
        std::cerr << "Invalid shoutNumber" << std::endl;
        return 1;
    }
    return 0;
}
