#include "src/stdAlgoV1.h"

int main(int argc, char** argv) {
    if (argc == 2 ) {
        std::forward_list<std::string> list;
        std::ifstream fin;
        fin.open(argv[1]);
        if (fin.is_open()) {
            try {
                int size = ReadFile(list, fin);
                OutInfo(list, size);
            }
            catch (...) {
                std::cerr << "error\n";
            }
        }
        else {
            std::cerr << "error\n";
        }
        fin.close();
    }
    else {
        std::cerr << "usage: ./stdAlgoV1 [file_name]\n";
        return 1;
    }
    return 0;
}
