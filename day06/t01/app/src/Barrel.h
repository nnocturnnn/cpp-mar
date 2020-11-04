#pragma once
#include "Container.h"

class Barrel : public Container {
    public:
    Barrel() : Container(false, LockpickDifficulty::None) {};
    std::string name() const override {return "Barrel";}
};
