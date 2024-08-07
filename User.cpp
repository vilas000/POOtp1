#include "User.h"

User :: User(string usuario, string senha) : usuario(usuario), senha(senha) {}

User :: autentica(string senha) {
    return this.senha == senha;
}