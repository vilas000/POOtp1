#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include "User.h"

using namespace std;

class Funcionario : User {

    friend class Admin;

    string nome, cpf;
    double salario;
    bool isDemitido;

    bool setNome(string);
    bool setCpf(string);
    bool setSalario(double);
    bool demite(bool recontrata = 0);

public:
    Funcionario(string login, string senha, string nome, string cpf, int salario = 0);

};

#endif // FUNCIONARIO_H