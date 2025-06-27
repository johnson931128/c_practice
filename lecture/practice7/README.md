# C++ 練習題：物件導向設計 - 幾何圖形系統

這是一個基於 CS106L 第 9 講「繼承 (Inheritance)」和「虛擬函式 (Virtual Functions)」的實作練習。我們的目標是設計一個物件導向的繼承體系，用以表示不同種類的二維圖形，並透過多型 (Polymorphism) 來統一處理它們。

## 學習目標

*   **繼承 (Inheritance)**：學習如何定義一個基礎類別 (`Shape`)，並讓衍生類別 (`Circle`, `Rectangle`) 繼承其特性。
*   **抽象基礎類別 (Abstract Base Class)**：理解當一個類別包含純虛擬函式時，它就變成抽象的，不能被直接實例化。
*   **純虛擬函式 (Pure Virtual Functions)**：學習使用 `= 0;` 語法來定義一個介面，並強制衍生類別必須提供自己的實現。
*   **多型 (Polymorphism)**：體驗物件導向最强大的特性之一。即使我們使用基礎類別的指標 (`Shape*`)，在執行時期也能夠正確地呼叫到衍生類別的特定函式。
*   **`override` 關鍵字**：養成使用 `override` 的好習慣，以確保我們確實是在覆寫基礎類別的虛擬函式，增加程式碼的健壯性。
*   **虛擬解構函式 (Virtual Destructor)**：理解在基礎類別中定義虛擬解構函式的重要性，以防止透過基礎類別指標刪除物件時發生資源洩漏。
*   **動態記憶體管理**：練習使用 `new` 來創建物件，並使用 `delete` 來釋放它們。

## 題目情境

假設我們要開發一個能處理多種幾何圖形的應用程式。每種圖形（如圓形、矩形）都有其獨特的屬性（如半徑、長寬），但它們也共享一些共通的行為，例如計算「面積」和「周長」。我們希望設計一個系統，能夠將這些不同的圖形存放在同一個集合中，並用統一的方式與它們互動。

## 設計要求

1.  **`Shape` (基礎類別)**:
    *   一個**抽象類別**，定義了所有圖形的通用介面。
    *   包含純虛擬函式：`area()`, `perimeter()`, `get_name()`。
    *   包含一個虛擬解構函式。

2.  **`Circle` (衍生類別)**:
    *   公開繼承自 `Shape`。
    *   擁有私有成員 `radius`。
    *   實現 `area()`, `perimeter()` 和 `get_name()` 的具體邏輯。

3.  **`Rectangle` (衍生類別)**:
    *   公開繼承自 `Shape`。
    *   擁有私有成員 `width` 和 `height`。
    *   實現 `area()`, `perimeter()` 和 `get_name()` 的具體邏輯。

## 檔案結構

這個專案由多個檔案組成，體現了 C++ 中宣告與實現分離的最佳實踐：

*   **`Shape.h`**: 基礎類別 `Shape` 的宣告。
*   **`Circle.h` / `Circle.cpp`**: `Circle` 類別的宣告與實現。
*   **`Rectangle.h` / `Rectangle.cpp`**: `Rectangle` 類別的宣告與實現。
*   **`main.cpp`**: 測試所有類別功能的驅動程式。

## 如何編譯與執行

在終端機中，確保所有 `.cpp` 檔案都在同一個目錄下，然後執行以下編譯指令：

```bash
g++ main.cpp Circle.cpp Rectangle.cpp -o shape_calculator
```
這會將所有實現檔案編譯並連結在一起，產生一個名為 `shape_calculator` 的可執行檔。

執行程式：
```bash
./shape_calculator
```

## 預期輸出

執行 `main.cpp` 後，你應該會看到以下輸出，展示了程式如何透過 `Shape*` 指標正確地呼叫到 `Circle` 和 `Rectangle` 各自的函式：

```
Processing shapes...
Shape: Circle, Area: 314.159, Perimeter: 62.8318
Shape: Rectangle, Area: 40, Perimeter: 26

Cleaning up...
```

---
這個練習是理解和應用 C++ 物件導向三大特性中「繼承」與「多型」的絕佳範例。