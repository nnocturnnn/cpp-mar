#include "src/tesLibrary.h"
#include <string>
#include <map>

void InvalidArgument(std::string error) {
    std::cerr << error << std::endl;
}

bool CheckSizeCommand(std::vector<std::string>& commands, size_t size) {
    if (commands.size() == size) {
        return 1;
    }
    else {
        return 0;
    }
}

std::vector<std::string> ParseCommand(const std::string& command) {
    std::stringstream stream(command);
    std::vector<std::string> commands;
    std::string buffer;
    while(getline(stream, buffer, ' ')) {
        if (buffer.size() != 0) {
            commands.push_back(buffer);
        }
    }
    return commands;
}

void AddBook(std::map<std::string, std::string>& books, std::string& book) {
    std::string path = "./library/" + book;
    std::ifstream fin(path);
    if (fin.is_open()) {
        std::string content(std::istreambuf_iterator<char>(fin), {});
        books[book] = content;
        std::cout << book << " added\n";
    }
    else {
        InvalidArgument("invalid book");
    }
}

void ListBooks(std::map<std::string, std::string>& books) {
    for (const auto& b : books) {
        std::cout << b.first << std::endl;
    }
}

void ReadBook(std::map<std::string, std::string>& books, std::string book) {
    if (books.count(book) == 1) {
        std::cout << books[book] << std::endl;
    }
    else {
        InvalidArgument("invalid book");
    }
}

void DeleteBook(std::map<std::string, std::string>& books, std::string book) {
    if (books.count(book) == 1) {
        books.erase(book);
        std::cout << book << " deleted\n";
    }
    else {
        InvalidArgument("invalid book");
    }
}

void ExecutionCommand(std::map<std::string, std::string>& books,
        std::vector<std::string>& commands) {
    if (commands[0] == "add" && CheckSizeCommand(commands, 2) == 1) {
        AddBook(books, commands[1]);
    }
    else if (commands[0] == "delete" && CheckSizeCommand(commands, 2) == 1) {
        DeleteBook(books, commands[1]);
    }
    else if (commands[0] == "read" && CheckSizeCommand(commands, 2) == 1) {
        ReadBook(books, commands[1]);
    }
    else if (commands[0] == "list" && CheckSizeCommand(commands, 1) == 1) {
        ListBooks(books);
    }
    else if (commands[0] == "quit"  && CheckSizeCommand(commands, 1) == 1) {
        std::cout << "bye" << std::endl;
        exit(0);
    }
    else {
        InvalidArgument("invalid command");
    }
}

int main() {
    std::map<std::string, std::string> books;
    try {
        while(true) {
            std::cout << "enter command:> ";
            std::string command;
            std::vector<std::string> commands;
            getline(std::cin, command);
            commands = ParseCommand(command);
            ExecutionCommand(books, commands);
        }
    }
    catch (...) {
        return 1;
    }
    return 0;
}
