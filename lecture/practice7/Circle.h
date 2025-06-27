#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Shape.h"

class Circle : public Shape {
    private:
        double radius;
    public:
        // explicit 避免隱式轉換，是個好習慣
        explicit Circle(double r);
        // Override
        double area() const override;
        double perimeter() const override;
        std::string get_name() const override;
};

#endif