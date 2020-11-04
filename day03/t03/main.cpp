#include "sumFileData.h"
#include <string>

int main(int argc, char** argv) {
    if (argc == 2)
        std::cout << sumFileData<double>(std::string(argv[1])) << std::endl;
    else {
        std::cerr << "Need file name!" << std::endl;
    }
}
