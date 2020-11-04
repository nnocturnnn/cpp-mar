#include "src/Worker.h"
#include <string>
#include <iostream>
#include <regex>

int main() {
    const auto strLambda = [](std::string&& str) { std::cout << str << std::endl; };
    Worker worker;
    worker.startWorker(strLambda, "Main thread 1");
    worker.joinThread();
    worker.startWorker(strLambda, "Main thread 2");
    worker.startWorker(strLambda, "Main thread 3");
    worker.joinThread();
    const auto testLambda = []() {
        for (auto i = 0; i < 100; i += 2) {
            --i; }
        std::cout << "testLambda" << std::endl;
    };
    worker.startWorker(testLambda);
    TestClass obj;
    worker.startWorker(&TestClass::testMember1, &obj);
    worker.startWorker(&TestClass::testMember2, &obj, 10);
    testLambda();
    return 0; }
