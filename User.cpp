#include "User.h"

User :: User(string usuario, string senha) : usuario(usuario), senha(senha) {}
User :: User() {}
User :: ~User() {}

bool User :: autentica(string senha) {
    return this->senha == senha;
}

string User :: getUsuario() const {
    return this->usuario;
}