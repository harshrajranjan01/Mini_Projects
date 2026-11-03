# Banking System

A command-line banking application written in C++. Users can create a profile and account, log in with a PIN, and perform basic transactions.

This project was a useful starting point for practicing how to organize a C++ program across multiple files, use classes, separate responsibilities, and track development with Git commits.

## Project Goals

The project is organized into separate parts so the menu, banking operations, and data models are not all in one file:

- **`main.cpp`** handles the menus and user input.
- **`BankService`** manages users and accounts and carries out banking operations.
- **`User`** stores user details and verifies a PIN.
- **`Account`** stores account details and updates the balance.

## Features

- Create a user and receive a user ID
- Create an account associated with a user ID
- Log in with a user ID and PIN
- Deposit money
- Withdraw money when the amount is valid and funds are available
- Check the account balance
- Log out and return to the main menu

## Project Structure

```text
BankingSystem/
├── src/
│   ├── main.cpp
│   ├── models/
│   │   ├── Account.h
│   │   ├── Account.cpp
│   │   ├── User.h
│   │   └── User.cpp
│   └── services/
│       ├── BankService.h
│       └── BankService.cpp
├── .gitignore
└── README.md
```

Header files declare the classes and their public methods. The corresponding `.cpp` files implement those methods.

## How the Program Works

When the application starts, `main.cpp` creates a `BankService` object. The service stores users and accounts in vectors for the duration of the run.

1. **User creation:** `BankService` assigns the next user ID, creates a `User`, and stores it. The program displays the ID so it can be used when opening an account or logging in.
2. **Account creation:** The program asks for a user ID. `BankService` assigns an account number and creates an account with a starting balance of zero.
3. **Login:** `BankService` finds the user and calls `User::verifyPin`. When the PIN is correct, `main.cpp` records the active user ID and displays the user menu.
4. **Transactions:** The menu passes the active user ID and amount to `BankService`. The service finds the user's account and asks `Account` to deposit or withdraw the amount. The account updates its balance only when the transaction is valid.
5. **Balance check:** `BankService` finds the account associated with the logged-in user ID and returns its balance.
6. **Logout:** The active user ID is cleared, returning the program to the main menu.

## Menus

### Main Menu

| Option | Operation | What it does |
| --- | --- | --- |
| 1 | Create User | Prompts for a name and PIN, then displays the new user ID. |
| 2 | Create Account | Prompts for a user ID and displays the new account number. |
| 3 | Login | Prompts for a user ID and PIN. |
| 0 | Exit | Ends the program. |

### User Menu

This menu is available after a successful login.

| Option | Operation | What it does |
| --- | --- | --- |
| 1 | Deposit | Prompts for an amount and adds it to the balance if valid. |
| 2 | Withdraw | Prompts for an amount and subtracts it if valid and within the available balance. |
| 3 | Check Balance | Displays the current balance. |
| 4 | Logout | Returns to the main menu. |

## Build and Run

You need a C++ compiler that supports C++11, such as g++ from MinGW-w64.

Open PowerShell in the project folder and compile the program:

```powershell
g++ -std=c++11 -Wall -Wextra -pedantic -Isrc src\main.cpp src\services\BankService.cpp src\models\Account.cpp src\models\User.cpp -o banking_system.exe
```

Start the application:

```powershell
.\banking_system.exe
```

Run the compile command again after changing any source files. If PowerShell reports that `g++` is not recognized, install a C++ compiler and make sure its `g++` command is available on your PATH.

## Example Session

On a fresh run, the first user ID is `1` and the first account number is `1001`.

1. At the main menu, enter **1** to create a user.
2. Enter a one-word name, such as `Harsh`, and a PIN, such as `1234`. Note the user ID displayed.
3. At the main menu, enter **2** and provide that user ID to create an account.
4. Enter **3** and log in with the user ID and PIN.
5. In the user menu, enter **1** and deposit `500`.
6. Enter **3** to check the balance; it should be `500`.
7. Enter **2** and withdraw `100`.
8. Enter **3** again; it should show `400`.
9. Enter **4** to log out, then **0** to exit.

## Concepts Practiced

- Classes, private data, and public methods
- Separating class declarations (`.h`) from implementations (`.cpp`)
- Organizing source files into model and service folders
- Managing collections with `std::vector`
- Passing data between the menu, service, and model layers
- Using Git commits to track changes

## Current Limitations

- Users, accounts, and balances are stored only in memory and are cleared when the program exits.
- The menu and transaction methods identify accounts by user ID, so the current design is intended for one account per user.
- Names are read as one word, so names containing spaces are not supported.
- This is a learning project, not a production banking system.