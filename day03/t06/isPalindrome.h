#pragma once


template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    for(auto iter = begin, riter = end - 1; iter != end; ++iter, --riter) {
    	if (*iter != *riter) {
    		return false;
    	}
    }
    return true;
}
