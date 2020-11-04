#pragma once
#include <iostream>
#include <vector>
#include <string>

class Draugr {
    public:
    Draugr();
    explicit Draugr(int frostResist);
    explicit Draugr(double health, int frostResist = 50);
    explicit Draugr(Draugr& other);
    explicit Draugr(Draugr&& other);
    void shoutPhrase(int shoutNumber) const;
    void setName(const std::string&& name);

    private:
    std::string m_name;
    double m_health;
    const int m_frostResist;
};
