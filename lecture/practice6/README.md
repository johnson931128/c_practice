# C++ 練習題：設計一個安全的 BankAccount 類別

這是一個基於 CS106L 第 8 講「類別 (Classes)」概念的實作練習。我們的目標是將一個不安全的 `struct` 重構為一個功能完整且具備良好封裝性的 C++ `class`。

## 學習目標

*   **封裝 (Encapsulation)**：理解為何要將資料成員設為 `private`，並透過 `public` 成員函式提供受控的存取介面。
*   **類別定義與實現分離**：練習將類別的宣告放在標頭檔 (`.h`)，並將實現放在原始檔 (`.cpp`)。
*   **建構函式 (Constructor)**：學習如何設計建構函式來初始化物件的狀態，並在其中加入驗證邏輯。
*   **成員初始化列表 (Member Initializer List)**：使用更高效、更強大的方式來初始化成員變數。
*   **成員函式 (Member Functions)**：設計 `getter` 和 `setter` 函式（如此處的 `deposit`/`withdraw`），並實作業務邏輯。
*   **`const` 正確性 (Const Correctness)**：練習在不修改物件狀態的成員函式（如 `getter`）後面加上 `const` 關鍵字。
*   **`this` 指標**：理解 `this` 在成員函式中的作用。

## 題目情境

你正在為一個銀行系統設計帳戶模組。最初的設計是一個簡單的 `struct`，但它允許外部程式碼隨意修改帳戶餘額，甚至設定成負數，這在真實世界中是不可接受的。

**初始的不安全結構：**
```cpp
struct BankAccount_struct {
    std::string owner_name;
    double balance; // 任何人都可以直接修改，非常不安全！
};
```

## 改造任務與規則

你需要將上述結構重構為一個 `BankAccount` 類別，並遵循以下規則：

1.  **資料封裝**：
    *   `owner_name` 和 `balance` 必須是 `private`。

2.  **建構函式**：
    *   接收帳戶持有人姓名和初始存款。
    *   如果初始存款為負數，餘額將被強制設為 `0.0`，並印出警告。

3.  **公開介面**：
    *   `deposit(double amount)`: 存入金額。金額必須為正數。
    *   `withdraw(double amount)`: 提出金額。金額必須為正數，且帳戶餘額必須足夠。
    *   `get_balance() const`: 回傳目前餘額。
    *   `get_owner_name() const`: 回傳持有人姓名。

## 檔案結構

這個專案包含三個主要檔案：

1.  **`BankAccount.h`**: 包含 `BankAccount` 類別的宣告（介面）。
2.  **`BankAccount.cpp`**: 包含 `BankAccount` 類別成員函式的實現（邏輯）。
3.  **`main.cpp`**: 用於測試 `BankAccount` 類別功能的驅動程式。

## 如何編譯與執行

你可以使用 C++ 編譯器（如 g++ 或 clang++）來編譯這些檔案。在終端機中，進入檔案所在的目錄並執行以下指令：

```bash
g++ main.cpp BankAccount.cpp -o bank_simulation
```
這會將 `main.cpp` 和 `BankAccount.cpp` 一起編譯，並產生一個名為 `bank_simulation` 的可執行檔。

然後執行它：
```bash
./bank_simulation
```

## 預期輸出

執行 `main.cpp` 後，你應該會看到類似以下的輸出，展示了類別如何正確處理有效和無效的操作：

```
Alice's balance: 100
[Warning] Initial balance cannot be negative. Setting balance for Bob to 0.0.
Bob's balance: 0
[Warning] Deposit amount must be positive.
Alice's balance after deposits: 150
[Warning] Withdrawal failed. Invalid amount or insufficient funds.
Alice's final balance: 120
```

---
這個練習很好地總結了物件導向程式設計的基本原則，並將它們應用於一個實際且易於理解的例子中。