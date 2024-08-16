#ifndef ORDEM_H
#define ORDEM_H

using namespace std;
#include <iostream> 
#include "servicos.h"
#include "produtos.h"
#include <vector>


enum status{
    encerrada,
    manutencao,
    orcamento,
    executada
};

class Cliente;
class Veiculo;
class Servicos;
class Produtos;

class Ordem
{
    private:
        Cliente *cliente;
        Veiculo *veiculo;
        string motivo;
        int *status; // 0 = encerrada, 1 = manutencao, 2 = orcamento, 3 = executada
        int idOrdem;
        bool *aprovada;
        bool isOrcamentoGerado;
        float custoTotal;
        // vector<Servicos> servicos;
        // vector<Produtos> pecas;
        vector<Servicos*> servicos;
        vector<Produtos*> pecas; 

    public:
        Ordem(Cliente *cliente, Veiculo *veiculo, string motivo = " ", int status = -1, int idOrdem = 0, bool aprovada = false, bool isOrcamentoGerado = false, float custo = 0);
        Ordem(const Ordem& outro);
        ~Ordem();
        void calcularCusto();
        void adicionarServico();
        void adicionarPeca();
        void listaOrcamento();
        void setAprovada(bool decisao);
        void setOrcamentoTrue();
        void encerrarOrdem();
        int getIdOrdem() const;
        int getStatus() const;
        float getCusto() const;
        const vector<Servicos*> &getServicos() const;
        const vector<Produtos*> &getPecas() const;
        Veiculo* getVeiculo() const;
        Cliente* getCliente() const;
        string getMotivo() const;
        bool getAprovada() const;
        void setStatus(int status);
        bool getOrcamento() const;
        friend ostream& operator<<(ostream& out, const Ordem& ordem);
        
};

#endif