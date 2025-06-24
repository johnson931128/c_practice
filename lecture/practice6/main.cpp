// main.cpp
#include <iostream>
#include "BankAccount.h"

int main() {
    // 創建帳戶，初始金額為正 -> 成功
    BankAccount account1("Alice", 100.0);
    std::cout << account1.get_owner_name() << "'s balance: " << account1.get_balance() << std::endl;

    // 創建帳戶，初始金額為負 -> 應設為 0
    BankAccount account2("Bob", -50.0);
    std::cout << account2.get_owner_name() << "'s balance: " << account2.get_balance() << std::endl;

    // 存款
    account1.deposit(50.0); // 合法
    account1.deposit(-20.0); // 非法
    std::cout << "Alice's balance after deposits: " << account1.get_balance() << std::endl;

    // 提款
    account1.withdraw(30.0);  // 合法
    account1.withdraw(200.0); // 非法，餘額不足
    std::cout << "Alice's final balance: " << account1.get_balance() << std::endl;
    
    // 嘗試直接修改 -> 會編譯失敗！
    // account1.balance = 50000; // ERROR! 'balance' is private
    
    return 0;
}