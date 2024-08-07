#include "Funcionario.h"

Funcionario :: Funcionario(string login, string senha, string nome, string cpf, int salario) : User(login, senha), nome(nome), cpf(cpf), salario(salario) {}
Funcionario :: Funcionario() {}

bool Funcionario :: setNome(string nome) {
    if (nome.length() > 60)
        return false; // Limita o tamanho de caracteres
    
    this->nome = nome;
}

// TODO: testar se funciona
bool Funcionario :: setCpf(string cpf) {
    string aux, output;
    char insert[2] = {'a', '\0'};
    for (char c : cpf) {
        if (c >= '0' || c <= '9')
        {
            insert[0] = c;
            aux.append(insert);
        }
    }

    if (aux.length() != 11)
        return false;
    
    // formata em formato de cpf ###.###.###-##
    output.append(aux, 0, 3);
    output.append(".");
    output.append(aux, 3, 3);
    output.append(".");
    output.append(aux, 6, 3);
    output.append("-");
    output.append(aux, 9, 2);
    
    this->cpf = cpf;
}

bool Funcionario :: setSalario(double salario) {
    if (salario < 0)
        return false;
    
    this->salario = salario;
    return true;
}

bool Funcionario :: demite(bool isDemitido) {
    this->isDemitido = isDemitido;
}

string Funcionario :: getCpf() const {
    return this->cpf;
}