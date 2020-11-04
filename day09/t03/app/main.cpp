#include "src/Worker.h"
#include "src/ClassWithAtomic.h"
#include <string>
#include <iostream>

static void Validate(int ar, char **argv, int& addValue, int& subtractValue, int& pushSize) {
    if (ar != 4) {
        std::cerr << "usage: classWithAtomic [add] [subtract] [size]" << std::endl;
        exit(EXIT_FAILURE);
    }
    try {
        size_t index = 0;
        if (addValue = std::stoi(argv[1], &index); argv[1][index] != '\0') {
            throw index;
        } else if (subtractValue = std::stoi(argv[2], &index); argv[2][index] != '\0') {
            throw index;
        } else if (pushSize = std::stoi(argv[3], &index); argv[3][index] != '\0') {
            throw index;
        }
    }
    catch (std::exception& e) {
        std::cerr << "usage: classWithAtomic [add] [subtract] [size]" << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv) {
    int addValue;
    int subtractValue;
    int pushSize;
    Validate(argc, argv, addValue, subtractValue, pushSize);
    Worker worker;
    ClassWithAtomic obj;
    worker.startNewThread(&ClassWithAtomic::addToInt, &obj, addValue);
    worker.startNewThread(&ClassWithAtomic::subtractFromInt, &obj, subtractValue);
    for (auto i = 0; i < pushSize; ++i) {
        worker.startNewThread(&ClassWithAtomic::pushToVector, &obj, i);
    }
    for (auto i = 1; i <= pushSize; ++i) {
        if (i % 2 == 0) {
            worker.startNewThread(&ClassWithAtomic::eraseFromVector, &obj, i);
        }
    }
    worker.joinAllThreads();
    std::cout << "Result: " << obj.getInt() << std::endl;
    auto vec= obj.getVector();
    std::cout<< "Size of vector: "<< vec.size() << std::endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout<< vec[i];
        if (i != vec.size() - 1) {
            std::cout<< " "  ;
        } else {
            std::cout<< std::endl;
        }
    }
}
