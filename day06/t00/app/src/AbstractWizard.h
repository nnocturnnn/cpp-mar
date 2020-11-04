#pragma once
#include <iostream>
#include "FoodItem.h"

class AbstractWizard {
    public:
    virtual ~AbstractWizard() = default;
    protected:
    virtual FoodType deductFoodType(FoodItem &other) = 0;
};

class MightyWizard : public AbstractWizard {
    public:
    MightyWizard(const std::string& name);
    FoodType deductFoodType(FoodItem &other) override;
    void checkFood(FoodItem &item);
    void checkFood(FoodItem *item);
    private:
    std::string m_name;
};
