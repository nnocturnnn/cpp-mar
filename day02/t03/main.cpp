
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <regex>
#include <utility>


bool CheckLineAndAdd(std::multimap<std::string, std::string>& library, std::ifstream& stream) {
    std::string line;
    int count_line = 0;
    while(getline(stream, line)) {
        count_line++;
        if (line.empty()) {
            continue;
        }
        std::smatch result;
        if (std::regex_match(line, result, std::regex(R"lit(\s*"([^"]+)"\s*:\s*"([^"]+)"\s*)lit"))) {
            library.insert(std::make_pair(result.str(1), result.str(2)));
        }
        else {
            std::cerr << "Line " << count_line << " is invalid" << std::endl;
            return true;
        }
    }
    return false;
}

void PrintLibrary(std::multimap<std::string, std::string> &library, const std::string& author) {
    int count = 1;
    std::cout << author << ":\n";
    for (const auto& lib : library) {
        if (lib.first == author) {
            std::cout << " " << count++ << ". " << lib.second << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    std::multimap<std::string, std::string> library;
    if (argc == 2) {
        std::ifstream fin(argv[1]);
        if (fin.is_open()) {
            if (CheckLineAndAdd(library, fin)) {
                return 1;
            }
            for (auto iter = library.begin(); iter != library.end(); iter = library.upper_bound(iter->first) ) {
                PrintLibrary(library, iter->first);
            }
        }
        else {
            std::cerr << "error" << std::endl;
        }
    }
    else {
        std::cerr << "usage: ./tesLibrary [file_name]" << std::endl;
    }
    return 0;
}
