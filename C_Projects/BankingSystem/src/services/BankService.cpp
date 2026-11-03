#include "BankService.h"

BankService::BankService()
    : nextUserId(1), nextAccountNumber(1001) {}

// Create a new user

User BankService::createUser(const std::string &name, int pin)
{
    User user(nextUserId, name, pin);
    users.push_back(user);
    nextUserId++;
    return user;
}

// Create a new account for a user
Account BankService::createAccount(int userId)
{
    Account account(nextAccountNumber, userId);
    accounts.push_back(account);
    nextAccountNumber++;
    return account;
}

Account *BankService::getAccountByUserId(int userId)
{
    for (Account &account : accounts)
    {
        if (account.getUserId() == userId)
        {
            return &account;
        }
    }
    return nullptr;
}

bool BankService::login(int userId, int pin) const
{
    for (const User &user : users)
    {
        if (user.getUserId() == userId)
        {
            return user.verifyPin(pin);
        }
    }
    return false;
}

bool BankService::deposit(int userId, double amount)
{
    Account *account = nullptr;

    for (Account &acc : accounts)
    {
        if (acc.getUserId() == userId)
        {
            account = &acc;
            break;
        }
    }

    if (account == nullptr)
    {
        return false;
    }

    return account->deposit(amount);
}

bool BankService::withdraw(int userId, double amount)
{
    Account *account = nullptr;

    for (Account &acc : accounts)
    {
        if (acc.getUserId() == userId)
        {
            account = &acc;
            break;
        }
    }
    if (account == nullptr)
    {
        return false;
    }
    return account->withdraw(amount);
}

double BankService::getBalance(int userId)
{
    Account *account = getAccountByUserId(userId);

    if (account == nullptr)
    {
        return -1; // indicates error / no account
    }

    return account->getBalance();
}
