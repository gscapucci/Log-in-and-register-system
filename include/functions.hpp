#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "user.hpp"
#include <vector>
#include <string>
#include <fstream>

void readFile(std::vector<User>& userList);
void writeFile(std::vector<User>& userList);
void admLogin(std::vector<User>& userList);
void addUser(std::vector<User>& userList);
void cls();
void menu();

#endif /* FUNCTIONS_HPP */