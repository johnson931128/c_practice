// data_handler.h
#ifndef DATA_HANDLER_H
#define DATA_HANDLER_H

#include <string> // 需要 string 型別

// 宣告儲存使用者資料的檔案名稱 (這個變數會在 .cpp 檔案中定義)
// extern 表示這個變數是在其他檔案定義的，這裡只是宣告它的存在。
// 這樣其他檔案就可以共用同一個變數，不會重複定義。
extern const std::string FILENAME;

// 宣告檢查使用者名稱是否已存在的函數
// 這裡只需要函數原型，具體實現會在 data_handler.cpp 中
bool doesUserExist(const std::string& username);

#endif // DATA_HANDLER_H