#include "uniqueWords.h"
#include "myFunction.h"

void DeletePunctuationMarks(std::string& line) {
    std::string marks = ",.?!";
    line.erase(remove_if(line.begin(), line.end(), [marks](char a) {
        return (marks[0] == a || marks[1] == a
                || marks[2] == a || marks[3] == a);
    }), line.end());
}

void ReadLineAndAdd(std::set<std::string>& uniqueWords, std::string& data) {
    std::stringstream in(data);
    std::string line;
    while(getline(in, line, ' ')) {
        DeletePunctuationMarks(line);
        uniqueWords.insert(line);
    }
}

void ReadFile (std::set<std::string>& uniqueWords, std::ifstream& fin) {
    std::string data;
    while (getline(fin,data, '\n')) {
        ReadLineAndAdd(uniqueWords, data);
    }
    if (uniqueWords.size() == 0) {
        throw(std::invalid_argument(""));
    }
}

void OutInfo(std::set<std::string>& uniqueWords, char* argv) {
    std::string new_name = CreateNewNameFile(argv);
    std::ofstream fout(new_name);
    if (fout.is_open()) {
        for (const auto& uW : uniqueWords) {
            fout << uW << std::endl;
        }
    }
    else {
        throw (std::invalid_argument(""));
    }
    fout.close();
}
