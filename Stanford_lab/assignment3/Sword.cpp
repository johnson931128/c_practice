// Sword.cpp
#include "Sword.h"
#include "Player.h"
#include <iostream>

Sword::Sword(const std::string& name, const std::string& description, int damage)
    : Item(name, description), damage_(damage) {}

void Sword::use(Player& player) {
    player.increase_damage(damage_);
    std::cout << "You equipped the " << name_ << ". Your attacks are now stronger!\n";
}