#include "src/validate.h"
#include "src/command.h"

#include <vector>

int main() {
    std::vector<char> inventory;
    while (true) {
        std::cout << "Enter command:> ";
        std::string command;
        std::cin >> command;
        if (command == "insert") {
            Insert(inventory);
        }
        else if (command == "remove") {
            Remove(inventory);
        }
        else if (command == "show") {
            Show(inventory);
        }
        else if (command == "help") {
            Help();
        }
        else if (command == "exit") {
            if (ValidateCin()) {
                continue;
            }
            std::cout << "Bye.\n";
            break;
        }
        else {
            std::cerr << "Invalid command.\n";
            continue;
        }
    }
    return 0;
}