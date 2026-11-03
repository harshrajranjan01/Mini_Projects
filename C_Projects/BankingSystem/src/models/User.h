#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int userId;
    std::string name;
    int pin;

public:
  
    User(int userId, const std::string& name, int pin);

 
    bool verifyPin(int inputPin) const;

  
    int getUserId() const;
    std::string getName() const;
};

#endif
