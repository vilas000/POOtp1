#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <vector>
#include "veiculo.h"
using namespace std;

class Cliente{
    private:
        string nome;
        string telefone;
        vector<Veiculo> veiculos;
    public:
        Cliente(string nome = " ", string telefone = " ", int km = 0, string modelo = " ", string placa = " ");
        ~Cliente();
        string getNome() const;
        string getTelefone() const;
        vector<Veiculo> getVeiculo() const;
        void setTelefone(string telefone);
        void setVeiculo(Veiculo veiculo);
        void adicionarVeiculo(string placa, string modelo, int quilometragem);
        friend ostream& operator<<(ostream& out, const Cliente &cliente);
};

#endif