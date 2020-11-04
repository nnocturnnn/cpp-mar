#include "Draugr.h"

Draugr::Draugr() : Draugr(100, 50) {
}

Draugr::Draugr(int frostResist) : Draugr(100, frostResist) {
}

Draugr::Draugr(double health, int frostResist)
    : m_health(health), m_frostResist(frostResist) {
    std::cout << "Draugr with " << m_health <<" health and " << m_frostResist
            << "% frost resist was born!" << std::endl;
}

Draugr::Draugr(Draugr& other) :Draugr (other.m_health, other.m_frostResist){
    std::cout << "Copy constructor was called" << std::endl;
}

Draugr::Draugr(Draugr&& other) : Draugr (std::move(other.m_health),
                                            std::move(other.m_frostResist)) {
    std::cout << "Move constructor was called" << std::endl;
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}

void Draugr::shoutPhrase(int shoutNumber) const {
    std::cout << "Draugr " << m_name << " (" << m_health << " health, " << m_frostResist
              << "% frost resist) shouts:\n";
    switch (shoutNumber) {
        case 0:
            std::cout << "Qiilaan Us Dilon!" << std::endl;
            break;
        case 1:
            std::cout << "Bolog Aaz, Mal Lir!" << std::endl;
            break;
        case 2:
            std::cout << "Kren Sosaal!" << std::endl;
            break;
        case 3:
            std::cout << "Dir Volaan!" << std::endl;
            break;
        case 4:
            std::cout << "Aar Vin Ok!" << std::endl;
            break;
        case 5:
            std::cout << "Unslaad Krosis!" << std::endl;
            break;
        case 6:
            std::cout << "Faaz! Paak! Dinok!" << std::endl;
            break;
        case 7:
            std::cout << "Aav Dilon!" << std::endl;
            break;
        case 8:
            std::cout << "Sovngarde Saraan!" << std::endl;
            break;
        }
}
