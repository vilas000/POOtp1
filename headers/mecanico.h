#ifndef MECANICO_H
#define MECANICO_H

#include "funcionario.h"
#include "ordem.h"
#include <vector>
using namespace std;

class Mecanico : public Funcionario
{
    public:
        Mecanico(string usuario, string nome, string senha, int id);
        ~Mecanico();
        void visualizarOrdens(vector<Ordem> &ordens);
        friend ostream & operator<<(ostream& out, const Mecanico& mecanico);
        virtual bool autenticar(string senha) const;
        void exibirOpcoes(vector<Ordem> & ordens);    
        void cadastrarServicosPecas(vector<Ordem> &ordens);
        void executarOrdens(vector<Ordem> &ordens);
};

#endif