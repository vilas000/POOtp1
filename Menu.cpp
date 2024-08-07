#include "Menu.h"
#include "User.h"

Menu :: Menu(vector<User*> users) : users(users) {
    printf("Bem vindo(a) ao programa. Informe usuário e senha para efetuar login.");
};

bool Menu :: login(string usuario, string senha) {
    for(auto var : users) {
        if(var->getUsuario() == usuario && var->autentica(senha))
            return true; // Sucesso! Credenciais corretas.
    }

    return false; // Falha. Usuário ou senha incorretos.
}