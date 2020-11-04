#include "myFunction.h"

std::string CreateNewNameFile(char *old_name) {
    std::string new_name;
    std::string type;
    std::stringstream stream(old_name);
    getline(stream, new_name, '.');
    getline(stream, type);
    new_name += "_mod." + type;
    return new_name;
}
