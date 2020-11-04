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

void DeletePunctuationMarks(std::string& line) {
    std::string marks = ",.?!";
    line.erase(remove_if(line.begin(), line.end(), [marks](char a) {
        return (marks[0] == a || marks[1] == a
                || marks[2] == a || marks[3] == a);
    }), line.end());
}
