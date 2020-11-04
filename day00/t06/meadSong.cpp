#include "meadSong.h"

void MoreBottle(int number) {
    std::cout << number << BOTTLES << WALL << ", " << number << BOTTLES << ".\n";
    std::cout << TAKE_ONE << number - 1;
    number == 2 ? std::cout << BOTTLE : std::cout << BOTTLES;
    std::cout << WALL << ".\n\n";
}

void OneBottle(int number) {
    std::cout << number << BOTTLE << WALL << ", " << number << BOTTLE << ".\n";
    std::cout << TAKE_IT << NO_MO << BOTTLES << WALL << ".\n\n";
}

void ZeroBottle() {
    std::cout << "No more" << BOTTLES << WALL << ", " << NO_MO << BOTTLES << ".\n";
    std::cout << GO_TO << "99" << BOTTLES << WALL << ".\n";
}
void MeadSong(int number) {
    if (number > 1) {
        MoreBottle(number);
    }
    else if (number == 1){
        OneBottle(number);
    }
    else if (number == 0) {
        ZeroBottle();
    }
}