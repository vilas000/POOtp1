#include "headers/cliente.h"
#include <iostream>

// Construtor da classe Cliente, responsavel por inicializar os membros da classe.
Cliente::Cliente(string nome, string telefone, int km, string modelo, string placa){
    this->nome = nome;// Atribui o valor do parametro 'nome' ao membro 'nome' da classe Cliente.
    this->telefone = telefone;// Atribui o valor do parametro 'telefone' ao membro 'telefone' da classe Cliente.
    Veiculo veiculo {placa, modelo, km}; // Cria um objeto do tipo Veiculo usando os valores fornecidos para placa, modelo e quilometragem.
    veiculos.push_back(veiculo);// Adiciona o objeto Veiculo criado ao vetor 'veiculos', que armazena todos os veiculos associados ao cliente.
}
// Destrutor da classe Cliente. É chamado quando um objeto Cliente é destruido.
Cliente::~Cliente(){}

string Cliente::getNome() const{// Metodo getter para o membro 'nome'. Retorna o nome do cliente.
    return nome;
};

string Cliente::getTelefone() const{// Metodo getter para o membro 'telefone'. Retorna o telefone do cliente
    return telefone;
};

vector<Veiculo> Cliente::getVeiculo() const{// Metodo getter para o vetor 'veiculos'. Retorna uma copia do vetor de veiculos do cliente.
    return veiculos;
}

void Cliente::setTelefone(string telefone){// Metodo setter para o membro 'telefone'. Permite alterar o telefone do cliente.
    this->telefone = telefone;
}

void Cliente::setVeiculo(Veiculo veiculo){// Metodo que adiciona um veiculo ao vetor 'veiculos'.
    veiculos.push_back(veiculo);
}

void Cliente::adicionarVeiculo(string placa, string modelo, int quilometragem){// Metodo que cria e adiciona um novo veiculo ao vetor 'veiculos'.
    Veiculo veiculo {placa,modelo,quilometragem};
    veiculos.push_back(veiculo);
}

ostream& operator<<(ostream& out, const Cliente &cliente){
        out <<  "Nome: " << cliente.getNome() << " " <<  "Telefone: " << cliente.getTelefone() << endl << " " << "Dados veículo: " << cliente.veiculos.at(0).getPlaca() << " | " << cliente.veiculos.at(0).getModelo() << endl;
        cout << endl;
        return out;
}


