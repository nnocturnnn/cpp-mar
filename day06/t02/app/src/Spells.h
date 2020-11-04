#pragma once

namespace Creatures {
    class Creature;
}

namespace Spells {

enum class SpellType {
    Healing,
    Equilibrium,
    Flames,
    Freeze,
    Fireball
};

class ISpell {
    public:
    virtual~ISpell() = default;
    virtual bool cast(Creatures::Creature &owner,
                      Creatures::Creature &other) = 0;
    virtual SpellType getType() const = 0;
};

}

class Healing : public Spells::ISpell {
    Spells::SpellType getType() const override;
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
};

class Equilibrium : public Spells::ISpell {
    Spells::SpellType getType() const override;
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
};

class Flames : public Spells::ISpell {
    Spells::SpellType getType() const override;
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
};

class Freeze : public Spells::ISpell {
    Spells::SpellType getType() const override;
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
};

class Fireball : public Spells::ISpell {
    Spells::SpellType getType() const override;
    bool cast(Creatures::Creature &owner, Creatures::Creature &other) override;
};

bool operator==(Spells::ISpell &lhs, Spells::ISpell &rhs);
