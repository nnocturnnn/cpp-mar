#include "Spells.h"
#include "Creatures.h"

/* Spells */

bool Healing::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 15) {
        owner.setHealth(owner.getHealth() + 10);
        owner.setMana(owner.getMana() - 15);
        return true;
    }
    else {
//        std::cout << owner.getName() << " can't cast healing!" << std::endl;
        return false;
    }
}

bool Equilibrium::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getHealth() > 25) {
        owner.setHealth(owner.getHealth() - 25);
        owner.setMana(owner.getMana() + 25);
        return true;
    }
    else {
//        std::cout << owner.getName() << " can't cast healing!" << std::endl;
        return false;
    }
}

bool Flames::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 14) {
        other.setHealth(other.getHealth() - 8);
        owner.setMana(owner.getMana() - 14);
        return true;
    }
    else {
//        std::cout << owner.getName() << " can't cast healing!" << std::endl;
        return false;
    }
}

bool Freeze::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 30) {
        other.setHealth(other.getHealth() - 20);
        owner.setMana(owner.getMana() - 30);
        return true;
    }
    else {
//        std::cout << owner.getName() << " can't cast healing!" << std::endl;
        return false;
    }
}

bool Fireball::cast(Creatures::Creature &owner, Creatures::Creature &other) {
    if (owner.getMana() >= 50) {
        other.setHealth(other.getHealth() - 40);
        owner.setMana(owner.getMana() - 50);
        return true;
    }
    else {
//        std::cout << owner.getName() << " can't cast healing!" << std::endl;
        return false;
    }
}

/* Get Type */
Spells::SpellType Healing::getType() const {
    return Spells::SpellType::Healing;
}

Spells::SpellType Equilibrium::getType() const {
    return Spells::SpellType::Equilibrium;
}

Spells::SpellType Flames::getType() const {
    return Spells::SpellType::Flames;
}

Spells::SpellType Freeze::getType() const {
    return Spells::SpellType::Freeze;
}

Spells::SpellType Fireball::getType() const {
    return Spells::SpellType::Fireball;
}

bool operator==(Spells::ISpell &lhs, Spells::ISpell &rhs) {
    return lhs.getType() == rhs.getType();
}
