#include "User.h"

User::User(int userId, const std::string& name, int pin)
    : userId(userId), name(name), pin(pin) {}


bool User::verifyPin(int inputPin) const {
    return pin == inputPin;
}


int User::getUserId() const {
    return userId;
}

std::string User::getName() const {
    return name;
}
