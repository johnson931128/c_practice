#ifndef SWORD_H
#define SWORD_H

#include "Item.h"

class Sword : public Item {
    private:
        int damage_;
    public:
        Sword(const std::string& name, const std::string& description, int damage);
        void use(Player& player) override;
};

#endif