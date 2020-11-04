#include "src/Worker.h"
#include "src/MultithreadedClass.h"
#include <string>
#include <iostream>
#include <regex>

void CheckArgument(int& addValue, int& subtractValue, int& count, char** argv) {
    size_t index = 0;
    if (addValue = std::stoi(argv[1], &index); argv[1][index] != '\0') {
        throw index;
    } else if (subtractValue = std::stoi(argv[2], &index); argv[2][index] != '\0') {
        throw index;
    } else if (count = std::stoi(argv[3], &index); argv[3][index] != '\0') {
        throw index;
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]" << std::endl;
        exit(EXIT_FAILURE);
    }
    int count;
    int addValue;
    int subtractValue;
    try {
        CheckArgument(addValue, subtractValue, count, argv);
    } catch (...) {

    }
    if (!(addValue <= 2000 && addValue >= -2000 && subtractValue <= 2000 && subtractValue >= -2000
        && count >=5 && count <= 10)) {
        std::cerr << "Incorrect values" << std::endl;
        exit(EXIT_FAILURE);
    }
    MultithreadedClass obj;
    Worker worker;
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
    }
    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::subtract,
                              &obj,
                              subtractValue);
    }

    worker.joinAllThreads();
    std::cout << obj.getInt() << std::endl;
}
