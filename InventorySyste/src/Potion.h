#ifndef POTION_H
#define POTION_H
#include "Item.h"

class Potion : public Item{
    private:
        int healAmount;
    public:
        Potion(const std::string& name, float weight, int healAmount);
        ~Potion();

        int getHealAmount() const;
        void use() const override;
};

#endif