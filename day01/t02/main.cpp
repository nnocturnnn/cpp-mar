#include "src/visitTown.h"

int main(int argc, char** argv) {
    std::deque<Town> journey;
    if (argc == 1) {
        std::cerr << "usage: ./visitAll [[name,stamina,distance] ...]\n";
        return 1;
    }
    try {
        if (GetAllTown(journey, argv, argc)) {
            return EXIT_FAILURE;
        }
    }
    catch (...) {
        std::cerr << "Argument " << argv[journey.size() + 1] << " is not valid" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (VisitAll(journey)) {
        std::cerr << "Mission: Impossible\n";
        return 1;
    }
    for (auto& j : journey) {
        std::cout << j.position << ". " << j.name << std::endl;
    }
    return 0;
}
