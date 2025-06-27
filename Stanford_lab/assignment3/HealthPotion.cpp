// HealthPotion.cpp
#include "HealthPotion.h"
#include "Player.h" // 這裡需要 Player 的完整定義，因為要呼叫它的成員函式
#include <iostream>

HealthPotion::HealthPotion(const std::string& name, const std::string& description, int heal_amount)
    : Item(name, description), heal_amount_(heal_amount) {}

void HealthPotion::use(Player& player) {
    player.heal(heal_amount_); // 假設 Player 有 heal 方法
    std::cout << "You used " << name_ << " and recovered " << heal_amount_ << " health!\n";
    // 這裡我們暫時無法實現「從物品欄移除自己」的功能，因為物品本身不知道自己在不在物品欄。這個邏輯應該由 Player 類別來處理。
}