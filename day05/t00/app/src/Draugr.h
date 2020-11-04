#pragma once
#include <iostream>
#include <vector>
#include <string>

class Draugr {
    public:
    Draugr();
    void shoutPhrase(int shoutNumber) const;

    private:
    double m_health;
    const int m_frostResist;
};
