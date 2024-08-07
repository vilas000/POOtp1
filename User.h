#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {

    friend class Menu;

    string usuario, senha;

public:

    User(string usuario, string senha = "1234");

    bool autentica(string senha);
    
};

#endif