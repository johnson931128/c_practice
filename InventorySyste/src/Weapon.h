#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

/**
 * @class Weapon
 * @brief Represents a weapon item in the inventory system, derived from Item.
 *
 * The Weapon class extends the Item class by adding a damage attribute,
 * representing the amount of damage the weapon can inflict.
 */
class Weapon : public Item {
    private:
        /**
         * @brief The amount of damage this weapon can deal.
         */
        int damage;

    public:
        /**
         * @brief Constructs a Weapon object with the specified name, weight, and damage.
         * @param name The name of the weapon.
         * @param weight The weight of the weapon.
         * @param damage The damage value of the weapon.
         */
        Weapon(const std::string& name, float weight, int damage);

        /**
         * @brief Destructor for the Weapon class.
         */
        ~Weapon();

        /**
         * @brief Gets the damage value of the weapon.
         * @return The damage value.
         */
        int getDamage() const;

        /**
         * @brief Uses the weapon. Overrides the use method from the Item class.
         */
        void use() const override;
};

#endif