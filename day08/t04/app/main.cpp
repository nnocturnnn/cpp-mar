#include "src/Serializer.h"
#include "src/SomeClass.h"

void deserialize(const std::string &path) {
    Serializer ser;
    if (path == "int") {
        auto obj = ser.deserialize<int>(path);
        std::cout << "Deserialized int: " << obj << std::endl;
    } else if (path == "float") {
        auto obj = ser.deserialize<float>(path);
        std::cout << "Deserialized float: " << obj << std::endl;
    } else {
        auto obj = ser.deserialize<SomeClass>(path);
        std::cout << "Deserialized ";
        obj.output();
        std::cout << std::endl;
    }
}

void serialize(const std::string &path, char *arg) {
    Serializer ser;
    if (path == "int") {
        int int_arg;
        try {
            size_t index;
            if (int_arg = std::stoi(arg, &index); arg[index] != '\0') {
                throw index;
            }
        } catch (...) {
            throw std::invalid_argument("error");
        }
        ser.serialize<int>(&int_arg, path);
        std::cout << "int: " << int_arg << " serialized" << std::endl;
    } else if (path == "float") {
        float float_arg;
        try {
            size_t index;
            if (float_arg = std::stof(arg, &index); arg[index] != '\0') {
                throw index;
            }
        } catch (...) {
            throw std::invalid_argument("error");
        }
        ser.serialize<float>(&float_arg, path);
        std::cout << "float: " << float_arg << " serialized" << std::endl;
    } else {
        throw std::invalid_argument("error");
    }
}

void serialize(const std::string &path, char *arg1, char *arg2, char *arg3) {
    Serializer ser;
    int int_arg;
    char char_arg;
    float float_arg;

    try {
        size_t index;
        if (int_arg = std::stoi(arg1, &index); arg1[index] != '\0') {
            throw index;
        }
        if (char_arg = arg2[0]; arg2[1] != '\0') {
            throw 1;
        }
        if (float_arg = std::stof(arg3, &index); arg3[index] != '\0') {
            throw index;
        }
    } catch (...) {
        throw std::invalid_argument("error");
    }
    SomeClass smcl(int_arg, char_arg, float_arg);
    ser.serialize<SomeClass>(&smcl, path);
    smcl.output();
    std::cout << " serialized" << std::endl;
}

int main(int ac, char **av) try {
    if (ac == 2) {
        deserialize(av[1]);
    } else if (ac == 3) {
        serialize(av[1], av[2]);
    } else if (ac == 5) {
        serialize(av[1], av[2], av[3], av[4]);
    } else {
        throw std::invalid_argument("usage: ./serializer [arg1] [arg2] [arg3] [arg4]");
    }
} catch (std::exception &ex) {
    std::cerr << ex.what() << std::endl;
    std::exit(EXIT_FAILURE);
}
