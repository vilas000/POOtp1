#ifndef ADMIN_H
#define ADMIN_H

using namespace std;
#include "user.h"
#include "vendedor.h"
#include "mecanico.h"
#include "valida.h"
#include <vector>

class Admin : public User{
    public:
    Admin(string usuario, string senha, string nome);
    ~Admin();

    void editarDadosFuncionario(Funcionario* funcionario);

    void exibirOpcoes(vector<User*> users);
};

#endif