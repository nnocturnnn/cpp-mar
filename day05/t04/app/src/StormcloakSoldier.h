#pragma once
#include "Soldier.h"

class ImperialSoldier;
class StormcloakSoldier : public Soldier {
    public:
    StormcloakSoldier(std::string&& name);
    ~StormcloakSoldier() override;
};
