#include "command.h"
#include "validate.h"


void Insert(std::vector<char>& inventory) {
    std::string item;
    std::cin >> item;
    if (ValidateCin() || ValidateItem(item)) {
        return;
    }
    if (inventory.size() == 12) {
        std::cerr << "Inventory is full.\n";
    }
    else {
        inventory.push_back(item[0]);
        std::cout << item[0] << " was inserted.\n";
    }
}

void Remove(std::vector<char>& inventory) {
    std::string item;
    std::cin >> item;
    if (ValidateCin() || ValidateItem(item)) {
        return;
    }
    if (count(inventory.begin(), inventory.end(), item[0]) == 0) {
        std::cerr << "Invalid item.\n";
        return;
    }
    if (inventory.size() > 0) {
        inventory.erase(find(inventory.begin(), inventory.end(), item[0]));
        std::cout << item[0] << " was removed.\n";
    }
}

void Show(const std::vector<char>& inventory) {
    if (ValidateCin()) {
        return;
    }
    std::cout << "Inventory { ";
    for(const auto& i : inventory) {
        std::cout << i << " ";
    }
    if (inventory.size() < 12) {
        for (int i = 12 - inventory.size(); i > 0 ; --i) {
            std::cout << "- ";
        }
    }
    std::cout << "}\n";
}

void Help() {
    if (ValidateCin()) {
        return;
    }
    std::cout << "Available commands:\n1. insert <itemType>\n2. remove <itemType>\n"
                 "3. show inventory\n4. help\n5. exit\n";
}
