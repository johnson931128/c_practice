#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h);
        double area() const override;
        double perimeter() const override;
        std::string get_name() const override;
};

#endif