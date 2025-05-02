# C++ 登入與註冊系統 (Login and Registration System)

這是一個使用 C++ 實現的簡單主控台應用程式，用於使用者註冊和登入。系統將使用者憑證 (帳號和密碼) 儲存在一個文字檔案中，模擬一個簡易的使用者資料庫。

## 功能 (Features)

*   **使用者註冊 (User Registration):** 允許新使用者設定帳號和密碼。
*   **使用者登入 (User Login):** 驗證使用者提供的帳號和密碼是否與儲存的憑證匹配。
*   **資料儲存 (Data Storage):** 使用文字檔案 (`userdata.txt`) 儲存使用者憑證。

## 使用技術 (Technologies Used)

*   C++ 程式語言
*   標準輸入/輸出函式庫 (`<iostream>`)
*   檔案操作函式庫 (`<fstream>`)
*   字串處理函式庫 (`<string>`, `<sstream>`)
*   輸入處理 (`<limits>`)

## 檔案結構 (File Structure)
login_system/
├── main.cpp
├── auth.h
├── auth.cpp
├── data_handler.h
└── data_handler.cpp


## 如何建置 (How to Build)

你需要一個 C++ 編譯器 (例如 g++)。在終端機中，導航到專案根目錄 (`login_system/`)，然後執行以下命令：

```bash
g++ main.cpp auth.cpp data_handler.cpp -o login_system -std=c++20
./login_system



