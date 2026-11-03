#include "Library.h"
#include <algorithm>
#include <cmath>
#include <fstream>

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

bool Library::updatePriceById(int id, float newPrice)
{
    if (!std::isfinite(newPrice) || newPrice < 0.0f)
    {
        return false;
    }

    std::vector<Book>::iterator it =
        find_if(books.begin(), books.end(),
                [id](const Book &book)
                {
                    return book.getId() == id;
                });

    if (it == books.end())
    {
        return false;
    }

    it->setPrice(newPrice);
    return true;
}

bool Library::saveToFile() const
{
    std::ofstream file("books.dat", std::ios::binary | std::ios::trunc);
    if (!file || !Book::writeFileHeader(file))
    {
        return false;
    }

    for (const Book &book : books)
    {
        if (!book.writeToFile(file))
        {
            return false;
        }
    }

    file.flush();
    return static_cast<bool>(file);
}

bool Library::loadFromFile()
{
    std::ifstream file("books.dat", std::ios::binary);
    if (!file || !Book::readFileHeader(file))
    {
        return false;
    }

    std::vector<Book> loadedBooks;
    while (file.peek() != std::char_traits<char>::eof())
    {
        Book book;
        if (!book.readFromFile(file))
        {
            return false;
        }
        loadedBooks.push_back(book);
    }

    books.swap(loadedBooks);
    return true;
}
