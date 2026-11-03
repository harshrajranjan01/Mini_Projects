#include "User.h"
#include<iostream>

User::User(int Id, string n)
{
    userId=Id;
    name=n;
}

void User::display() const
{
    cout<<"User Id: "<<userId<<" Name: "<<name<<endl;
}

User::~User()
{

}
