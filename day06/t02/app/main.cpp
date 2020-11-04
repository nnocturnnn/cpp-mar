#include <iostream>
#include "src/Creatures.h"

int main() {
    Redguard Jojo("Jojo");
    Jojo.sayPhrase();
    Imperial Dio("Dio");
    Dio.sayPhrase();
    std::cout << Jojo << std::endl;
    std::cout << Dio << std::endl;
    Healing *heal = new Healing;
    Fireball *fireball = new Fireball;
    Equilibrium *equilibrium = new Equilibrium;
    Flames *flames = new Flames;
    Freeze *freeze = new Freeze;
    Jojo.learnSpell(heal);
    Jojo.learnSpell(fireball);
    Dio.learnSpell(equilibrium);
    Dio.learnSpell(equilibrium);
    Jojo.castSpell(Spells::SpellType::Fireball, Dio);
    Dio.castSpell(Spells::SpellType::Equilibrium, Jojo);
    std::cout << Jojo << std::endl;
    std::cout << Dio << std::endl;
    Dio.castSpell(Spells::SpellType::Flames, Jojo);
    Dio.learnSpell(flames);
    Dio.learnSpell(freeze);
    Jojo.castSpell(Spells::SpellType::Healing, Jojo);
    Dio.castSpell(Spells::SpellType::Freeze, Jojo);
    std::cout << Jojo << std::endl;
    std::cout << Dio << std::endl;
    Jojo.castSpell(Spells::SpellType::Fireball, Dio);
    Jojo.castSpell(Spells::SpellType::Fireball, Dio);
    Jojo.castSpell(Spells::SpellType::Fireball, Dio);
    std::cout << Jojo << std::endl;
    std::cout << Dio << std::endl;
    return 0;
}
