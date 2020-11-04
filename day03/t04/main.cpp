#include <iostream>
#include <set>
#include "outputContainer.h"

int main() {
    std::set<int> maps;
    std::string q = " place!";
    for (int i = 0; i < 10; ++i) {
        maps.insert(i);
    }
    outputContainer(maps);
}
