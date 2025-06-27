#include "Player.h"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& name, int health, int damage)
    : name_(name), health_(health), base_damage_(damage) {}


void Player::pickup_item(std::unique_ptr<Item> item) {
    if (item) {
        std::cout << name_ << " picked up " << item->get_name() << ".\n";
        inventory_.push_back(std::move(item));
    }
}

void Player::use_item(const std::string& item_name) {
    auto it = std::find_if(inventory_.begin(), inventory_.end(),
        [&](const std::unique_ptr<Item>& item_ptr){
            return item_ptr->get_name() == item_name;
        });
    
    if (it != inventory_.end()) {
        // 找到了物品
        (*it)->use(*this); // 呼叫物品的 use 方法，傳入當前 player 物件

        // HealthPotion 的 use 方法會呼叫 heal，但它不應該負責刪除自己
        // 我們假設消耗品 (如藥水) 使用後就消失
        // 為了簡化，我們先假設所有物品用完都會消失
        // （更好的設計是讓 use() 回傳一個 bool 來決定是否要刪除）
        inventory_.erase(it);
    } else {
        std::cout << "You don't have an item called '" << item_name << "'.\n";
    }
}


void Player::show_inventory() const {
    std::cout << "--- " << name_ << "'s Inventory ---\n";
    if (inventory_.empty()) {
        std::cout << "Inventory is empty.\n";
    } else {
        for (const auto& item_ptr : inventory_){
            std::cout << "- " << item_ptr->get_name() << ": " << item_ptr->get_description() << std::endl;
        }
    }
    std::cout << "--------------------------\n";
}

void Player::heal(int amount) {
    health_ += amount;
    std::cout << name_ << " health is now " << health_ << ".\n";
}

void Player::take_damage(int amount) {
    health_ -= amount;
    std::cout << name_ << " took " << amount << " damage. Health is now " << health_ << ".\n";
}

void Player::increase_damage(int amount) {
    base_damage_ += amount;
    std::cout << name_ << "'s base damage increased to " << base_damage_ << ".\n";
}

std::string Player::get_name() const { return name_; }
int Player::get_health() const { return health_; }

