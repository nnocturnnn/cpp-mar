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

void DraugrShout(Draugr* draugr, char** argv, int argc) {
    try {
        if (argc == 2) {
            draugr = new Draugr;
            draugr->shoutPhrase(std::stoi(argv[1]));
        } else if (argc == 3) {
            CheckArg(std::string(argv[2]));
            Draugr *second = new Draugr(std::stod(argv[2]));
            second->shoutPhrase(std::stoi(argv[1]));
            draugr = new Draugr(std::stoi(argv[2]));
            draugr->shoutPhrase(std::stoi(argv[1]));
            delete second;
        } else if (argc == 4) {

            CheckArg(std::string(argv[2]));
            CheckArg(std::string(argv[3]));
            draugr = new Draugr(std::stod(argv[2]), std::stoi(argv[3]));
            draugr->shoutPhrase(std::stoi(argv[1]));
        }
        delete draugr;
    }
    catch (...) {
        throw(std::out_of_range("Error"));
    }
}

int main(int argc, char** argv) {
    if (argc > 4 || argc < 2) {
        std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]" << std::endl;
        return 1;
    }
    Draugr* draugr = NULL;
    try {
        CheckFirstArg(std::string(argv[1]));
        DraugrShout(draugr, argv, argc);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
