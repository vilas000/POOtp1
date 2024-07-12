#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class User;

class Menu {

vector<User> users;

public:
    Menu(vector<User>);
    ~Menu();
};

#endif