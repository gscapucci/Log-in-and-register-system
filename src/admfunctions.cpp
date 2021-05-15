#include "../include/admfunctions.hpp"
#include "../include/functions.hpp"

void admMenu()
{
    std::cout << "------ADM-MENU------" <<  std::endl;
    std::cout << "1 - Add user"         <<  std::endl;
    std::cout << "2 - Delete user"      <<  std::endl;
    std::cout << "3 - List users"       <<  std::endl;
    std::cout << "4 - Exit"             <<  std::endl;
    std::cout << "--------------------" <<  std::endl;
}

void listUsers(std::vector<User>& userList)
{
    for (int i = 0; i < userList.size(); i++)
        userList[i].print();
}

void deleteUser(std::vector<User>& userList)
{
    std::string username;
    std::cout << "Type an username:";
    std::cin >> username;
    if(!username.compare(userList[0].getUsername()))
    {
        cls();
        std::cout << "You can't delete adm." << std::endl;
        std::cin.ignore();
        std::cin.get();
        return;
    }
    for(int i = 0; i < userList.size(); i++)
    {
        if(!(username.compare(userList[i].getUsername())))
        {
            userList.erase(userList.begin() + i);
            std::cout << username << " was deleted." << std::endl;
            std::cin.ignore();
            std::cin.get();
            return;
        }
    }
    std::cout << username << " was not found." << std::endl;
}