#include "visitTown.h"

void CheckStoi(int value, std::string data, size_t index) {
    if (data[index] != *data.end() || value < 0) {
        throw(std::invalid_argument(""));
    }
}

bool GetTown(Town& town, std::string data, char* argv, int i) {
    size_t index = 0;
    if (i > 2) {
        throw (std::invalid_argument(""));
    }
    if (data.empty()) {
        std::cerr << "Argument " << argv << " is not valid" << std::endl;
        return 1;
    }
    if (i == 0) {
        town.name = data;
    }
    else if (i == 1) {
        town.stamina = std::stoi(data, &index);
        CheckStoi(town.stamina, data, index);
    }
    else if (i == 2) {
        town.distance = std::stoi(data, &index);
        CheckStoi(town.distance, data, index);
    }
    return 0;
}

bool CheckArgument(std::deque<Town>& journey, char* argv) {
    std::stringstream stream(argv);
    Town town;
    std::string data;
    for (int i = 0; getline(stream, data, ','); i++) {
        if (GetTown(town, data, argv, i)) {
            return 1;
        }
    }
    town.position = journey.size();
    journey.push_back(town);
    return 0;
}

bool GetAllTown(std::deque<Town>& journey, char** argv, int argc) {
    for (int i = 1; i < argc; ++i) {
        if (CheckArgument(journey, argv[i])) {
            return 1;
        }
    }
    return 0;
}

bool VisitAll(std::deque<Town>& journey) {
    for (size_t i = 0; i < journey.size(); ++i) {
        int sum = std::accumulate(journey.begin(), journey.end(), 0, [](int sum, Town &town) {
            if (sum >= 0) {
                return sum + town.stamina - town.distance;
            } else {
                return sum;
            }
        });
        if (sum >= 0) {
            return 0;
        }
        else {
            Town& buff = journey.front();
            journey.pop_front();
            journey.push_back(buff);
        }
    }
    return 1;
}
