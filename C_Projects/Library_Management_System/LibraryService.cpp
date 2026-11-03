#include "LibraryService.h"
#include "Book.h"
#include "Student.h"

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace
{
void recoverInput()
{
    std::cin.clear();
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}
}

LibraryService::LibraryService()
{
    library.loadFromFile();
}

void LibraryService::addBook()
{
    Book book;
    std::cout << "Enter Id, Title (one word) and Price: ";
    if (!(std::cin >> book))
    {
        if (!std::cin.eof())
        {
            recoverInput();
        }
        std::cout << "Invalid book details. Please enter a non-negative price.\n";
        return;
    }

    library.addBook(book);
    std::cout << "Book added successfully.\n";
}

void LibraryService::displayBooks() const
{
    library.displayAll();
}

void LibraryService::sortBooks()
{
    library.sortByPrice();
    std::cout << "Books are sorted by price.\n";
}

void LibraryService::SearchBook() const
{
    int id = 0;
    std::cout << "Enter Book Id: ";
    if (!(std::cin >> id))
    {
        if (!std::cin.eof())
        {
            recoverInput();
        }
        std::cout << "Invalid book ID.\n";
        return;
    }

    if (library.findById(id))
    {
        std::cout << "Book Found.\n";
    }
    else
    {
        std::cout << "Book not found.\n";
    }
}

void LibraryService::fileMenu()
{
    int choice = -1;
    std::cout << "\n1. Save Library Books\n"
              << "2. Display File Books\n"
              << "3. Update Price\n"
              << "Enter your choice: ";
    if (!(std::cin >> choice))
    {
        if (!std::cin.eof())
        {
            recoverInput();
        }
        std::cout << "Invalid choice.\n";
        return;
    }

    switch (choice)
    {
    case 1:
        if (library.saveToFile())
        {
            std::cout << "Library books saved to books.dat.\n";
        }
        else
        {
            std::cout << "Unable to save books.dat.\n";
        }
        break;
    case 2:
        Book::readAllFromFile();
        break;
    case 3:
    {
        int id = 0;
        float price = 0.0f;
        std::cout << "Enter ID and new price: ";
        if (!(std::cin >> id >> price))
        {
            if (!std::cin.eof())
            {
                recoverInput();
            }
            std::cout << "Invalid ID or price.\n";
            break;
        }
        if (!std::isfinite(price) || price < 0.0f)
        {
            std::cout << "Price cannot be negative.\n";
            break;
        }

        const bool updatedFile = Book::updatePriceById(id, price);
        const bool updatedLibrary = library.updatePriceById(id, price);
        if (updatedFile || updatedLibrary)
        {
            std::cout << "Price updated.\n";
        }
        else
        {
            std::cout << "Book ID not found.\n";
        }
        break;
    }
    default:
        std::cout << "Invalid choice.\n";
        break;
    }
}

void LibraryService::studentFine() const
{
    int id = 0;
    int days = 0;
    std::string name;
    std::cout << "Enter Student Id, Name and DaysLate: ";
    if (!(std::cin >> id >> name >> days))
    {
        if (!std::cin.eof())
        {
            recoverInput();
        }
        std::cout << "Invalid student details.\n";
        return;
    }

    try
    {
        Student student(id, name, days);
        User &user = student;
        user.display();
    }
    catch (const std::invalid_argument &error)
    {
        std::cout << error.what() << '\n';
    }
}
