#include "outputAny.h"
#include <iostream>
#include <vector>
#include <set>
#include <list>

int main() {
    std::vector<int> i = {1, 2, 3, 4, 5, 6};
    std::set<int> i1 = {1, 2, 3, 4, 5, 6};
    std::list<int> i2 = {1, 2, 3, 4, 5, 6};

    std::vector<std::string> i3 = {"1", "2", "3", "4", "5", "6"};
    std::set<std::string> i4 = {"1", "2", "3", "4", "5", "6"};
    std::list<std::string> i5 = {"1", "2", "3", "4", "5", "6"};
    std::cout << "\n\ni\n-----------------------\n";
    outputAny(i);
    std::cout << "\n\ni1\n-----------------------\n";
    outputAny(i1);
    std::cout << "\n\ni2\n-----------------------\n";
    outputAny(i2);
    std::cout << "\n\ni3\n-----------------------\n";
    outputAny(i3);
    std::cout << "\n\ni4\n-----------------------\n";
    outputAny(i4);
    std::cout << "\n\ni5\n-----------------------\n";
    outputAny(i5);
}
