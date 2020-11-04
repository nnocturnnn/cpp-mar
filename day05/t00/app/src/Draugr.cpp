#include "Draugr.h"

Draugr::Draugr() : m_health(100), m_frostResist(50) {

}
void Draugr::shoutPhrase(int shoutNumber) const {
    std::cout << "Draugr (100 health, 50% frost resist) shouts:" << std::endl;
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
