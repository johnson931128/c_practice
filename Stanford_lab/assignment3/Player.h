// Player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include "Item.h"

class Player {
private:
    std::string name_;
    int health_;
    int base_damage_;
    std::vector<std::unique_ptr<Item>> inventory_;

public:
    Player(const std::string& name, int health, int damage);

    void pickup_item(std::unique_ptr<Item> item);
    void use_item(const std::string& item_name);
    void show_inventory() const;
    void heal(int amount);
    void take_damage(int amount);
    void increase_damage(int amount);

    // Getters
    std::string get_name() const;
    int get_health() const;
};

#endif // PLAYER_H