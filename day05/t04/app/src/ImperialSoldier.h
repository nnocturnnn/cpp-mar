#pragma once
#include <iostream>
#include "Soldier.h"

class ImperialSoldier final : public Soldier {
    public:
    ImperialSoldier(std::string&& name);
    ~ImperialSoldier() override;
    void consumeDamage(int amount);
};
