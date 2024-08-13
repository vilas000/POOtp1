#include "headers/user.h"
#include <iostream>

// Construtor da classe User
User::User(string usuario, string senha, string nome){
    this->usuario = usuario;
    this->senha = senha;
    this->nome = nome;
}

// Metodo getter que retorna o nome de usuario de um determinado usuario
string User::getUsuario() const{
    return this->usuario;
}

// Metodo getter que retorna a senha de um determinado usuario
string User::getSenha() const{
    return this->senha;
}

// Metodo getter que retorna o nome de um determinado usuario
string User::getNome() const{
    return this->nome;
}
// Metodo setter que armazena um nome de usuario para um determinado usuario
void User::setUsuario(string usuario){
    this->usuario = usuario;
}

// Metodo setter que armazena uma senha para um determinado usuario
void User::setSenha(string senha){
    this->senha = senha;
}

// Metodo setter que armazena um nome para um determinado usuario
void User::setNome(string nome){
    this->nome = nome;
}























