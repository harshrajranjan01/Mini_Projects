#include "Book.h"

#include <cmath>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <utility>

namespace
{
const char fileMagic[] = {'L', 'I', 'B', 'B', 'O', 'O', 'K', '1'};
const std::uint32_t maxTitleLength = 1024U * 1024U;

bool writeStorageHeader(std::ostream &out)
{
    out.write(fileMagic, sizeof(fileMagic));
    return static_cast<bool>(out);
}

bool readStorageHeader(std::istream &in)
{
    char magic[sizeof(fileMagic)] = {};
    if (!in.read(magic, sizeof(magic)))
    {
        return false;
    }

    for (std::size_t i = 0; i < sizeof(fileMagic); ++i)
    {
        if (magic[i] != fileMagic[i])
        {
            return false;
        }
    }
    return true;
}

bool writeRecord(std::ostream &out, int id, const std::string &title, float price)
{
    if (title.size() > maxTitleLength ||
        id < (std::numeric_limits<std::int32_t>::min)() ||
        id > (std::numeric_limits<std::int32_t>::max)())
    {
        return false;
    }

    const std::int32_t storedId = static_cast<std::int32_t>(id);
    const std::uint32_t titleLength = static_cast<std::uint32_t>(title.size());

    out.write(reinterpret_cast<const char *>(&storedId), sizeof(storedId));
    out.write(reinterpret_cast<const char *>(&titleLength), sizeof(titleLength));
    if (!title.empty())
    {
        out.write(title.data(), static_cast<std::streamsize>(title.size()));
    }
    out.write(reinterpret_cast<const char *>(&price), sizeof(price));
    return static_cast<bool>(out);
}

bool readRecord(std::istream &in, int &id, std::string &title, float &price,
                std::streampos *pricePosition = 0)
{
    std::int32_t storedId = 0;
    std::uint32_t titleLength = 0;
    if (!in.read(reinterpret_cast<char *>(&storedId), sizeof(storedId)) ||
        !in.read(reinterpret_cast<char *>(&titleLength), sizeof(titleLength)) ||
        titleLength > maxTitleLength)
    {
        return false;
    }

    title.assign(titleLength, '\0');
    if (titleLength > 0 &&
        !in.read(&title[0], static_cast<std::streamsize>(titleLength)))
    {
        return false;
    }

    if (pricePosition)
    {
        *pricePosition = in.tellg();
    }
    if (!in.read(reinterpret_cast<char *>(&price), sizeof(price)))
    {
        return false;
    }

    id = static_cast<int>(storedId);
    return true;
}
}

int Book::bookCount = 0;

Book::Book() : id(0), title("NA"), price(0.0f)
{
    ++bookCount;
}

Book::Book(int bookId, std::string bookTitle, float bookPrice)
    : id(bookId), title(std::move(bookTitle)), price(bookPrice)
{
    if (!std::isfinite(bookPrice) || bookPrice < 0.0f)
    {
        throw std::invalid_argument("Book price cannot be negative");
    }
    ++bookCount;
}

Book::Book(const Book &other)
    : id(other.id), title(other.title), price(other.price)
{
    ++bookCount;
}

void Book::display() const
{
    std::cout << "Id: " << id
              << ", Title: " << title
              << ", Price: " << price << std::endl;
}

void Book::setData(int bookId, std::string bookTitle, float bookPrice)
{
    setPrice(bookPrice);
    id = bookId;
    title = std::move(bookTitle);
}

void Book::setData(int bookId, std::string bookTitle)
{
    id = bookId;
    title = std::move(bookTitle);
    price = 0.0f;
}

void Book::setPrice(float newPrice)
{
    if (!std::isfinite(newPrice) || newPrice < 0.0f)
    {
        throw std::invalid_argument("Book price cannot be negative");
    }
    price = newPrice;
}

int Book::getBookCount()
{
    return bookCount;
}

std::istream &operator>>(std::istream &in, Book &book)
{
    int newId = 0;
    std::string newTitle;
    float newPrice = 0.0f;

    if (in >> newId >> newTitle >> newPrice)
    {
        if (!std::isfinite(newPrice) || newPrice < 0.0f)
        {
            in.setstate(std::ios::failbit);
        }
        else
        {
            book.id = newId;
            book.title = std::move(newTitle);
            book.price = newPrice;
        }
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Book &book)
{
    out << "Id: " << book.id
        << ", Title: " << book.title
        << ", Price: " << book.price;
    return out;
}

Book &Book::operator++()
{
    price += 10.0f;
    return *this;
}

bool Book::writeToFile(std::ostream &out) const
{
    return writeRecord(out, id, title, price);
}

bool Book::writeFileHeader(std::ostream &out)
{
    return writeStorageHeader(out);
}

bool Book::readFileHeader(std::istream &in)
{
    return readStorageHeader(in);
}

bool Book::readFromFile(std::istream &in)
{
    int bookId = 0;
    std::string bookTitle;
    float bookPrice = 0.0f;
    if (!readRecord(in, bookId, bookTitle, bookPrice) ||
        !std::isfinite(bookPrice) || bookPrice < 0.0f)
    {
        return false;
    }

    id = bookId;
    title = std::move(bookTitle);
    price = bookPrice;
    return true;
}

bool Book::readAllFromFile()
{
    std::ifstream file("books.dat", std::ios::binary);
    if (!file)
    {
        std::cout << "No saved books found." << std::endl;
        return false;
    }

    if (!readFileHeader(file))
    {
        std::cout << "Unable to read the books file." << std::endl;
        return false;
    }

    bool foundAny = false;
    while (file.peek() != std::char_traits<char>::eof())
    {
        Book book;
        if (!book.readFromFile(file))
        {
            std::cout << "Unable to read a book record." << std::endl;
            return false;
        }

        book.display();
        foundAny = true;
    }

    if (!foundAny)
    {
        std::cout << "No books saved in the file." << std::endl;
    }
    return true;
}

bool Book::updatePriceById(int searchId, float newPrice)
{
    if (!std::isfinite(newPrice) || newPrice < 0.0f)
    {
        return false;
    }

    std::fstream file("books.dat", std::ios::binary | std::ios::in | std::ios::out);
    if (!file || !readFileHeader(file))
    {
        return false;
    }

    while (file.peek() != std::char_traits<char>::eof())
    {
        int id = 0;
        std::string title;
        float price = 0.0f;
        std::streampos pricePosition;
        if (!readRecord(file, id, title, price, &pricePosition))
        {
            return false;
        }

        if (id == searchId)
        {
            file.seekp(pricePosition);
            file.write(reinterpret_cast<const char *>(&newPrice), sizeof(newPrice));
            file.flush();
            return static_cast<bool>(file);
        }
    }
    return false;
}

int Book::getId() const
{
    return id;
}

float Book::getPrice() const
{
    return price;
}
