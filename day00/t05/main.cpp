#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "usage:./automaton [name] [level] [health] [stamina]" << std::endl;
    }
    else {
        auto name = argv[1];
        try {
            auto level = std::stoi(argv[2]);
        }
        catch (std::exception &e) {
            std::cerr << "Invalid argument: " << argv[2] << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            auto health = std::stof(argv[3]);
        }
        catch (std::exception &e) {
            std::cerr << "Invalid argument: " << argv[3] << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            auto stamina = std::stod(argv[4]);
        }
        catch (std::exception &e) {
            std::cerr << "Invalid argument: " << argv[4] << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << "Name = " << argv[1] << "\nLevel = " << argv[2] << "\nHealth = " << argv[3]
                  << "\nStamina = " << argv[4] << std::endl;
    }
    return 0;
}
