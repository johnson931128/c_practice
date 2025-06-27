// Item.cpp
#include "Item.h"

Item::Item(const std::string& name, const std::string& description)
    : name_(name), description_(description) {}

std::string Item::get_name() const {
    return name_;
}

std::string Item::get_description() const {
    return description_;
}