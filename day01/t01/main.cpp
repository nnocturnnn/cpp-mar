#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool FindSubName(std::string name, std::string name_thiev) {
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    if (name.find(name_thiev, 0) != std::string::npos) {
        return 1;
    }
    return 0;
}

void CheckNameMove(std::vector<std::string>& name, std::vector<std::string>& thiev) {
    for (auto& n : name) {
        if (FindSubName(n, thiev[0]) || FindSubName(n, thiev[1])
            || FindSubName(n, thiev[2])) {
            std::cout << n << ", move along!\n";
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::vector<std::string> name;
        std::vector<std::string> thiev = {"mercer", "emer", "jim"};
        for (int i = 1; i < argc; ++i) {
            name.push_back(argv[i]);
        }
        CheckNameMove(name, thiev);
    }
    else {
        std::cerr << "usage: ./moveAlong [args]\n";
    }
    return 0;
}