#include "Rectangle.h"
#include <string>


Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

std::string Rectangle::get_name() const {
    return "Rectangle";
}