#include "src/Draugr.h"
#include <regex>

void CheckFirstArg(std::string argv) {
    std::cmatch result;
    std::regex regular(R"lit(\s*([0-8])\s*)lit");
    if (!(std::regex_match(argv.c_str(), result, regular))) {
        throw(std::invalid_argument("Invalid shoutNumber"));
    }
}

template <typename T>
void CheckArg(T argv) {
    std::cmatch result;
    std::regex regular("(^[0-9]*)|(^[0-9]+\\.?[0-9]+)");
    if (!std::regex_match(argv.c_str(), result, regular)) {
        throw(std::invalid_argument("Error"));
    }
}

std::vector<std::string> CheckNames(std::string argv) {
    std::vector<std::string> names;
    std::smatch result;
    std::regex regular("\\s*([\\w]+),([\\w]+)\\s*");
    if (!std::regex_match(argv, result, regular)) {
        throw(std::invalid_argument("Invalid names"));
    }
    names.push_back(result.str(1));
    names.push_back(result.str(2));
    return names;
}


int main(int argc, char** argv) {
    if (argc < 4 || argc > 5) {
        std::cerr << "usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]" << std::endl;
        return 1;
    }
    std::vector<std::string> names;
    Draugr* first = NULL;
    Draugr* second = NULL;
    try {
        CheckFirstArg(std::string(argv[1]));
        names = CheckNames(argv[2]);
        CheckArg(std::string(argv[3]));
        if (argc == 4) {
            first = new Draugr(std::stod(argv[3]));
            first->setName(std::move(names[0]));
            first->shoutPhrase(std::stoi(argv[1]));
            second = new Draugr(*first);
            second->setName(std::move(names[1]));
            second->shoutPhrase(std::stoi(argv[1]));
        } else if (argc == 5) {
            CheckArg(std::string(argv[4]));
            first = new Draugr(std::stod(argv[3]), std::stoi(argv[4]));
            first->setName(std::move(names[0]));
            first->shoutPhrase(std::stoi(argv[1]));
            second = new Draugr(std::move(*first));
            second->setName(std::move(names[1]));
            second->shoutPhrase(std::stoi(argv[1]));
        }
    } catch (std::out_of_range &){
        std::cerr << "Error" << std::endl;
    }catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    delete first;
    delete second;
    return 0;
}
