#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(const std::string& name, double initial_balance)
    : owner_name(name), balance(initial_balance >= 0.0? initial_balance : 0.0){
    if (initial_balance < 0.0) {
        std::cout << "[Warning] Initial balance cannot be negative. Setting balance for "
        << owner_name << " to 0.0.\n";
    }      
}

double BankAccount::get_balance() const{
    return this->balance;
}

std::string BankAccount::get_owner_name() const{
    return owner_name;
}

void BankAccount::deposit(double amount){
    if (amount > 0.0 || balance >= 0.0){
        balance += amount;
        std::cout << "Deposit Successful\n";
    }else{
        std::cout << "Please check ur money is enough\n";
    }
}

void BankAccount::withdraw(double amount){
    if (amount > 0.0 && balance >= amount){
        balance-=amount;
        std::cout << "Withdraw Successful\n";
        std::cout << "Your Balance is : " << balance << "\n";
    }else{
        std::cout << "You have no money\n";
    }
}