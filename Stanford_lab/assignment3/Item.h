#ifndef ITEM_H
#define ITEM_H
#include <string>
class Player;

class Item {
    protected:
        std::string name_;
        std::string description_;
    public:
        Item(const std::string& name, const std::string& description);
        virtual ~Item() = default;

        std::string get_name() const;
        std::string get_description() const;

        virtual void use(Player& player) = 0;

};

#endif