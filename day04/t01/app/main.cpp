#include <iostream>
#include "src/StormcloakSoldier.h"
#include "src/ImperialSoldier.h"
#include "src/Axe.h"
#include "src/Sword.h"

void InitSolders(StormcloakSoldier &Ssolder, ImperialSoldier &Isolder,
                 char **argv) {
    if (std::stoi(argv[1]) >= 10 && std::stoi(argv[1]) <= 20
        && std::stoi(argv[2]) >= 10 && std::stoi(argv[2]) <= 20) {
        auto *sword = new Sword(std::stoi(argv[1]));
        Axe *axe = new Axe(std::stoi(argv[2]));
        Ssolder.setWeapon(axe);
        Isolder.setWeapon(sword);
    } else {
        throw (std::invalid_argument(""));
    }
}

void OutPutWon(StormcloakSoldier &Ssolder, ImperialSoldier &Isolder) {
    if (Ssolder.getHealth() >= 0) {
        std::cout << "Stormcloack has won!\n";
    } else {
        std::cout << "Imperial has won!\n";
    }
}

int main(int argc, char *argv[]) {
    if (argc == 3) {
        StormcloakSoldier Ssolder;
        ImperialSoldier Isolder;
        try {
            InitSolders(Ssolder, Isolder, argv);
        } catch(...) {
            std::cerr << "Damage has to be in a range of 10-20 points.\n";
            return 1;
        }
        while (Ssolder.getHealth() >= 0 && Isolder.getHealth() > 0) {
            Isolder.attack(Ssolder);
            Ssolder.attack(Isolder);
            std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>"
                      << std::endl;
        }
        OutPutWon(Ssolder, Isolder);
    } else {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]"
                  << std::endl;
    }
}
