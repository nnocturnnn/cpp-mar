#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier(std::string&& name) : Soldier(std::move(name), 100) {
    std::cout << "Stormcloak soldier was created" << std::endl;
}

StormcloakSoldier::~StormcloakSoldier() {
    std::cout << "Stormcloak soldier was deleted" << std::endl;
}
