#include "squareValue.h"
#include <iostream>
#include <vector>


int main() {
    std::vector<int> sq = {1, 2, 3, 4, 5, 6, 7};
    squareValue(sq);
    for (auto& i : sq) {
        std::cout << i << " ";
    }
}
