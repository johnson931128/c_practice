// auth.h
#ifndef AUTH_H
#define AUTH_H

#include <string>       // 需要 string
#include "data_handler.h" // 因為 auth 模組會使用 data_handler 模組的函數 (例如 doesUserExist)

// 宣告註冊函數
void registerUser();

// 宣告登入函數
void loginUser();

#endif // AUTH_H