#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;
    float weight;

public:
    Item(std::string name, float weight);
    // 虛擬解構函式，確保透過基底類別指標刪除物件時能正確呼叫派生類別的解構函式，釋放資源。
    virtual ~Item();

    std::string getName() const;
    float getWeight() const;

    virtual void use() const = 0;
};

#endif
