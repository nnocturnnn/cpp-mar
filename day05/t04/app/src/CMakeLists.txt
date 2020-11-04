cmake_minimum_required(VERSION 3.1)

project(src LANGUAGES CXX)
add_library(src
        Weapon.cpp
        Soldier.cpp
        Axe.cpp
        ImperialSoldier.cpp
        StormcloakSoldier.cpp
        Sword.cpp)
