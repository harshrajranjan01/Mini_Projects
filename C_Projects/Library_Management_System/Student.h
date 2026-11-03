#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"

class Student : public User
{
private:
    int DaysLate;

public:
    Student(int, string, int);
     float calculateFine() const override;
    void display() const override;
};

#endif