#include "Room.h"
#include <iostream>
#include <algorithm>

Room::Room(const std::string& description) 
    : description_(description) {}

void Room::add_exit(const std::string& direction, Room* room){
    exits_[direction] = room;
}

void Room::add_item(std::unique_ptr<Item> item) {
    if (item) {
        items_in_room_.push_back(std::move(item));
    }
}


void Room::look() const {
    std::cout << "\n" << description_ << std::endl;
    if (!items_in_room_.empty()) {
        std::cout << "You see the following items on the ground:\n";
        for (const auto& item_ptr : items_in_room_) {
            std::cout << "- " << item_ptr->get_name() << std::endl;
        }
    }

    if (!exits_.empty()) {
        std::cout << "Exits are to the: ";
        for (const auto& pair : exits_) {
            std::cout << pair.first << " "; // pair.first 是方向
        }
        std::cout << std::endl;
    }
}


Room* Room::get_exit(const std::string& direction) {
    auto it = exits_.find(direction);
    if (it != exits_.end()){
        return it->second;
    }
    return nullptr;
}


std::unique_ptr<Item> Room::take_item(const std::string& item_name) {
    auto it = std::find_if(items_in_room_.begin(), items_in_room_.end(), 
        [&](const std::unique_ptr<Item>& item_ptr) {
            return item_ptr && item_ptr->get_name() == item_name;
        });

    if (it != items_in_room_.end()) {
        // 找到了物品
        std::unique_ptr<Item> found_item = std::move(*it); // 使用 move 轉移所有權
        items_in_room_.erase(it); // 從 vector 中移除現在為空的 unique_ptr
        return found_item; // 回傳物品的所有權
    }
    
    return nullptr; // 沒找到物品
}