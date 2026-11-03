#include "LibraryService.h"
#include "Book.h"
#include "Student.h"
#include <iostream>

using namespace std;

void LibraryService::addBook()
{
    Book b;
    cin >> b;
    library.addBook(b);
    cout << "Book added sucessfully" << endl;
}

void LibraryService::displayBooks() const
{
    library.displayAll();
}

void LibraryService::sortBooks()
{
    library.sortByPrice();
    cout << "Books are sorted by price" << endl;
}

void LibraryService::SearchBook() const
{
    int id;
    cout << "Enter Book Id: " << endl;
    cin >> id;

    if (library.findById(id))
    {
        cout << "Book Found" << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

void LibraryService::fileMenu()
{
    int ch;
    cout << "\n 1. Save Books" << endl
         << "2. Display File Books" << endl
         << "3. Update Price " << endl
         << "....Enter YOur Choice...." << endl;
    cin >> ch;

    if (ch == 1)
    {
        Book b;
        cin >> b;
        b.writeToFile();
    }

    else if (ch == 2)
    {
        Book::readAllFromFile();
    }
    else if (ch == 3)
    {
        int id;
        float price;
        cout << "Enter ID and New Price: " << endl;
        cin>>id>>price;
        Book::updatePriceById(id, price);
    }
}

void LibraryService::studentFine() const
{
    int id, days;
    string name;
    cout << "Enter Student Id, Name and DaysLate " << endl;
    cin >> id >> name >> days;

    User *u = new Student(id, name, days);
    u->display();
    delete u;
}