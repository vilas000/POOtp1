#include "headers/user.h"
#include <iostream>

// Construtor da classe User
User::User(string usuario, string senha, string nome) : usuario(usuario), senha(senha), nome(nome) {}

// Metodo getter que retorna o nome de usuario de um determinado usuario
string User::getUsuario() const{
    return this->usuario;
}

// Metodo setter que armazena um nome de usuario para um determinado usuario
void User::setUsuario(string usuario){
    this->usuario = usuario;
}

// Metodo setter que armazena uma senha para um determinado usuario
void User::setSenha(string senha){
    this->senha = senha;
}

// Metodo getter que retorna o nome de um determinado usuario
string User::getNome() const{
    return this->nome;
}
// Metodo setter que armazena um nome para um determinado usuario
void User::setNome(string nome){
    this->nome = nome;
}

bool User::autenticar(string usuario, string senha) {
    return this->senha == senha && this->usuario == usuario;
}






















