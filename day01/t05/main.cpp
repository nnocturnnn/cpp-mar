#include "src/stdAlgoV2.h"

int main(int argc, char** argv) {
    if (argc == 2 ) {
        std::forward_list<std::string> list;
        std::ifstream fin;
        fin.open(argv[1]);
        if (fin.is_open()) {
            try {
                ReadFile(list, fin);
                OutInfo(list, argv[1]);
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
        std::cerr << "usage: ./stdAlgoV2 [file_name]\n";
        return 1;
    }
    return 0;
}
