#pragma once
#include "Creature.h"
#include "Human.h"
#include "Wolf.h"


class Werewolf: public Human, public Wolf {
    public:
    Werewolf();
    ~Werewolf();
};
