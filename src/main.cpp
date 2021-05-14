#include "../include/functions.hpp"

int main()
{
    char op;
    std::string username, password;
    std::vector<User> userList;

    userList.push_back(User("adm", "adm"));

    readFile(userList);
    do{
        cls();
        menu();
        std::cout << "Option:";
        std::cin >> op;
        std::cin.ignore();
        switch (op)
        {
        case '1':
            cls();
            std::cout << "Type your username:";
            std::cin >> username;
            std::cout << "Type your password:";
            std::cin >> password;
            if(!username.compare(userList[0].getUsername()) && !password.compare(userList[0].getPassword()))
                admLogin(userList);
            else
            {
                int i;
                for(i = 1; i < userList.size(); i++)
                {
                    if((!username.compare(userList[i].getUsername())) && (!password.compare(userList[i].getPassword())))
                    {
                        std::cout << "Successfully logged in!" << std::endl;
                        std::cout << "Press any key to continue.";
                        std::cin.ignore();
                        std::cin.get();
                        break;
                    }
                }
                if(i == userList.size())
                {
                    std::cout << "Username or password are incorrect." << std::endl;
                    std::cout << "Press any key to continue.";
                    std::cin.ignore();
                    std::cin.get();
                }
            }
            break;
        case '2':
            cls();
            addUser(userList);
            break;
        case '3':
            break;
        default:
            cls();
            std::cout << "Invalid option." << std::endl;
            std::cin.get();
            break;
        }
    }while(op != '3');
    writeFile(userList);
}