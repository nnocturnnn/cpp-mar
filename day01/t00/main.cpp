#include <iostream>
#include <array>

int main(int argc, char* argv[]) {
    if (argc == 6) {
        std::array<std::string, 5> container;
        for (size_t i = 1, j = 0; j < container.size(); ++i, ++j) {
            container[j] = argv[i];
        }
        sort(container.begin(), container.end());
        for (size_t i = 0; i < container.size(); ++i) {
            if (i == container.size() - 1) {
                std::cout << container[i] << std::endl;
            }
            else {
                std::cout << container[i] << " ";
            }
        }
    }
    else {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5\n";
    }
    return 0;
}