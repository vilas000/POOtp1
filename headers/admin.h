#ifndef ADMIN_H
#define ADMIN_H

using namespace std;
#include "user.h"
#include "vendedor.h"
#include "mecanico.h"
#include <vector>

class Admin : public User{
    public:
    Admin(string usuario, string senha, string nome);
    ~Admin();
    bool autenticar(string senha) const;
    void editarDadosVendedor(Vendedor &vendedor);
    void editarDadosMecanico(Mecanico &mecanico);
    void exibirOpcoes(vector<Vendedor> &vendedores, vector<Mecanico> &mecanicos);
};

#endif