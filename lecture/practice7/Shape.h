#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
    public:
        // 純虛擬函式,用 = 0來宣告
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual std::string get_name() const = 0;

        virtual ~Shape() = default;
};

#endif