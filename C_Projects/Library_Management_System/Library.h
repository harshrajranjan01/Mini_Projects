#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <vector>

class Library
{
private:
    std::vector<Book> books;
    // Stores a dynamic collection of Book objects; using std:: avoids namespace pollution in header files

public:
    void addBook(const Book &b);
    void displayAll() const;
    void sortByPrice(); // need to change the order of books arranged
    bool findById(int id) const;
};

#endif