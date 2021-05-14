#ifndef USER_HPP
#define USER_HPP

#include <iostream>
class User{
    std::string username, password;
    static int numberOfUsers;

    public:

    User(std::string user, std::string pass);
    User();
    ~User();
    void setUsername(std::string user);
    void setPassword(std::string pass);
    std::string getUsername();
    std::string getPassword();
    void print();
};

#endif /* USER_HPP */