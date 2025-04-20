#include <iostream>
#include <string>
std::string a = "test";
double b = 3.2 * 5 - 1;
int c = 5 / 2; // What does this equal?

int d(int foo) { return foo / 2; }
double e(double foo) { return foo / 2; }
int f(double foo) { return static_cast<int>(foo + 0.5); }
void g(double c) { std::cout << c << std::endl; }

int main() {
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << " (integer division: 5 / 2)" << std::endl;

    std::cout << "d(5): " << d(5) << std::endl;
    std::cout << "e(5.0): " << e(5.0) << std::endl;
    std::cout << "f(5.7): " << f(5.7) << std::endl;

    std::cout << "g(3.14): ";
    g(3.14);

    return 0;
}