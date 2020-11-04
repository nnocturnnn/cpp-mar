#include "AbstractWizard.h"

MightyWizard::MightyWizard(const std::string& name) {
    m_name = name;
}

void MightyWizard::checkFood(FoodItem &item) {
    if (FoodType::HoneyNut == item.getType()) {
        std::cout << "Honey nut. Mmm, tasty!" << std::endl;
    } else if (FoodType::Sweetroll == item.getType()) {
        std::cout << "Sweetroll. Mmm, tasty!" << std::endl;
    } else if (FoodType::Applepie == item.getType()) {
        std::cout << "Apple pie. Ugh, not again!" << std::endl;
    } else if (FoodType::PoisonesFood == item.getType()) {
        std::cout << "Poison. Ugh, not again!" << std::endl;
    } else {
        std::cout << "<wtf>. Ugh, not again!" << std::endl;
    }
}

void MightyWizard::checkFood(FoodItem *item) {
    if (item == nullptr) {
        std::cout << "<wtf>. Ugh, not again!" << std::endl;
    } else {
      checkFood(*item);
    }
}

FoodType MightyWizard::deductFoodType(FoodItem &other) {
    return other.getType();
}
