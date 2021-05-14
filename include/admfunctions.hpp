#ifndef ADM_FUNCTION_HPP
#define ADM_FUNCTION_HPP

#include "user.hpp"
#include <vector>
#include <string>
#include <fstream>

void admMenu();
void listUsers(std::vector<User>& userList);
void deleteUser(std::vector<User>& userList);


#endif /* ADM_FUNCTION_HPP */