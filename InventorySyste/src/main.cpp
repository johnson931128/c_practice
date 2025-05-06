// main.cpp
#include "Weapon.h"
#include "Potion.h"
#include "Inventory.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <limits>
#include <memory>

// --- Helper function for robust integer input ---
int getIntegerInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.good()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cerr << "Invalid input. Please enter a whole number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

float getFloatInput(const std::string& prompt) {
    float value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.good()) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cerr << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int main() {
    Character* myCharacter = nullptr;
    Inventory* myInventory = nullptr;
    bool gameRunning = true;

    while (gameRunning) {
        std::cout << "\n===========================\n";
        std::cout << "Welcome to xxx game\n";
        std::cout << "===========================\n";
        std::cout << "option :\n";
        std::cout << "1. create a character\n";
        std::cout << "2. exit the game\n";
        std::cout << "===========================\n";

        int mainChoice = getIntegerInput("Enter your choice: ");

        switch (mainChoice) {
        case 1: {
            if (myCharacter) {
                std::cout << "\nCreating a new character will discard the current one.\n";
                std::cout << "Are you sure? (y/n): ";
                char confirm;
                std::cin >> confirm;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (confirm != 'y' && confirm != 'Y') {
                    std::cout << "Character creation cancelled.\n";
                    break;
                }
            }
            delete myCharacter;
            myCharacter = nullptr;
            delete myInventory;
            myInventory = nullptr;

            std::string charName;
            int charHealth;
            float charChestSize;

            std::cout << "\n===========================\n";
            std::cout << "Create Your Character\n";
            std::cout << "===========================\n";
            std::cout << "Set your name: ";
            std::getline(std::cin, charName);
            charHealth = getIntegerInput("Set your health: ");
            charChestSize = getFloatInput("Set your chest size: ");

            myCharacter = new Character(charName, charHealth, charChestSize);
            std::cout << "\nCharacter '" << myCharacter->getName() << "' created!\n";
            myCharacter->displayInfo();

            if (myCharacter->saveToFile("character_data.txt")) {
                std::cout << "Character data saved to character_data.txt\n";
            } else {
                std::cerr << "Failed to save character data.\n";
            }

            myInventory = new Inventory(10);
            myInventory->addItem(new Weapon("Steel Sword", 5.0f, 30));
            myInventory->addItem(new Weapon("Battle Axe", 7.5f, 45));
            myInventory->addItem(new Potion("Healing Potion", 0.5f, 50));
            myInventory->addItem(new Potion("Mega Potion", 1.0f, 100));

            std::cout << "\nStarting with a basic inventory.\n";
            myInventory->showInventory();

            bool inInventoryMenu = true;
            while (inInventoryMenu) {
                std::cout << "\n===========================\n";
                std::cout << "     Inventory Menu\n";
                std::cout << "===========================\n";
                std::cout << "option :\n";
                std::cout << "1. Add a Basic Potion\n";
                std::cout << "2. Use item\n";
                std::cout << "3. Show inventory\n";
                std::cout << "4. Back to main menu\n";
                std::cout << "===========================\n";

                int inventoryChoice = getIntegerInput("Enter inventory choice: ");
                switch (inventoryChoice) {
                case 1:
                    std::cout << "\nAttempting to add a Basic Potion...\n";
                    if (myInventory->addItem(new Potion("Basic Potion", 0.2f, 20))) {
                        std::cout << "Basic Potion added.\n";
                    }
                    break;
                case 2:
                    if (myInventory->getCount() == 0) {
                        std::cout << "Inventory is empty, cannot use items.\n";
                        break;
                    }
                    std::cout << "\n--- Current Inventory for Usage ---\n";
                    myInventory->showInventory();
                    std::cout << "-----------------------------------\n";
                    {
                        int itemIndexToUse = getIntegerInput("Enter the index of the item to use: ");
                        myInventory->useItem(itemIndexToUse);
                    }
                    break;
                case 3:
                    std::cout << "\n=== Inventory ===\n";
                    myInventory->showInventory();
                    break;
                case 4:
                    std::cout << "\nReturning to main menu...\n";
                    inInventoryMenu = false;
                    break;
                default:
                    std::cout << "\nInvalid inventory choice. Please try again.\n";
                    break;
                }
            }
            break;
        }
        case 2:
            std::cout << "\nExiting game. Goodbye!\n";
            gameRunning = false;
            break;
        default:
            std::cout << "\nInvalid main menu choice. Please try again.\n";
            break;
        }
    }

    delete myCharacter;
    delete myInventory;
    return 0;
}
