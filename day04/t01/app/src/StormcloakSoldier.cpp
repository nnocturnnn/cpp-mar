#include "StormcloakSoldier.h"

StormcloakSoldier::StormcloakSoldier() {
    m_health = 100;
}

void StormcloakSoldier::consumeDamage(int amount) {
    m_health -= amount;
}

void StormcloakSoldier::attack(ImperialSoldier &enemy) {
    enemy.consumeDamage(m_weapon->getDamage());
    std::cout << "Stormcloak soldier attacks and deals "
                << m_weapon->getDamage() << " damage" << std::endl;
    std::cout << "Imperial soldier consumes "
                << m_weapon->getDamage() << " of damage" << std::endl;
}

int StormcloakSoldier::getHealth() const {
    return m_health;
}

void StormcloakSoldier::setWeapon(Axe *sword) {
    m_weapon = sword;
}

StormcloakSoldier::~StormcloakSoldier() {
    delete m_weapon;
}
