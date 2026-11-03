#include "Account.h"

Account::Account(int accountNumber, int userId)
    : accountNumber(accountNumber), userId(userId), balance(0.00) {};

bool Account::deposit(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (amount <= 0 && amount > balance)
    {
        return false;
    }

    balance -= amount;

    return true;
}

double Account::getBalance() const
{
    return balance;
}

int Account::getUserId() const
{
    return userId;
}
int Account::getAccountNumber() const
{
    return accountNumber;
}