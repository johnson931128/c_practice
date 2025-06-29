
# Lab 2 解題說明

這個檔案包含了 LeetCode Lab 2 中四個問題的解題思路、重要觀念和 C 語言語法技巧。

---

## 1. 1480. Running Sum of 1d Array (一維陣列的連續和)

### 核心觀念

這題的目標是計算一個陣列的「連續和」，也就是新陣列中的每個元素都是原陣列從頭到該位置所有元素的總和。

- **連續和 (Running Sum):** `result[i] = nums[0] + nums[1] + ... + nums[i]`
- **遞迴關係:** `result[i]` 其實就是 `result[i-1] + nums[i]`。這個發現是解題的關鍵，可以避免重複計算，大大提高效率。

### 重要語法與技巧

1.  **動態記憶體配置 (`malloc`):**
    -   題目要求回傳一個新的陣列，這個陣列的大小在編譯時期是未知的（取決於輸入的 `numsSize`），因此我們需要動態配置記憶體。
    -   `int* result = (int*)malloc(numsSize * sizeof(int));`
    -   這行程式碼配置了足夠存放 `numsSize` 個整數的記憶體空間，並將指標回傳給 `result`。
    -   `sizeof(int)` 確保了跨平台的可攜性，無論 `int` 在不同作業系統佔用多少位元組。

2.  **指標參數 (`int* returnSize`):**
    -   在 C 語言中，函式通常只能有一個回傳值。如果我們需要回傳多個資訊（例如，一個陣列和它的長度），常用的方法就是透過指標參數。
    -   `*returnSize = numsSize;`
    -   這裡我們透過傳入的指標 `returnSize`，將陣列的長度「存回」到呼叫這個函式的程式碼中。`*` 是取值運算子 (dereference operator)，用來存取指標所指向的記憶體位置。

3.  **迴圈與陣列操作:**
    -   使用一個 `for` 迴圈從第二個元素開始（索引 `i = 1`），利用 `result[i] = result[i - 1] + nums[i];` 的遞迴關係，有效率地完成計算。

---

## 2. 2235. Add Two Integers (兩數相加)

### 核心觀念

這是一個非常基礎的題目，主要目的是熟悉 C 語言的函式定義、參數傳遞以及標準輸入輸出。

### 重要語法與技巧

1.  **函式定義:**
    -   `int sum(int num1, int num2)` 定義了一個名為 `sum` 的函式，它接收兩個 `int` 型別的參數，並回傳一個 `int` 型別的結果。

2.  **標準輸入 (`scanf`):**
    -   `scanf("%d %d", &num1, &num2);`
    -   `scanf` 用於從標準輸入（通常是鍵盤）讀取格式化的資料。
    -   `%d` 是格式指定符，表示要讀取一個十進位整數。
    -   `&num1` 中的 `&` 是取址運算子 (address-of operator)，它會取得變數 `num1` 的記憶體位址。`scanf` 需要位址才能將讀取到的值寫入變數中。

3.  **標準輸出 (`printf`):**
    -   `printf("%d\n", ans);`
    -   `printf` 用於將格式化的資料輸出到標準輸出（通常是螢幕）。
    -   `\n` 是換行符，讓輸出的結果更清晰。

---

## 3. 344. Reverse String (反轉字串)

### 核心觀念

這題要求我們「原地」反轉一個字串（字元陣列），也就是不能使用額外的陣列來儲存結果。最有效率的方法是「雙指標法」。

-   **雙指標法 (Two Pointers):**
    1.  設定一個指標 `left` 指向陣列的開頭，另一個指標 `right` 指向陣列的結尾。
    2.  當 `left` 在 `right` 的左邊時，不斷交換它們指向的字元。
    3.  每次交換後，將 `left` 往右移一步，`right` 往左移一步。
    4.  當 `left` 與 `right` 相遇或交錯時，整個陣列就反轉完成了。

### 重要語法與技巧

1.  **指標與陣列:**
    -   在 C 語言中，傳入函式的陣列名稱 `char* s` 實際上是一個指向陣列第一個元素的指標。因此，我們可以直接透過 `s[index]` 的方式來存取和修改陣列的內容。

2.  **原地交換 (In-place Swap):**
    -   為了交換兩個變數的值，我們需要一個暫存變數 `temp`。
    -   ```c
      char temp = s[left];
      s[left] = s[right];
      s[right] = temp;
      ```
    -   這個三步驟的交換是演算法中非常基礎且重要的技巧。

3.  **迴圈條件:**
    -   `while (left < right)` 是這個演算法的核心。它確保了我們只處理陣列的前半部分與後半部分的對應交換，當指標相遇（陣列長度為奇數）或交錯（陣列長度為偶數）時，迴圈會自然停止，不多做也不少做。

---

## 4. 412. Fizz Buzz

### 核心觀念

這是一個經典的程式設計入門題，考驗的是條件判斷邏輯，以及在 C 語言中處理字串陣列的細節。

-   **條件判斷順序:** 判斷的順序至關重要。必須先檢查最嚴格的條件（`i % 15 == 0`），然後才是比較寬鬆的條件（`i % 3 == 0` 和 `i % 5 == 0`）。如果順序反了，那麼 15 的倍數會先被 `i % 3 == 0` 的條件攔截，永遠不會輸出 "FizzBuzz"。

### 重要語法與技巧

1.  **二維陣列/指標的指標 (`char**`):**
    -   我們要回傳的是一個「字串陣列」，在 C 中，這通常用 `char**` (指向字元指標的指標) 來表示。
    -   `char** answer = (char**)malloc(n * sizeof(char*));`
    -   這行程式碼配置了「外層陣列」，它本身不存字串，而是存放 `n` 個 `char*` 型別的「指標」。每一個指標未來將指向一個實際的字串。

2.  **動態配置每個字串的記憶體:**
    -   對於外層陣列中的每一個指標，我們都需要根據要存放的字串（"FizzBuzz", "Fizz", "Buzz", 或數字）再次使用 `malloc` 來配置對應的記憶體空間。
    -   `answer[index] = (char*)malloc(9 * sizeof(char));`
    -   **注意：** 字串結尾需要一個空字元 `'\0'`，所以配置的長度必須是 `字串長度 + 1`。

3.  **字串複製 (`strcpy`):**
    -   `strcpy(destination, source);` 是 C 標準函式庫 `<string.h>` 中的函式，用來將一個字串複製到另一個字串中。
    -   `strcpy(answer[index], "FizzBuzz");`

4.  **數字轉字串 (`sprintf`):**
    -   當數字不符合任何 "Fizz" 或 "Buzz" 的條件時，需要將整數 `i` 轉換成字串。
    -   `sprintf(buffer, "%d", i);` 是個強大且方便的工具，它的用法和 `printf` 類似，但不是印到螢幕，而是將格式化後的字串「印」到一個字元陣列 `buffer` 中。
    -   為了節省記憶體，我們先用 `sprintf` 將數字轉到一個暫存的 `buffer`，再用 `strlen(buffer)` 取得實際長度，最後才根據這個實際長度去 `malloc` 剛好大小的記憶體。
