#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    int id;
    string title;
    float price;

    static int bookCount; // Count Number of books object are created (must be static)

public:
    Book();
    Book(int, string, float); //// may throw exception
    void display() const;

    Book(const Book &); // copy constructor

    void setData(int, string, float); // set id, name, and price to books;
    void setData(int, string);        // run in case, the price of book is not known at that time

    static int getBookCount(); // static funciton

    friend istream &operator>>(istream &, Book &); // these need iostream library
    friend ostream &operator<<(ostream &, const Book &);

    Book operator++(); // Preincrement operator

    // File Handling

    void writeToFile() const;
    static void readAllFromFile();

    static bool updatePriceById(int SearchId, float newPrice);

    int getId() const;
    float getPrice() const;
};

#endif