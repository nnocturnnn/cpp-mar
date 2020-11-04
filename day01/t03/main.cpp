#include "src/vampireRabbits.h"

int main() {
    srand(time(0));
    std::list<Rabbit> rabbits;

    for (int i = 0; i < 10; ++i) {
        rabbits.push_back(CreateRabbit());
    }
    PrintPopulationRabbit(rabbits);
    while(rabbits.size() <= 1000 && rabbits.size() > 0) {
        sleep(1);
        IncreaseAgeRabbits(rabbits);
        KillRabbits(rabbits);
        BiteRabbits(rabbits);
        ReproductionRabbits(rabbits);
        PrintPopulationRabbit(rabbits);
    }
    return 0;
}
