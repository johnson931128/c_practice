// main.cpp
#include <iostream> // 用於 cin, cout
#include <limits>   // 用於 numeric_limits
#include "auth.h"   // 需要呼叫 auth 模組中的函數

// 使用 std namespace (通常在 main 或 .cpp 檔案中使用)
using namespace std;

// 顯示選單的函數 (可以放在這裡或獨立成一個 UI 模組)
void showMenu() {
    cout << "========================" << endl;
    cout << "   登入與註冊系統" << endl;
    cout << "========================" << endl;
    cout << "1. 註冊 (Register)" << endl;
    cout << "2. 登入 (Login)" << endl;
    cout << "3. 離開 (Exit)" << endl;
    cout << "========================" << endl;
}

int main() {
    int choice;

    do {
        showMenu(); // 顯示選單
        cout << "請輸入您的選擇: ";

        // 讀取使用者輸入，並做基本的錯誤處理
        while (!(cin >> choice)) {
            cout << "無效的輸入，請輸入數字 (1-3): ";
            cin.clear(); // 清除錯誤旗標
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除輸入緩衝區
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除換行符

        switch (choice) {
            case 1:
                registerUser(); // 呼叫 auth 模組中的註冊函數
                break;
            case 2:
                loginUser();    // 呼叫 auth 模組中的登入函數
                break;
            case 3:
                cout << "感謝使用，再見！" << endl;
                break;
            default:
                cout << "無效的選擇，請重新輸入。" << endl;
        }
        cout << endl; // 增加空行，讓畫面更清晰
    } while (choice != 3); // 當使用者選擇 3 時離開迴圈

    return 0; // 程式正常結束
}