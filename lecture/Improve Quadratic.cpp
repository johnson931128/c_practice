#include <iostream>
#include <cmath>
#include <utility>

// Define type aliases using the `using` keyword
using Zeros = std::pair<double, double>;
using Solution = std::pair<bool, Zeros>;

// Function to solve the quadratic equation
Solution solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        // Not a quadratic equation
        return {false, {0.0, 0.0}};
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // No real roots
        return {false, {0.0, 0.0}};
    } else {
        // Compute the roots
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        return {true, {root1, root2}};
    }
}

int main() {
    double a, b, c;
    std::cout << "Enter coefficients a, b, and c: ";
    std::cin >> a >> b >> c;

    Solution result = solveQuadratic(a, b, c);

    if (result.first) {
        std::cout << "The roots are: " << result.second.first << " and " << result.second.second << std::endl;
    } else {
        std::cout << "No real roots exist." << std::endl;
    }

    return 0;
}