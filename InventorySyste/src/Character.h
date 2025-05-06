#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <fstream>

class Character {
    private:
        std::string name;
        int health;
        float chestSize;

    public:
        Character(const std::string& name = "Unknown", int health = 100, float chestSize = 0.0f);
        std::string getName() const;
        int getHealth() const;
        float getChestSize() const;

        void displayInfo() const;
        bool saveToFile(const std::string& filename) const;
        bool loadFromFile(const std::string& filename);
};


#endif