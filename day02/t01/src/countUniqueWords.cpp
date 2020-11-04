#include "countUniqueWords.h"
#include "myFunction.h"

void ReadLineAndAdd(Words& words, std::string& data) {
    std::stringstream in(data);
    std::string line;
    while(getline(in, line, ' ')) {
        DeletePunctuationMarks(line);
        words.uniqueWords.insert(line);
        words.countUniqueWords.insert(line);
    }
}

void ReadFile (Words& words, std::ifstream& fin) {
    std::string data;
    while (getline(fin,data, '\n')) {
        ReadLineAndAdd(words, data);
    }
    if (words.uniqueWords.size() == 0) {
        throw(std::invalid_argument(""));
    }
}

void OutInfo(Words& words, char* argv) {
    std::string new_name = CreateNewNameFile(argv);
    std::ofstream fout(new_name);
    if (fout.is_open()) {
        for (const auto& uW : words.uniqueWords) {
            fout << uW << ": "
            << words.countUniqueWords.count(uW) << std::endl;
        }
    }
    else {
        throw (std::invalid_argument(""));
    }
    fout.close();
}
