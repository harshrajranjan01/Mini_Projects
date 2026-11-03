#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    int accountNumber;
    int userId;
    double balance;

public:
    Account(int accountNumber, int userId);

    bool deposit(double amount);

    bool withdraw(double amount);

    double getBalance() const;

    int getUserId() const;

    int getAccountNumber() const;
};
#endif