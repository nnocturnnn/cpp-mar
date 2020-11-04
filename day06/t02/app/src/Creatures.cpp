#include "Creatures.h"

Creatures::Creature::Creature(std::string &&name)
    : m_name(std::move(name)), m_health(100), m_mana(100){
    std::cout << m_name << " was born!" << std::endl;
}

Creatures::Creature::~Creature() {
    for (auto& spell : m_spells) {
        delete spell;
    }
}

int Creatures::Creature::getMana() const {
    return m_mana;
}


int Creatures::Creature::getHealth() const {
    return m_health;
}

std::string Creatures::Creature::getName() const {
    return m_name;
}

void Creatures::Creature::setMana(int mana) {
    m_mana = mana;
}

void Creatures::Creature::setHealth(int health) {
    m_health = health;
}

bool HasSpell(std::set<Spells::ISpell *>& m_spells, Spells::ISpell *spell) {
    if (spell != nullptr && count_if(m_spells.begin(),
                                     m_spells.end(),
                                     [spell](const Spells::ISpell *m_spell) {
                                         return spell->getType()
                                             == m_spell->getType();
                                     })) {
        return true;
    }
    return false;
}

std::string getNameSpell(const Spells::SpellType type) {
    if (type == Spells::SpellType::Healing) {
        return "healing";
    } else if (type == Spells::SpellType::Flames) {
        return "flames";
    } else if (type == Spells::SpellType::Fireball) {
        return "fireball";
    } else if (type == Spells::SpellType::Freeze) {
        return "freeze";
    } else if (type == Spells::SpellType::Equilibrium) {
        return "equilibrium";
    } else {
        return "invalid <name spell>";
    }
}

void Creatures::Creature::learnSpell(Spells::ISpell *spell) {
    if (spell != nullptr && !HasSpell(m_spells, spell)) {
        m_spells.insert(spell);
        std::cout << m_name << " has learned " << getNameSpell(spell->getType()) << " spell successfully!" << std::endl;
    } else {
        std::cout << m_name << " already know " << getNameSpell(spell->getType()) << " spell!" << std::endl;
    }
}

Spells::ISpell* getSpell(std::set<Spells::ISpell *>& m_spells, const Spells::SpellType type) {
    auto buffer = find_if(m_spells.begin(), m_spells.end(), [type](const Spells::ISpell *spell) {
        return spell->getType() == type;
    });
    if (buffer != m_spells.end()) {
        return *buffer;
    } else {
        return nullptr;
    }
}

void Creatures::Creature::castSpell(const Spells::SpellType type,
                                    Creature &creature) {
    auto spell = getSpell(m_spells, type);
    if (spell == nullptr) {
        std::cout << getNameSpell(type) << " spell is not learned by " << m_name << std::endl;
    } else if (spell->getType() == type && spell->cast(*this, creature)) {
        std::cout << m_name << " casted " << getNameSpell(type) << " spell on " << creature.getName() << std::endl;
    } else {
        std::cout << m_name << " can't cast " << getNameSpell(type) << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Creatures::Creature& creature) {
    os << creature.getName() << " : " << creature.getHealth() << " HP, " << creature.getMana() << " MP.";
    return os;
}

Imperial::Imperial(std::string &&name) : Creatures::Creature(std::move(name)) {
}

void Imperial::sayPhrase() const {
    std::cout << "I am " << getName() <<", Imperial soldier! Stop right here!" << std::endl;
}

Redguard::Redguard(std::string &&name) : Creatures::Creature(std::move(name)) {
}

void Redguard::sayPhrase() const {
    std::cout << "I am " << getName() << " from Redguards, wanna trade?" << std::endl;
}
