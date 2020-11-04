#include "FoodItem.h"

//FoodItem::~FoodItem() {
//
//}

FoodType ApplePie::getType() {
    return FoodType::Applepie;
}

FoodType HoneyNut::getType() {
    return FoodType::HoneyNut;
}

FoodType Sweetroll::getType() {
    return FoodType::Sweetroll;
}

FoodType PoisonedFood::getType() {
    return FoodType::PoisonesFood;
}

