#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <unistd.h>

enum class Gender {
    Male,
    Female
};

struct Rabbit {
    Gender gender;
    bool isVampire;
    int age;
};

Rabbit CreateRabbit();
void KillRabbits(std::list<Rabbit>& rabbits);
std::vector<int> CountPopulation(std::list<Rabbit>& rabbits);
void BiteRabbits(std::list<Rabbit>& rabbits);
void PrintPopulationRabbit(std::list<Rabbit>& rabbits);
void IncreaseAgeRabbits(std::list<Rabbit>& rabbits);
void ReproductionRabbits(std::list<Rabbit>& rabbits);

