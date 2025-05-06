#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory{
    private:
        Item** items;
        int capacity;
        int count;
    
    public:
        Inventory(int capacity = 10);
        ~Inventory();

        bool addItem(Item* item);
        bool removeItem(int index);
        void showInventory() const;
        void useItem(int index) const;
        int getCount() const;
};


#endif