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

        op = validaa(input);
        
        if (op == 1)
            errorMsg = main->login();
        else if (op == 2)
            break;

    } while (true);
    

    delete main;

    return 0;
}

int validaa(string aux){
    int opcao;
    try
    {
        opcao = stoi(aux);
    }
    catch(const std::exception& e)
    {
        return -1;
    }
    
    return opcao;
}