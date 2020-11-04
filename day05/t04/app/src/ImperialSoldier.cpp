#include "ImperialSoldier.h"

ImperialSoldier::ImperialSoldier(std::string&& name) : Soldier(std::move(name), 100){
    std::cout << "Imperial soldier was created" << std::endl;
}

ImperialSoldier::~ImperialSoldier() {
    std::cout << "Imperial soldier was deleted" << std::endl;
}

