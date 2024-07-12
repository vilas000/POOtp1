#ifndef ADMIN_H
#define ADMIN_H

#include <string>

using namespace std;

#include "User.h"
#include "Funcionario.h"

class Admin : User {

public:
    Admin(string usuario = "admin", string senha = "admin");
    bool editarFunc(Funcionario& funcionario, short operacao, string novo = "");
};

#endif