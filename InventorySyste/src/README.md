## Project Structure：
```
InventorySystem/         <-- 專案主資料夾
│
├── main.cpp             <-- 主程式入口，執行 Inventory 的操作
│
├── Item.h               <-- 抽象類別 Item（基底類）
├── Item.cpp             <-- Item 類別的定義
│
├── Weapon.h             <-- Weapon 類別（繼承 Item）
├── Weapon.cpp           <-- Weapon 的函式實作
│
├── Potion.h             <-- Potion 類別（繼承 Item）
├── Potion.cpp           <-- Potion 的函式實作
│
├── Inventory.h          <-- Inventory 類別（管理 Item* 陣列）
├── Inventory.cpp        <-- Inventory 的函式實作
```
## 1. Build the abstraction class of Item
* virtual class
* name & weight
* method ```use```

## 2. Build the Weapon class that inherits from Item
* add ```damage``` attribute
* override use() to print how much damage from swinging the sword

## 3. Build the Potion class that inherits from Item
* This class enables recovery functionality.
* Add a `healAmount` attribute.
* Override `use()` to print: "You drink [name], hp +[healAmount]"

## 4. Function check
| 類別      | 功能           |
| -------- | --------       |
| `Item`   | 抽象類，定義介面 |
| `Weapon` | 有傷害的可用裝備 |
| `Potion` | 有回復效果的道具 |

## 5. Inventory 類別，它會幫我們管理所有裝備與道具。
* 這部分會展示 C++ 多型的實力，並進一步強化 pointer 操作的練習。
* 我們這裡先用 手動管理 Item* 陣列，這樣你可以練習：
```
動態配置 new / delete
自己控制記憶體與容量
管理多型 Item* 陣列（實際上是指向 Weapon 或 Potion）
```
```
Item* sword = new Weapon(...);  // 單一 Item* 指向 Weapon
Item* potion = new Potion(...); // 單一 Item* 指向 Potion

Item** items = new Item*[10];   // 建立一個長度為 10 的 Item* 陣列
items[0] = sword;               // 把武器放進 inventory 的第一格
items[1] = potion;              // 把藥水放進第二格

items →  ┌─────────────┐     // Item*[]
         │ items[0] ───► Weapon 物件
         │ items[1] ───► Potion 物件
         │ items[2] ───► nullptr 或其他 Item*
         └─────────────┘

```

## 6. main.cpp
* 建立幾個 Weapon 與 Potion
* 將它們加入 Inventory
* 顯示物品清單
* 使用物品（展示多型）
* 刪除物品
* smart pointer
```
-------------------------------------------------------------------------
| 類型                  | 功能說明                                        |
| -------------------- | ------------------------------------------------|
| `std::unique_ptr<T>` | 獨佔擁有權，一個物件只能有一個 owner（不能複製）    |
| `std::shared_ptr<T>` | 多人共享擁有權（reference count）                 |
| `std::weak_ptr<T>`   | 搭配 shared\_ptr，用來解決環狀參考問題（不擁有）    |
--------------------------------------------------------------------------
```

## character class：
* store chacater data
* ifstream & ofstream

