// Room.h
#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <map>
#include <memory> // for std::unique_ptr
#include "Item.h"

// 再次使用前向宣告，因為 Room 的出口會指向另一個 Room
class Room; 

class Room {
private:
    std::string description_;
    std::vector<std::unique_ptr<Item>> items_in_room_;
    // 使用原始指標 Room*，因為房間之間只是「關聯」，不互相「擁有」
    std::map<std::string, Room*> exits_;

public:
    explicit Room(const std::string& description);

    // 我們不需要自訂解構函式，因為 unique_ptr 會自動清理物品
    // 而 exits_ 中的原始指標我們不負責刪除

    void add_exit(const std::string& direction, Room* room);
    void add_item(std::unique_ptr<Item> item);
    void look() const;
    Room* get_exit(const std::string& direction);
    std::unique_ptr<Item> take_item(const std::string& item_name);
};

#endif // ROOM_H