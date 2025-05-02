// auth.cpp
#include "auth.h" // 包含自己的標頭檔
#include "data_handler.h" // 再次包含，讓 .cpp 檔案也是獨立的
#include <iostream>       // 用於 cin, cout
#include <fstream>        // 用於 ofstream
#include <limits>         // 用於 numeric_limits
#include <sstream>        // 用於 stringstream

// 使用 std namespace，但通常只在 .cpp 檔案中使用或限定範圍
using namespace std;

// 實作註冊函數
void registerUser() {
    string username, password;

    cout << "--- 使用者註冊 ---" << endl;
    cout << "請輸入您想註冊的帳號: ";
    cin >> username;
    // 清除可能殘留的換行符，避免影響密碼輸入
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // *** 重要：使用 data_handler 模組提供的函數檢查帳號是否已被使用 ***
    if (doesUserExist(username)) {
        cout << "錯誤：此帳號 '" << username << "' 已經被註冊了！請嘗試其他帳號。" << endl;
        return; // 結束註冊流程
    }

    cout << "請輸入您的密碼: ";
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // *** 將新使用者資料寫入檔案 ***
    // 直接在 auth 模組中處理寫入，或者也可以在 data_handler 模組中建立一個 addUserToFile 的函數
    // 為了簡單，我們這裡直接寫入，但更大型系統會把寫入也放到 data_handler
    ofstream file(FILENAME, ios::app); // 使用 data_handler 提供的 FILENAME

    if (!file.is_open()) {
        cerr << "錯誤：無法開啟資料檔進行寫入！" << endl; // cerr 用於輸出錯誤訊息
        return;
    }

    // 將帳號和密碼寫入檔案，用空格分隔，並換行
    file << username << " " << password << endl;
    file.close(); // 關閉檔案

    cout << "帳號 '" << username << "' 註冊成功！" << endl;
}

// 實作登入函數
void loginUser() {
    string username, password;
    string line;
    string storedUsername, storedPassword;
    bool loggedIn = false;

    cout << "--- 使用者登入 ---" << endl;
    cout << "請輸入您的帳號: ";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "請輸入您的密碼: ";
    cin >> password;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // *** 讀取檔案並驗證 ***
    ifstream file(FILENAME); // 使用 data_handler 提供的 FILENAME 開啟檔案用於讀取

    if (!file.is_open()) {
        cerr << "錯誤：無法開啟使用者資料檔！可能尚未有使用者註冊。" << endl;
        return;
    }

    // 逐行讀取檔案
    while (getline(file, line)) {
        stringstream ss(line);
        if (ss >> storedUsername >> storedPassword) { // 讀取儲存的帳號密碼
            // 檢查帳號和密碼是否都匹配
            if (storedUsername == username && storedPassword == password) {
                loggedIn = true; // 找到匹配的使用者
                break; // 找到就可以停止搜尋了
            }
        }
    }

    file.close(); // 關閉檔案

    // 根據驗證結果顯示訊息
    if (loggedIn) {
        cout << "登入成功！歡迎, " << username << "!" << endl;
        // 在這裡可以加入登入成功後的其他功能
    } else {
        cout << "登入失敗：帳號或密碼錯誤。" << endl;
    }
}