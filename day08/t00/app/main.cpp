#include "src/MoveManager.h"
#include "src/Player.h"
#include "src/Map.h"
#include <string>
#include <iostream>
#include <regex>

void CheckArgument(char** argv, int argc) {
    int width;
    int height;
    std::smatch result;
    std::regex regular("(^[0-9]*)|(^[0-9]+\\.?[0-9]+)");
    for (int i = 1; i < argc; ++i) {
        std::string line = argv[i];
        if (std::regex_match(line, result, regular)) {
            if (i == 1) {
                width = std::stoi(result[0]);
            } else {
                height = std::stoi(result[1]);
            }
        } else {
            std::cerr << "usage: ./smartPointers [width] [heigh]";
            exit(EXIT_FAILURE);
        }
    }
    if ((width < 5 || height < 5) || (width > 20 || height > 20)) {
        std::cerr << "Invalid map size" << std::endl;
        exit(EXIT_FAILURE);
    }
};

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "usage: ./smartPointers [width] [height]" << std::endl;
        exit(1);
    }
    try {
        CheckArgument(argv, argc);
    } catch (std::out_of_range &) {
        std::cerr << "Invalid map size" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::shared_ptr<Player> player(new Player);
    std::shared_ptr<Map> map(new Map(std::stoi(argv[1]), std::stoi(argv[2]), player));
    map->outputMap();
    std::shared_ptr<MoveManager> moveManager(new MoveManager(player, map));
    std::string line;
    std::cout << ":> ";
    while(getline(std::cin, line)) {
        if (line == "u" || line == "d" || line == "r" || line == "l") {
            moveManager->processInputAndMove(line);
        } else if (line == "e") {
            std::cout << ">" << std::endl;
            exit(EXIT_FAILURE);
        }
        else {
            std::cout << "Invalid input" << std::endl;
            map->outputMap();
        }
        std::cout << ":> ";
    }
}
