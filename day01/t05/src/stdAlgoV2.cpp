#include "stdAlgoV2.h"

std::string CreateNewNameFileWithMOD(std::string old_name) {
    size_t index = old_name.find_last_of('.');
    if (index == std::string::npos) {
        return old_name + "_mod";
    } else {
        return old_name.insert(index, "_mod");
    }
}

bool CheckValidLine(std::string data) {
    std::vector<std::string> lines;
    std::stringstream in(data);
    std::string line;
    while (getline(in, line, ' ')) {
        lines.push_back(line);
    }
    if (lines.size() == 1) {
        return false;
    } else {
        return true;
    }
}

void ReadFile(std::forward_list<std::string> &list, std::ifstream &fin) {
    std::string data;
    int size = 0;
    while (getline(fin, data, '\n')) {
        if (CheckValidLine(data)) {
            throw (std::invalid_argument(""));
        }
        size++;
        list.push_front(data);
    }
    if (size == 0) {
        throw (std::invalid_argument(""));
    }
}

void WriteNewFile(std::ofstream &fout, std::forward_list<std::string> &list) {
    for (auto &l : list) {
        fout << l << std::endl;
    }
}

void OutInfo(std::forward_list<std::string> &list, char *argv) {
    std::string new_name = CreateNewNameFileWithMOD(std::string(argv));
    std::ofstream fout(new_name);
    if (fout.is_open()) {
        list.remove_if([](std::string name) {
            return (name.find("c") != std::string::npos)
              || (name.find("b") != std::string::npos)
              || (name.find("l") != std::string::npos);
        });
        std::replace_if(list.begin(), list.end(), [](std::string &name) {
            return name.size() < 4;
        }, "Short one");
        std::replace_if(list.begin(), list.end(), [](std::string &name) {
            return name.size() > 10;
        }, "Long one");
        list.sort();
        list.unique();
        list.reverse();
        WriteNewFile(fout, list);
    } else {
        throw (std::invalid_argument(""));
    }
    fout.close();
}
