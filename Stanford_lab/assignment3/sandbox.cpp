// sandbox.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

#include "Player.h"
#include "Room.h"
#include "HealthPotion.h"
#include "Sword.h"

void sandbox() {
    // 1. 創建世界
    Room hall("You are in a grand hall. There are doors to the north and east.");
    Room library("You are in a dusty library. A health potion sits on a table. A door leads south.");
    Room armory("You are in an armory. A sharp sword is on a rack. A door leads west.");

    // 2. 連接世界
    hall.add_exit("north", &library);
    hall.add_exit("east", &armory);
    library.add_exit("south", &hall);
    armory.add_exit("west", &hall);

    // 3. 在房間放置物品
    library.add_item(std::make_unique<HealthPotion>("Health Potion", "A bubbling red liquid.", 20));
    armory.add_item(std::make_unique<Sword>("Steel Sword", "A simple but sturdy sword.", 5));

    // 4. 創建玩家
    Player player("Hero", 100, 10);
    Room* current_room = &hall;

    std::cout << "Welcome to Text Adventure, " << player.get_name() << "!\n";
    std::cout << "Type 'go [direction]', 'take [item]', 'use [item]', 'inventory', 'look', or 'quit'.\n";

    // 5. 遊戲主迴圈
    std::string line;
    while (true) {
        current_room->look(); // 顯示當前房間資訊
        std::cout << "> ";
        
        if (!std::getline(std::cin, line)) break; // 讀取玩家輸入

        std::stringstream ss(line);
        std::string command, arg;
        ss >> command; // 讀取第一個詞作為指令
        ss >> arg;     // 讀取第二個詞作為參數

        if (command == "quit") {
            break;
        } else if (command == "go") {
            Room* next_room = current_room->get_exit(arg);
            if (next_room) {
                current_room = next_room;
            } else {
                std::cout << "You can't go that way.\n";
            }
        } else if (command == "take") {
            std::unique_ptr<Item> item = current_room->take_item(arg);
            if (item) {
                player.pickup_item(std::move(item));
            } else {
                std::cout << "There is no '" << arg << "' here.\n";
            }
        } else if (command == "inventory") {
            player.show_inventory();
        } else if (command == "use") {
            player.use_item(arg);
        } else if (command == "look") {
            // `look` 會在迴圈開始時自動執行，但允許玩家手動刷新
        } else {
            std::cout << "I don't understand that command.\n";
        }
    }

    std::cout << "Thanks for playing!\n";
}