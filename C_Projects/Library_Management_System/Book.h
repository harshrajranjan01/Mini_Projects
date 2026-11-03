#ifndef BOOK_H
#define BOOK_H

#include <iosfwd>
#include <string>

class Book
{
private:
    int id;
    std::string title;
    float price;

    static int bookCount;

public:
    Book();
    Book(int id, std::string title, float price);
    Book(const Book &other);

    void display() const;
    void setData(int id, std::string title, float price);
    void setData(int id, std::string title);
    void setPrice(float newPrice);

    static int getBookCount();

    friend std::istream &operator>>(std::istream &in, Book &book);
    friend std::ostream &operator<<(std::ostream &out, const Book &book);

    Book &operator++();

    bool writeToFile(std::ostream &out) const;
    static bool writeFileHeader(std::ostream &out);
    static bool readFileHeader(std::istream &in);
    bool readFromFile(std::istream &in);
    static bool readAllFromFile();
    static bool updatePriceById(int searchId, float newPrice);

    int getId() const;
    float getPrice() const;
};

#endif
