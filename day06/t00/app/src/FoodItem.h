#pragma once

enum class FoodType {
    HoneyNut,
    Sweetroll,
    Applepie,
    PoisonesFood,
    Invalid
};

class FoodItem {
    public:
    virtual FoodType getType() = 0;
    virtual ~FoodItem() = default;
};

class ApplePie : public FoodItem {
    public:
    FoodType getType() override;
};

class HoneyNut : public FoodItem {
    public:
    FoodType getType() override;
};

class Sweetroll : public FoodItem {
    public:
    FoodType getType() override;
};

class PoisonedFood : public FoodItem {
    public:
    FoodType getType() override;
};
