#include <iostream>
#include "services/BankService.h"

int main()
{
    BankService bank;
    int choice = -1;
    int currentUserId = -1; //-1 mean no user login

    while (true)
    {
        // Not Logged in menu

        if (currentUserId == -1)
        {
            std::cout << "\n....Main Menu...\n";
            std::cout << "1. Create User\n";
            std::cout << "2. Create Account\n";
            std::cout << "3. Login\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter Your choice\n";
            std::cin >> choice;

            if (choice == 1)
            {
                std::string name;
                int pin;

                std::cout << "Enter Name: \n";
                std::cin >> name;

                std::cout << "Enter Pin: \n";
                std::cin >> pin;

                User user = bank.createUser(name, pin);

                std::cout << "User Created Sucessfully!\n";
                std::cout << "Your User Id is: " << user.getUserId() << "\n";
            }
            else if (choice == 2)
            {
                int userId;

                std::cout << "Enter User ID: \n";
                std::cin >> userId;

                Account acc = bank.createAccount(userId);

                std::cout << "Account created. with account Number: "
                          << acc.getAccountNumber() << "\n";
            }
            else if (choice == 3)
            {
                int userId;
                int pin;

                std::cout << "Enter User Id: \n";
                std::cin >> userId;

                std::cout << "Enter PIN: \n";
                std::cin >> pin;

                if (bank.login(userId, pin))
                {
                    currentUserId == userId;
                    std::cout << "Login sucessfully\n";
                }

                else
                {
                    std::cout << "Invalid User ID or PIN\n";
                }
            }
            else if (choice == 0)
            {
                break;
            }
            else
            {
                std::cout << "Invalid choice\n";
            }
        }
        // Logged In menu
        else
        {
            std::cout << "\n.....User Menu....\n";
            std::cout << "1. Deposite\n";
            std::cout << "2. Withdraw\n";
            std::cout << "3. Check Balance\n";
            std::cout << "4. Logout\n";
            std::cout << "Enter Your Choice\n";

            std::cin >> choice;

            if (choice == 1)
            {
                double amount;
                std::cout << "Enter Amount to deposit:\n";
                std::cin >> amount;
                if (bank.deposit(currentUserId, amount))
                {
                    std::cout << "Deposit successfully!\n";
                }
                else
                {
                    std::cout << "Deposit failed. Invalid amount or account not found!\n";
                }
            }

            else if (choice == 2)
            {
                double amount;
                std::cout << "Enter Amount to Withdraw\n";
                std::cin >> amount;

                if (bank.withdraw(currentUserId, amount))
                {
                    std::cout << "Withdraw Sucessfull\n";
                }
                else
                {
                    std::cout << "Withdraw failed. Insufficient balance or invalid account\n";
                }
            }

            else if (choice == 3)
            {
                double balance = bank.getBalance(currentUserId);

                if (balance < 0)
                {
                    std::cout << "No account found.\n";
                }
                else
                {
                    std::cout << "Current Balance: " << balance << "\n";
                }
            }

            else if (choice == 4)
            {
                currentUserId == -1;
            }
            else
            {
                std::cout << "Invalid Choice\n";
            }
        }
    }
    std::cout << "Thank U" << std::endl;
    return 0;
}