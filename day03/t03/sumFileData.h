#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

template <class T>
T sumFileData(const std::string& fileName) {
    std::ifstream fin(fileName);
    std::istream_iterator<T> end;
    std::istream_iterator<T> start (fin);

    T sum = 0;
    while(start != end) {
        sum += *start;
        start++;
    }
    fin.close();
    return sum;
}
