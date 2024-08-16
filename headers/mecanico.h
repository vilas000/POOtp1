#ifndef MECANICO_H
#define MECANICO_H

#include "funcionario.h"
#include "ordem.h"
#include "valida.h"
#include <vector>
#include <unistd.h>

using namespace std;

class Vendedor;

class Mecanico : public Funcionario
{
    public:
        Mecanico(string usuario, string nome, string senha, int id);
        ~Mecanico();
        void visualizarOrdens(vector<Ordem> &ordens);
        friend ostream & operator<<(ostream& out, const Mecanico& mecanico);
        void exibirOpcoes(vector<Ordem> & ordens);    
        void cadastrarServicosPecas(vector<Ordem> &ordens);
        void executarOrdens(vector<Ordem> &ordens);
};

#endif