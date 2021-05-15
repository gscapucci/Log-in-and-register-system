#include "../include/functions.hpp"
#include "../include/admfunctions.hpp"

void readFile(std::vector<User>& userList)
{
    std::fstream userFile;

    userFile.open("../files/user.txt", std::ios::in);

    userFile.seekg(0, std::ios::end);
    int size = (int)userFile.tellg();
    if(size == -1)
    {
        userFile.close();
        return;
    }
    userFile.seekg(0, std::ios::beg);

    while (userFile.tellg() < size)
    {
        std::string username, password;
        User newUser;

        std::getline(userFile, username);
        std::getline(userFile, password);

        newUser.setUsername(username);
        newUser.setPassword(password);
        if(username.compare("adm") | (password == "\000" || username == "\000"))
            userList.push_back(newUser);
    }
}

void writeFile(std::vector<User>& userList)
{
    std::fstream userFile;

    userFile.open("../files/user.txt", std::ios::out | std::ios::trunc);
    for(int i = 0; i < userList.size(); i++)
    {
        userFile << userList[i].getUsername() << '\n';
        userFile << userList[i].getPassword() << '\n';
    }
}

void admLogin(std::vector<User>& userList)
{
    char op;
    do{
        cls();
        admMenu();
        std::cout << "Option:";
        std::cin >> op;
        std::cin.ignore();
        cls();
        switch (op)
        {
        case '1':
            addUser(userList);
            break;
        case '2':
            deleteUser(userList);
            break;
        case '3':
            std::cout << "Number of users: " << userList.size() << std::endl;
            std::cout << "Users:" << std::endl;
            listUsers(userList);
            break;
        case '4':
            break;
        default:
            std::cout << "invalid option." << std::endl;
            break;
        }
    }while(op != '4');
}

void addUser(std::vector<User>& userList)
{
    User newUser;
    bool validUser = true;
    std::string username, password;

    do{
        std::cout << "Type an username:";
        std::cin >> username;

        for(int i = 0; i < userList.size(); i++)
        {
            if(!username.compare(userList[i].getUsername()))
            {
                validUser = false;
                std::cout << username << "Already exist." << std::endl;
            }
            else
                validUser = true;
        }

    }while(!validUser);

    std::cout << "Type a password:";
    std::cin >> password;

    newUser.setUsername(username);
    newUser.setPassword(password);

    userList.push_back(newUser);
}

void cls()
{
    for(int i = 0; i < 50; i++)
        std::cout << std::endl;
}

void menu()
{
    std::cout << "--------MENU--------" << std::endl;
    std::cout << "1 - Login"            << std::endl;
    std::cout << "2 - Register"         << std::endl;
    std::cout << "3 - exit"             << std::endl;
    std::cout << "--------------------" << std::endl;
}

