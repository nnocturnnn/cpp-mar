#pragma once
#include "LockpickDificulty.h"

class IOpenable {
    public:
    virtual bool tryToOpen (LockpickDifficulty item) = 0;
    virtual ~IOpenable() = default;
};

