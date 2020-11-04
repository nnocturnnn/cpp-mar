#pragma once
#include <typeinfo>
#include <iostream>

namespace UniversalReferenceDeterminant {
template <typename T>
void determineReference(T&& obj) {
    if (*typeid(obj).name() == 'i') {
        std::cout << "int";
    } else if (*typeid(obj).name() == 'c') {
        std::cout << "char";
    } else if (*typeid(obj).name() == 'f') {
        std::cout << "float";
    } else if (*typeid(obj).name() == 'd') {
        std::cout << "double";
    }  else if (*typeid(obj).name() == 'l') {
        std::cout << "long";
    } else if (*typeid(obj).name() == 'j') {
        std::cout << "unsigned long";
    }
    if (std::is_lvalue_reference<T>::value) {
        std::cout << " is l-value reference" << std::endl;
    } else {
        std::cout << " is r-value reference" << std::endl;
    }
}

}
