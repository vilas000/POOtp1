#include "headers/funcionario.h"
#include <iostream>
// Construtor da classe Funcionario.
Funcionario::Funcionario(int id, string usuario, string senha, string nome) : User(usuario, senha, nome), idFuncionario(id){}// Inicializa um objeto Funcionario com os valores fornecidos para id, usuario, senha e nome.
    
void Funcionario::setId(int id){// Metodo setter para 'idFuncionario'.
    this->idFuncionario = id;
}
int Funcionario::getId() const{// Metodo getter para 'idFuncionario'.
    return this->idFuncionario;
}

bool Funcionario::setId(string id) {
    int aux;

    try
    {
        aux = stoi(id);
    }
    catch(const std::exception& e)
    {
        cout << e.what();
        return false;
    }
    
    idFuncionario = aux;
    return true;
}