#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>


class BankAccount {
    private:
        std::string owner_name;
        double balance;

    public:
        BankAccount(const std::string& name, double initial_balance);
        
        void deposit(double amount);
        void withdraw(double amount);
        double get_balance() const;
        std::string get_owner_name() const;
};

#endif
