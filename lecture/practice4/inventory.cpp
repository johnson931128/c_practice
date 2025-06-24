#include <iostream>
#include <map>
#include <vector>
#include <string>

/*
目前的庫存 inventory (一個 std::map)。
一張銷售清單 sales_list (一個 std::vector<string>)，記錄了被賣出的商品。
每當一個商品被賣出，其庫存數量就減 1。
如果一個商品的庫存數量減到 0，就必須將該商品從庫存地圖中完全移除。
如果銷售清單中的商品在庫存中不存在，則印出一條警告訊息。
*/
void process_sales(std::map<std::string, int>& inventory, const std::vector<std::string>& sales_list){
    // TODO: write a loop to run all the sales_list  
    for (const std::string& sold_item : sales_list){
        std::cout << "Processing sale of: " << sold_item << std::endl;
        // TODO: search sold_item in inventory
        auto it = inventory.find(sold_item);
        // TODO: if find or not
        if (it != inventory.end()){
            // TODO: decrease number of item for 1
            it->second--;
            // TODO: check number of item is zero or not
            if (it->second == 0){
                std::cout << "Item " << it->first << " is out of stock, removing from inventory.\n";
                inventory.erase(it); 
            }
        } else {
            std::cout << "[Warning] Item not in inventory: " << sold_item << std::endl;
        }
    }
}


int main() {
    // 初始庫存
    std::map<std::string, int> inventory = {
        {"apple", 5},
        {"banana", 8},
        {"orange", 3}
    };

    // 銷售清單
    std::vector<std::string> sales_list = {
        "banana",
        "orange",
        "apple",
        "banana",
        "grape", // 注意，這個商品庫存裡沒有
        "orange"
    };

    std::cout << "Initial inventory:\n";
    for (const auto& pair : inventory) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    process_sales(inventory, sales_list);

    std::cout << "\nFinal inventory:\n";
    for (const auto& pair : inventory) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}