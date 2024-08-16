#include "headers/admin.h"
#include "headers/cliente.h"
#include "headers/funcionario.h"
#include "headers/mecanico.h"
#include "headers/ordem.h"
#include "headers/produtos.h"
#include "headers/servicos.h"
#include "headers/user.h"
#include "headers/veiculo.h"
#include "headers/vendedor.h"
#include "headers/menu.h"
#include "headers/valida.h"
#include <iostream>

int validaa(string);

int main(){
    
    Menu* main = new Menu();

    string input, errorMsg = "";
    int op;

    do
    {
        system("clear");
        cout << errorMsg << "Bem-vindo ao sistema!\n\n1. Efetuar login\n2. Sair\n";
        cin >> input;

        op = valida(input);
        
        if (op == 1)
            errorMsg = main->login();
        else if (op == 2)
            break;

    } while (true);
    

    delete main;

    return 0;
}

