#include "ImperialSoldier.h"

class Sword;
class StormcloakSoldier;

ImperialSoldier::ImperialSoldier() {
    m_health = 100;
}
void ImperialSoldier::setWeapon(Sword *sword) {
    m_weapon = sword;
}
void ImperialSoldier::attack(StormcloakSoldier &enemy) {
    enemy.consumeDamage(m_weapon->getDamage());
    std::cout << "Imperial soldier attacks and deals "
                << m_weapon->getDamage() << " damage" << std::endl;
    std::cout << "Stormcloak soldier consumes "
                << m_weapon->getDamage() << " of damage" << std::endl;
}
void ImperialSoldier::consumeDamage(int amount) {
    m_health -= amount;
}
int ImperialSoldier::getHealth() const {
    return m_health;
}

ImperialSoldier::~ImperialSoldier() {
    delete m_weapon;
}

