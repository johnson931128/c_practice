#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& name, float weight, int damage)
    : Item(name, weight), damage(damage) {}

Weapon::~Weapon() {
    std::cout << "Destroying Weapon: " << name << std::endl;
}

int Weapon::getDamage() const {
    return damage;
}

void Weapon::use() const{
    std::cout << "You swing the " << name << " and deal " << damage << " damage!" << std::endl;
}
