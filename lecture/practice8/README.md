# C++ 高難度練習：實現一個類 Python 的 `range` 類別與自訂迭代器

這是一個綜合性的 C++ 練習，目標是從頭開始實現一個類似 Python `range()` 功能的模板類別 `NumericRange<T>`。這個專案的核心挑戰在於為我們的自訂類別設計並實現一個完整的**自訂迭代器**，從而讓它能夠與 C++ 的基於範圍的 for 迴圈 (`range-based for loop`) 以及標準庫演算法 (STL algorithms) 無縫接軌。

## 學習目標

這個練習涵蓋了 C++ 中多個進階且核心的主題：

*   **自訂迭代器 (Custom Iterators)**：深入理解迭代器的本質，不僅僅是使用，而是親手打造。這包括重載關鍵的運算子：
    *   `operator*` (解引用)
    *   `operator++` (前置遞增)
    *   `operator!=` (不等於比較)
*   **模板程式設計 (Template Programming)**：利用模板 `template <typename T>` 來設計一個泛型的 `NumericRange` 類別和它的迭代器，使其能同時適用於 `int`, `double` 等多種數值型別。
*   **運算子重載 (Operator Overloading)**：這是實現自訂迭代器的基礎，賦予類別物件類似指標的行為。
*   **類別設計與實現**：練習將一個複雜問題拆解為兩個協同工作的類別 (`NumericRange` 和 `NumericRangeIterator`)。
*   **STL 設計哲學**：深刻體會 STL 如何透過 `begin()` 和 `end()` 函式將**容器**、**迭代器**和**演算法**這三個核心元件串連起來。
*   **基於範圍的 for 迴圈原理**：理解 `for (auto i : my_object)` 在編譯器層面是如何被轉換為使用 `begin()` 和 `end()` 的迭代器迴圈。

## 題目情境

Python 的 `range()` 函式是一個強大且高效的工具，它能產生一個數字序列供迴圈使用，卻不需要在記憶體中實際儲存整個序列。本次的任務就是在 C++ 中模仿這一行為，創建一個 `NumericRange` 類別，使其具備以下特性：

*   可以指定**開始值**、**結束值**和**步長**。
*   能夠**惰性求值 (lazy evaluation)**，只在需要時才產生下一個數字。
*   可以被用於標準的 `for` 迴圈。
*   可以與 `std::algorithm` 中的函式（如 `std::accumulate`）一起使用。

## 設計與實現

### 1. `NumericRangeIterator<T>`
這是迭代器類別，是整個系統的「引擎」。它負責：
*   儲存當前在序列中的值 (`current_value`) 和步長 (`step_value`)。
*   透過 `operator*` 提供對當前值的存取。
*   透過 `operator++` 計算並移動到序列中的下一個值。
*   透過 `operator!=` 判斷是否已達到範圍的末端，從而終止迴圈。

### 2. `NumericRange<T>`
這是範圍類別，是使用者直接互動的「介面」。它負責：
*   儲存範圍的配置：`start_value`, `end_value`, `step_value`。
*   提供 `begin()` 函式，用來產生一個指向序列起點的 `NumericRangeIterator`。
*   提供 `end()` 函式，用來產生一個代表序列終點的「哨兵」`NumericRangeIterator`。

### 檔案結構

由於模板的特性（編譯器需要在編譯時期看到完整的程式碼來進行實例化），所有的宣告和實現都放在單一的標頭檔中。

*   **`NumericRange.h`**: 包含 `NumericRangeIterator<T>` 和 `NumericRange<T>` 兩個模板類別的完整定義。
*   **`main.cpp`**: 用於展示和測試 `NumericRange` 功能的範例程式。

## 如何編譯與執行

使用任何標準的 C++ 編譯器（需支援 C++17 或以上版本）即可。

```bash
g++ -std=c++17 main.cpp -o range_test
```
執行編譯後的可執行檔：
```bash
./range_test
```

## 預期輸出

執行 `main.cpp` 後，將展示 `NumericRange` 的多種用法，包括正向、帶步長、反向遍歷，以及與 STL 演算法的結合：

```
Integers from 0 to 9:
0 1 2 3 4 5 6 7 8 9 

Doubles from 1.5 to 5.0 with step 0.5:
1.5 2 2.5 3 3.5 4 4.5 

Integers from 5 down to 1:
5 4 3 2 1 

Using with STL algorithm (sum of 0..9):
Sum is: 45
```

---
這個練習不僅僅是寫程式，更是對 C++ 語言設計思想的一次深度探索。完成它代表你對模板和迭代器的理解已經超越了單純的使用者層面，達到了設計者和實現者的層次。