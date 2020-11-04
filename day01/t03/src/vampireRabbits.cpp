#include "vampireRabbits.h"

Rabbit CreateRabbit() {
    Rabbit rabbit;
    rabbit.age = 0;
    rabbit.isVampire = (rand() % 100) == 0 ? 1 : 0;
    if (rabbit.isVampire) {
        rabbit.gender = Gender::Male;
    }
    else {
        rabbit.gender = rand() % 2 ? Gender::Male : Gender::Female;
    }
    return rabbit;
}

void KillRabbits(std::list<Rabbit>& rabbits) {
    for (auto iter = rabbits.begin(); iter != rabbits.end();) {
        if ((iter->age > 3 && iter->isVampire == 0)
            || (iter->age > 8 && iter->isVampire == 1)) {
            iter = rabbits.erase(iter);
        }
        else {
            ++iter;
        }
    }
}

std::vector<int> CountPopulation(std::list<Rabbit>& rabbits) {
    std::vector<int> population(2);
    population[0] = count_if(rabbits.begin(), rabbits.end(), [](const Rabbit& rabbit) {
        return rabbit.gender == Gender::Male && rabbit.isVampire == 0;
    });

    population[1] = count_if(rabbits.begin(), rabbits.end(), [](const Rabbit& rabbit) {
      return rabbit.gender == Gender::Female && rabbit.isVampire == 0;
    });
    return population;
}

void PrintPopulationRabbit(std::list<Rabbit>& rabbits) {
    int male = count_if(rabbits.begin(), rabbits.end(), [](const Rabbit& rabbit) {
        return rabbit.gender == Gender::Male;
    });
    int female = rabbits.size() - male;
    int vampire = count_if(rabbits.begin(), rabbits.end(), [](const Rabbit& rabbit) {
        return rabbit.isVampire == 1;
    });
    std::cout << "Males = " << male << std::endl;
    std::cout << "Females = " << female << std::endl;
    std::cout << "Vampires = " << vampire << std::endl;
    std::cout << std::endl;
}

void IncreaseAgeRabbits(std::list<Rabbit>& rabbits) {
    for (auto & rabbit : rabbits) {
        ++(rabbit.age);
    }
}

void ReproductionRabbits(std::list<Rabbit>& rabbits) {
    std::vector<int> rabbits_data = CountPopulation(rabbits);
    size_t family = 0;

    rabbits_data[0] > rabbits_data[1] ? family = rabbits_data[1]
                                      : family = rabbits_data[0];
    for (size_t i = 0; i < family; ++i) {
        rabbits.push_back(CreateRabbit());
    }
}

void BiteRabbits(std::list<Rabbit>& rabbits) {
    int vampires = count_if(rabbits.begin(), rabbits.end(),
                            [](Rabbit &rabbit) {
                              return rabbit.isVampire == 1
                                  && rabbit.gender == Gender::Male;
                            });
    size_t counter = 0;

    for (int i = 0; i < vampires && counter < rabbits.size(); ++i) {
        auto it = std::next(rabbits.begin(), counter);

        if (it->isVampire == 0) {
            it->isVampire = 1;
            it->gender = Gender::Female;
        }
        else {
            --i;
        }
        counter++;
    }
}

