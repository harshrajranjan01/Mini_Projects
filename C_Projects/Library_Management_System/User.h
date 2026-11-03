#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

class User
{
    
private:
    int userId;
    string name;

public:

    User(int, string);
    virtual float calculateFine() const = 0; // pure virtual function
    virtual void display() const;
    virtual ~User(); // Virtual Destructor (important)
};

#endif