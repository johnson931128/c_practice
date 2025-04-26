#include <iostream>
#include <iomanip> // 為了 std::fixed 和 std::setprecision set the type of output

// Overloaded function with int parameter
double axolotl(int x) {
    return (double)x + 3;
}

// Overloaded function with double parameter
double axolotl(double x) {
    return x * 3;
}

int main() {
    // 設定輸出格式：固定小數點，顯示一位
    std::cout << std::fixed << std::setprecision(1);

    // Call the first version of axolotl (int parameter)
    std::cout << "Result of axolotl(int): " << axolotl(2) << std::endl;

    // Call the second version of axolotl (double parameter)
    std::cout << "Result of axolotl(double): " << axolotl(2.0) << std::endl;

    std::cout << "Program executed successfully." << std::endl;
    return 0;
}
