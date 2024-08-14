#ifndef MENU_H
#define MENU_H

#include "mecanico.h"
#include "vendedor.h"
#include "admin.h"
#include "cliente.h"

#include <vector>
#include <iostream>
using namespace std;

class Menu
{
    vector<User*> users;
    vector<Ordem> ordens;
    vector<Cliente> clientes;

    public:
        Menu();
        ~Menu();

        string login();
        string exibirOpcoes(User* u);
};

#endif