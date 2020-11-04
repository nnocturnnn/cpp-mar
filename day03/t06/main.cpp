#include "isPalindrome.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<int> i = {1, 2, 3, 1};
	std::vector<std::string> a = {"as", "ab", "ac", "ab", "as"};
	std::cout << isPalindrome(i.begin(), i.end()) << std::endl;
	std::cout << isPalindrome(a.begin(), a.end()) << std::endl;
}
