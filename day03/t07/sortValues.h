#pragma once

#include <algorithm>
#include <vector>

template<class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin,
                                RandomAccessIterator end) {
    int length = end - begin;
    if (length < 2)
        return begin;
    std::vector<typename RandomAccessIterator::value_type> first(begin, end);
    std::vector<typename RandomAccessIterator::value_type> second;

    auto first_3 = first.begin() + length / 3;
    auto second_3 = first.begin() + length * 2 / 3;

    sortValues(first.begin(), first_3);
    sortValues(first_3, second_3);
    sortValues(second_3, first.end());

    std::merge(first.begin(),
               first_3,
               first_3,
               second_3,
               std::back_inserter(second));
    std::merge(second.begin(), second.end(), second_3, first.end(), begin);
    return begin;
}

