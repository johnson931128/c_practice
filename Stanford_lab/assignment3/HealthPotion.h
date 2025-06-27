#ifndef HEALTH_POTION_H
#define HEALTH_POTION_H

#include "Item.h"

class HealthPotion : public Item {
    private:
        int heal_amount_;
    public:
        HealthPotion(const std::string& name, const std::string& description, int heal_amount);
        void use(Player& player) override;
};

#endif