#include "Item.h"
#include <iostream>

Item::Item(std::string name, float weight):name(name), weight(weight) {}

Item::~Item() {
    std::cout << "Destroying item: " << name << std::endl;
}

std::string Item::getName() const{
    return name;
}

float Item::getWeight() const {
    return weight;
}
