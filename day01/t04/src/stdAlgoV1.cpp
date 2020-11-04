#include "stdAlgoV1.h"

//bool CheckValidLine(std::string data) {
//    std::vector<std::string> lines;
//    std::stringstream in(data);
//    std::string line;
//    while(getline(in, line, ' ')) {
//        if (line.size() != 0)
//            lines.push_back(line);
//    }
//    if (lines.size() < 3) {
//        return false;
//    }
//    else {
//        return true;
//    }
//}

int ReadFile (std::forward_list<std::string>& list, std::ifstream& fin) {
    std::string data;
    int size = 0;
    while (getline(fin,data, '\n')) {
//        if (CheckValidLine(data)) {
//            std::cerr << "1\n";
//            throw (std::invalid_argument(""));
//        }
        size++;
        list.push_front(data);
    }
    if (size == 0) {
        throw(std::invalid_argument(""));
    }
    return size;
}

void OutInfo(std::forward_list<std::string>& list, int& size) {
    std::cout << "size: " << size << std::endl;
    std::string contains = std::any_of(list.begin(), list.end(), [](std::string& name) {
        if (name.find("rich") == std::string::npos) {
            return 0;
        }
        else {
            return 1;
        }}) == 0 ? "false" : "true";
    std::cout << "contains 'rich': " << contains << std::endl;
    contains = std::none_of(list.begin(), list.end(), [](std::string& name) {
        return name.size() == 15; }) == 1 ? "true" : "false";
    std::cout << "none of lengths is 15: " << contains << std::endl;
    contains = std::all_of(list.begin(), list.end(), [](std::string& name) {
        std::string buffer {name.end() - 3, name.end()};
        return buffer == "vel"; }) == 0 ? "false" : "true";
    std::cout << "all end with 'vel': " << contains << std::endl;
    std::cout << "not contains 'mel': " << count_if(list.begin(), list.end(), [](std::string& name) {
        if (name.find("mel") == std::string::npos) {
            return 1;
        }
        else return 0;}) << std::endl;
}
