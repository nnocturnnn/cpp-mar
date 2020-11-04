#pragma once
#include "Container.h"

class Chest : public Container {
    public:
    Chest(bool isLocked, LockpickDifficulty difficulty)
        : Container(isLocked, difficulty) {}
    std::string name() const override {return "Chest";}
};
