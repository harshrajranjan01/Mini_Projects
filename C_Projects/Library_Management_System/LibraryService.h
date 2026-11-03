#ifndef LIBRARY_SERVICE_H
#define LIBRARY_SERVICE_H

#include "Library.h"
class LibraryService
{
private:
    Library library;

public:
    void addBook();
    void displayBooks() const;
    void sortBooks();
    void SearchBook() const;

    // file related
    void fileMenu();

    // User Related
    void studentFine() const;
};
#endif