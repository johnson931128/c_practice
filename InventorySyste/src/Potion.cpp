#include "Potion.h"
#include <iostream>

Potion::Potion(const std::string& name, float weight, int healAmount)
    : Item(name, weight), healAmount(healAmount) {}
Potion::~Potion(){
    std::cout << "Destroying Potion: " << name << std::endl;
}

int Potion::getHealAmount() const{
    return healAmount;
}

void Potion::use() const{
    std::cout << "You drink the " << name << " and recover " << healAmount << " HP!\n";
}