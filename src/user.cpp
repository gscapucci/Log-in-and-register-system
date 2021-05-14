#include "../include/user.hpp"

int User::numberOfUsers = 0;

User::User(std::string user, std::string pass)
{
    this->username = user;
    this->password = pass;
    this->numberOfUsers++;
}

User::User()
{
    this->username = "";
    this->password = "";
    this->numberOfUsers++;
}

User::~User()
{
    this->numberOfUsers--;
}

void User::setUsername(std::string user)
{
    this->username = user;
}

void User::setPassword(std::string pass)
{
    this->password = pass;
}

std::string User::getUsername()
{
    return this->username;
}

std::string User::getPassword()
{
    return this->password;
}

void User::print()
{
    std::cout << this->username << std::endl;
}

