#include <iostream>
#include "src/Dragonborn.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./dragonborn [action]" << std::endl;
        return 1;
    }
    try {
        const static std::map<std::string, Dragonborn::Actions> table = {
            {"shout", Dragonborn::Actions::Shout},
            {"magic", Dragonborn::Actions::Magic},
            {"weapon", Dragonborn::Actions::Weapon}
        };
        Dragonborn dragon;
        dragon.executeAction(table.at(argv[1]));
    }
    catch (...){
        std::cerr << "Invalid action" << std::endl;
        return 1;
    }
    return 0;
}
