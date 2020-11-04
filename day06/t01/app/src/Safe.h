#pragma once
#include "Container.h"

class Safe : public Container {
    public:
    Safe(bool isLocked, LockpickDifficulty difficulty)
        : Container(isLocked, difficulty) {}
    std::string name() const override {return "Safe";}
};
