#include "Funcionario.h"

Funcionario :: Funcionario(string login, string senha, string nome, string cpf, int salario = 0) : User(login, senha), nome(nome), cpf(cpf), salario(salario) {}

bool Funcionario :: setNome(string nome) {
    // Implementar
}

bool Funcionario :: setCpf(string nome) {
    // Implementar
}

bool Funcionario :: setSalario(double salario) {
    // Implementar
}

bool Funcionario :: demite(bool isDemitido) {
    // Implementar
}