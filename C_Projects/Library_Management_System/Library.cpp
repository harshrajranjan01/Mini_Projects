#include "Library.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Library::addBook(const Book &b)
{
    books.push_back(b);
}

void Library::displayAll() const
{
    for (size_t i = 0; i < books.size(); i++)
    {
        const Book &b = books[i];  //Book b = books[i];-->this will crate copy of the book 
        b.display();
    }
}

void Library::sortByPrice()
{
    sort(books.begin(), books.end(),
         [](const Book &a, const Book &b)
         {
             return a.getPrice() < b.getPrice(); // it return true or false to sort happen
         });
}

bool Library::findById(int id) const
{
    std::vector<Book>::const_iterator it =
        find_if(books.begin(), books.end(),
                [id](const Book &b)
                {
                    return b.getId() == id;
                });

    return it != books.end();
}
