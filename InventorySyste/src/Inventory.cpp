#include "Inventory.h"
#include <iostream>
#include <iomanip>

Inventory::Inventory(int capacity) : capacity(capacity), count(0) {
    items = new Item*[capacity];
}

Inventory::~Inventory() {
    for (int i = 0; i < count; ++i) {
        delete items[i];
    }
    delete [] items;
}

#include "Inventory.h"
#include <iostream>

// 實作 addItem
bool Inventory::addItem(Item* item) {
    if (count < capacity) {
        items[count++] = item;
        return true;
    } else {
        std::cout << "Inventory is full!" << std::endl;
        return false;
    }
}


bool Inventory::removeItem(int index){
    if (index < 0 || index >= count) {
        std::cout << "Ivalid index. \n";
        return false;
    }

    delete items[index];
    for (int i = index; i < count - 1; ++i){
        items[i] = items[i + 1];
    }
    --count;
    return true;
}

int Inventory::getCount() const {
    return count;
}


void Inventory::showInventory() const {
    if (count == 0){
        std::cout << "Inventory is empty.\n";
        return;
    }
    std::cout << "========================================\n";
    std::cout << "| Id |        Name        |  Weight(kg) |\n";
    std::cout << "----------------------------------------\n";
    for (int i = 0; i < count; ++i){
        std::cout << "| "
                  << std::setw(2) << i << " | "
                  << std::setw(16) << std::left << items[i]->getName() << " | "
                  << std::setw(10) << std::right << items[i]->getWeight() << " |\n";
    }
    std::cout << "========================================\n";
}


void Inventory::useItem(int index) const{
    if (index < 0 || index >= count) {
        std::cout << "Invalid index.\n";
        return;
    }

    items[index]->use(); //polymophism
}

