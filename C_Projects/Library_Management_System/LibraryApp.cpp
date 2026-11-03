#include "LibraryApp.h"
#include "LibraryService.h"

#include <iostream>
#include <limits>

void LibraryApp::run()
{
    LibraryService services;
    int choice = -1;

    while (true)
    {
        std::cout << "\n....LIBRARY MANAGEMENT SYSTEM....\n"
                  << "1. Add Book\n"
                  << "2. Display Books\n"
                  << "3. Sort Books\n"
                  << "4. Search Book\n"
                  << "5. File Operations\n"
                  << "6. Student Fine\n"
                  << "0. Exit\n"
                  << "Enter choice: ";

        if (!(std::cin >> choice))
        {
            if (std::cin.eof())
            {
                return;
            }
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "Invalid choice. Enter a menu number.\n";
            continue;
        }

        switch (choice)
        {
        case 0:
            return;
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
            std::cout << "Invalid choice.\n";
            break;
        }
    }
}
