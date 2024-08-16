#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "user.h"
#include "funcionario.h"
#include "ordem.h"
#include "valida.h"
#include <vector>
#include <unistd.h>

class Vendedor : public Funcionario{
    public:
        Vendedor(int idFuncionario, string usuario, string senha, string nome);
        ~Vendedor();
        bool cadastrarCliente(vector<Cliente> &clientes);
        Ordem gerarOrdemServico( Cliente & cliente);
        void visualizarAprovar(vector<Ordem> &ordens);
        void visualizarOrdensExecutadas(vector<Ordem> &ordens);
        void exibirOpcoes(vector<Ordem> & ordem, vector<Cliente> &cliente);
        void imprimeClientes(vector<Cliente>& clientes);

};

#endif