// Character.cpp
#include "Character.h"
#include <iostream>
#include <fstream>
#include <limits>

// Constructor
Character::Character(const std::string& name, int health, float chestSize)
    : name(name), health(health), chestSize(chestSize) {}

// Getters
std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

float Character::getChestSize() const {
    return chestSize;
}

// Display character info
void Character::displayInfo() const {
    std::cout << "==============================\n";
    std::cout << "|      Character Profile      |\n";
    std::cout << "------------------------------\n";
    std::cout << "| Name       : " << name << "\n";
    std::cout << "| Health     : " << health << "\n";
    std::cout << "| Chest Size : " << chestSize << "\n";
    std::cout << "==============================\n";
}


// Save character data to a file
bool Character::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for saving: " << filename << std::endl;
        return false;
    }
    outFile << name << std::endl;
    outFile << health << std::endl;
    outFile << chestSize << std::endl;
    return true;
}

// Load character data from a file
bool Character::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        return false;
    }

    std::string loadedName;
    int loadedHealth;
    float loadedChestSize;

    if (!std::getline(inFile, loadedName)) {
        std::cerr << "Error reading character name from file: " << filename << std::endl;
        return false;
    }
    if (!(inFile >> loadedHealth)) {
        std::cerr << "Error reading character health from file: " << filename << std::endl;
        return false;
    }
    if (!(inFile >> loadedChestSize)) {
        std::cerr << "Error reading character chest size from file: " << filename << std::endl;
        return false;
    }

    name = loadedName;
    health = loadedHealth;
    chestSize = loadedChestSize;
    return true;
}
