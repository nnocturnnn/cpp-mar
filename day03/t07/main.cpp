#include "sortValues.h"
#include <iostream>


int main() {
	std::vector<int> name;
    for (int i = 1000000; i > 0 ; --i) {
        name.push_back(i);
    }
    sortValues(name.begin(), name.end());
	for(auto& n : name) {
		std::cout << n << std::endl;
	}
	return 0;
}
