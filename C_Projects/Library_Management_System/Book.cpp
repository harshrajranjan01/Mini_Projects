#include "Book.h"
#include <iostream>
#include <fstream>

int Book::bookCount = 0;
Book::Book() // Book Constructor outside class
{

    id = 0;
    title = "NA";
    price = 0;
    bookCount++;
}

Book::Book(int i, string t, float p)
{
    if (p < 0) // exception handling
    {
        throw invalid_argument("Book Price Cannot Be negative");
    }

    id = i;
    title = t;
    price = p;
    bookCount++;
}

void Book::display() const
{
    cout << "Id: " << id
         << ", Title: " << title
         << ", Price: " << price << endl;
}

Book::Book(const Book &b)
{
    id = b.id;
    title = b.title;
    price = b.price;
    bookCount++;
}

void Book::setData(int i, string t, float p)
{
    id = i;
    title = t;
    price = p;
}

void Book::setData(int i, string t)
{
    id = i;
    title = t;
    price = 0;
}

int Book::getBookCount()
{
    return bookCount;
}

istream &operator>>(istream &in, Book &b)
{
    cout << "Enter Id, Title and Price: " << endl;
    cin >> b.id >> b.title >> b.price;
    return in;
}

ostream &operator<<(ostream &out, const Book &b)
{
    out << "Id: " << b.id
        << " Title: " << b.title
        << "Price: " << b.price << endl;
    return out;
}

Book Book::operator++()
{
    price = price + 10; // increase price
    return *this;
}

void Book::writeToFile() const
{
    ofstream fout("books.dat", ios::binary | ios::app);

    if (!fout)
    {
        cout << "Error Opening File" << endl;
        return;
    }

    fout.write((char *)this, sizeof(*this)); // this-> current object in memory
    fout.close();
}

void Book::readAllFromFile()
{
    ifstream fin("books.dat", ios::binary);
    if (!fin)
    {
        cout << "File Not found" << endl;
        return;
    }

    Book temp;

    while (fin.read((char *)&temp, sizeof(temp)))
    {
        temp.display();
    }
    fin.close();
}

bool Book::updatePriceById(int SearchId, float newPrice)
{
    fstream file("books.dat", ios::binary | ios::in | ios::out);

    if (!file)
    {
        cout << "Failed TO open file" << endl;
        return false;
    }

    Book temp;

    while (file.read((char *)&temp, sizeof(temp)))
    {
        if (temp.id == SearchId)
        {
            temp.price = newPrice;

            int pos = -1 * (int)sizeof(temp);
            file.seekp(pos, ios::cur);

            file.write((char *)&temp, sizeof(temp));

            return true;
        }
    }
    file.close();
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