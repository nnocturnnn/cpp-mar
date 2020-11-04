#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <iterator>

template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> out(std::cout, "\n");
    std::copy(std::begin(container), std::end(container), out);
}
