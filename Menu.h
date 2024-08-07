#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class User;

class Menu {

vector<User*> users;

public:
    Menu(vector<User*> users);
    ~Menu();

    bool login(string usuario, string senha);
};

#endif