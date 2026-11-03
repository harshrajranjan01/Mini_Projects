#include "LibraryApp.h"
#include "LibraryService.h"

#include <iostream>

using namespace std;

void LibraryApp::run()
{
    LibraryService services;
    int choice;

    do
    {
        cout << "\n....IBRARY MANAGEMENT SYSTEM...\n";
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Sort Books" << endl;
        cout << "4. Search Book" << endl;
        cout << "5. File Operations" << endl;
        cout << "6. Student Fine" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: " << endl;
        ;
        cin >> choice;

        switch (choice)
        {
        case 1:
            services.addBook();
            break;
        case 2:
            services.displayBooks();
            break;
        case 3:
            services.sortBooks();
            break;
        case 4:
            services.SearchBook();
            break;
        case 5:
            services.fileMenu();
            break;
        case 6:
            services.studentFine();
            break;
        default:
            cout << "Invalid Choice" << endl;
        }

    } while (choice != 0);
}