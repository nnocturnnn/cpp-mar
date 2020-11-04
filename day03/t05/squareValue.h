#pragma once
#include <iostream>
#include <iterator>

template <class Container>
void squareValue(Container& container) {
    typename Container::iterator start = container.begin();
    typename Container::iterator end = container.end();

    for (auto iter = start; iter != end; ++iter) {
        *iter *= *iter;
    }
}
