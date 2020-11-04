#include "validate.h"

bool ValidateCin(void) {
    if (std::cin.peek() != '\n') {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cerr << "Invalid command.\n";
        return 1;
    }
    return 0;
}

bool ValidateItem(const std::string& it) {
    if (it.size() != 1 || (it[0] != 'w' && it[0] != 'f'
        && it[0] != 'a' && it[0] != 'p')) {
        std::cerr << "Invalid item.\n";
        return 1;
    }
    return 0;
}
