#ifndef BANKSERVICE_H
#define BANKSERVICE_H

#include <string>
#include <vector>

#include "models/User.h"
#include "models/Account.h"

class BankService
{
private:
    std::vector<User> users;
    std::vector<Account> accounts;

    int nextUserId;
    int nextAccountNumber;

public:
    BankService();

    // public operation
    User createUser(const std::string &name, int pin);
    Account createAccount(int userId);

    Account *getAccountByUserId(int userId) ;

    // Login
    bool login(int userId, int pin) const;

    // Transaction
    bool deposit(int userId, double amount);
    bool withdraw(int userId, double amount);

    double getBalance(int userId);
};
#endif