// main.cpp
#include <iostream>
#include <vector>
#include <memory> // 為了 std::unique_ptr，這是更好的作法
#include "Circle.h"
#include "Rectangle.h"
// #include "Triangle.h" // 假設你未來會加入 Triangle.h

// 輔助函式保持不變
void print_shape_info(const Shape* s) {
    if (s) {
        std::cout << "Shape: " << s->get_name() 
                  << ", Area: " << s->area() 
                  << ", Perimeter: " << s->perimeter() << std::endl;
    }
}

int main() {
    // ---- 方法一：使用原始指標 (需要手動管理記憶體) ----
    std::cout << "--- Part 1: Using Raw Pointers (Manual Memory Management) ---\n";
    { // 使用一個區塊來限制指標的生命週期
        std::vector<Shape*> raw_shapes;
        raw_shapes.push_back(new Circle(5.0));
        raw_shapes.push_back(new Rectangle(4.0, 6.0));
        // raw_shapes.push_back(new Triangle(3.0, 4.0, 5.0)); // 如果你實現了 Triangle

        for (const Shape* shape_ptr : raw_shapes) {
            print_shape_info(shape_ptr);
        }

        // 清理記憶體！
        for (Shape* shape_ptr : raw_shapes) {
            delete shape_ptr;
        }
    } // raw_shapes 在這裡被銷毀


    // ---- 方法二：使用智慧指標 (推薦的現代 C++ 作法) ----
    std::cout << "\n--- Part 2: Using Smart Pointers (Automatic Memory Management) ---\n";
    {
        // std::unique_ptr 會在它離開作用域時自動刪除所指向的物件
        std::vector<std::unique_ptr<Shape>> smart_shapes;

        // 使用 std::make_unique 來創建物件，更安全
        smart_shapes.push_back(std::make_unique<Circle>(10.0));
        smart_shapes.push_back(std::make_unique<Rectangle>(10.0, 10.0));

        for (const auto& shape_ptr : smart_shapes) {
            // 使用 .get() 來獲取原始指標以傳遞給輔助函式
            print_shape_info(shape_ptr.get());
        }

        // 不需要手動 delete！unique_ptr 會自動處理！
    } // smart_shapes 在這裡被銷毀，它包含的所有物件也會被自動 delete

    return 0;
}