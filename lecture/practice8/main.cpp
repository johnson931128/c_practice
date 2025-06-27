// main.cpp
#include <iostream>
#include "NumericRange.h"
#include <numeric> // For std::accumulate

int main() {
    std::cout << "Integers from 0 to 9:\n";
    NumericRange<int> r1(0, 10);
    for (int i : r1) {
        std::cout << i << " "; // 預期輸出: 0 1 2 3 4 5 6 7 8 9
    }
    std::cout << "\n\n";

    std::cout << "Doubles from 1.5 to 5.0 with step 0.5:\n";
    NumericRange<double> r2(1.5, 5.0, 0.5);
    for (auto val : r2) {
        std::cout << val << " "; // 預期輸出: 1.5 2.0 2.5 3.0 3.5 4.0 4.5
    }
    std::cout << "\n\n";
    
    std::cout << "Integers from 5 down to 1:\n";
    NumericRange<int> r3(5, 0, -1);
    for (int i : r3) {
        std::cout << i << " "; // 預期輸出: 5 4 3 2 1
    }
    std::cout << "\n\n";

    std::cout << "Using with STL algorithm (sum of 0..9):\n";
    // std::accumulate 需要一個開始迭代器、一個結束迭代器和一個初始值
    long long sum = std::accumulate(r1.begin(), r1.end(), 0LL);
    std::cout << "Sum is: " << sum << std::endl; // 預期輸出: 45

    return 0;
}