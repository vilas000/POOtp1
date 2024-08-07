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
    
    bool setSalario(double);
    bool demite(bool recontrata = 0);

public:
    Funcionario(string login, string senha, string nome = "Joe", string cpf = "000.000.000-00", int salario = 0);
    Funcionario();
    ~Funcionario();

    bool setCpf(string);

    string getCpf() const;
    string getNome() const;
    double getSalario() const;
    bool getIsDemitido() const;

};

#endif // FUNCIONARIO_H