#include "src/Worker.h"
#include "src/MultithreadedFileHandler.h"
#include <string>
#include <iostream>
#include <fstream>
#include <regex>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "usage: ./multithreadedFileHandler [file1] [file2]" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        std::ifstream fin1(argv[1]);
        std::ifstream fin2(argv[2]);
        if (!fin1.is_open() && !fin2.is_open()) {
            std::cerr << "error" << std::endl;
        } else {
            fin1.close();
            fin2.close();
        }
    }
    MultithreadedFileHandler m;
    Worker worker;
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &m, std::string(argv[1]));
    worker.startNewThread(&MultithreadedFileHandler::processFile, &m);

    worker.startNewThread(&MultithreadedFileHandler::loadFile, &m, std::string(argv[2]));
    worker.startNewThread(&MultithreadedFileHandler::processFile, &m);
    worker.joinAllThreads();

}
