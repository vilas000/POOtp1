#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User {

    string usuario, senha;

public:

    User(string usuario, string senha = "1234");
    User();
    ~User();

    bool autentica(string senha);

    string getUsuario() const;
    
};

#endif