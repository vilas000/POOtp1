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
#include <iostream>

void administradorMenu(Admin admin, vector<Vendedor> &vendedores, vector<Mecanico> &mecanicos);
void login(Admin super, vector<Vendedor> &vendedores, vector<Mecanico> &mecanicos, vector<Cliente> &clientes, vector<Ordem> &ordens);
void Menu(vector<Vendedor> &vendedores, vector<Mecanico> &mecanicos, Admin &admin, vector<Cliente> &clientes, vector<Ordem> &ordens);

int main(){
    Admin super{"super", "2024", ""};

    // Completando o vetor de clientes
    vector<Cliente> clientes;
    Cliente cliente0 {"Roberto", "3434", 143, "fox", "AB88"};
    Cliente cliente1 {"Sabrina", "2030", 2856, "celta", "NK20"};
    Cliente cliente2 {"Marcia", "1978", 9865, "corsa", "AT67"};
    Cliente cliente3 {"Claudio", "8742", 0, "creta", "HJ54"};
    Cliente cliente4 {"Medusa", "1111", 111, "ranger", "Z3US"};
    clientes.push_back(cliente0); clientes.push_back(cliente1); clientes.push_back(cliente2); clientes.push_back(cliente3); clientes.push_back(cliente4); 

    //Completando o vetor de vendedores
    vector<Vendedor> vendedores;
    Vendedor vendedor0 {00, "vendedor0", "0000", "Fernando"};
    Vendedor vendedor1 {01, "vendedor1", "0001", "Bruna"};
    Vendedor vendedor2 {02, "vendedor2", "0002", "Marcelo"};
    Vendedor vendedor3 {03, "vendedor3", "0003", "Nicole"};
    Vendedor vendedor4 {04, "vendedor4", "0004", "Carlos"};
    Vendedor vendedor5 {05, "v", "1", "Manuel Debug"};
    vendedores.push_back(vendedor0); vendedores.push_back(vendedor1); vendedores.push_back(vendedor2); vendedores.push_back(vendedor3); vendedores.push_back(vendedor4); vendedores.push_back(vendedor5);
    
    //Completando o vetor de mecânicos
    vector<Mecanico> mecanicos;
    Mecanico mecanico0 {"mecanico0", "Hugo", "0000", 00};
    Mecanico mecanico1 {"mecanico1", "Paula", "0001", 01};
    Mecanico mecanico2 {"mecanico2", "Jadson", "0002", 02};
    Mecanico mecanico3 {"mecanico3", "Marina", "0003", 03};
    Mecanico mecanico4 {"mecanico4", "Luis", "0005", 04};
    Mecanico mecanico5 {"m", "Manuelito Debug", "1", 05};
    mecanicos.push_back(mecanico0); mecanicos.push_back(mecanico1); mecanicos.push_back(mecanico2); mecanicos.push_back(mecanico3); mecanicos.push_back(mecanico4); mecanicos.push_back(mecanico5);

    vector<Ordem> ordens;
    vector<Servicos> servicos;
    vector<Produtos> produtos;

    Menu(vendedores, mecanicos, super, clientes, ordens);

    return 0;
}

void Menu(vector<Vendedor> &vendedores, vector<Mecanico> &mecanicos, Admin &admin, vector<Cliente> &clientes, vector<Ordem> &ordens){
    int opcao;

    do{
        system("clear");
        cout << "1. Login\n"; 
        cout << "2. Sair do sistema\n";
        cin >> opcao;
        
        if(opcao != 1 && opcao != 2){
            cout << "Escolha uma opcao valida!\n";
        }

    }while(opcao != 1 && opcao != 2);

    if(opcao == 2)
        return;

    login(admin, vendedores, mecanicos, clientes, ordens);
}


void login(Admin super, vector<Vendedor> &vendedores, vector<Mecanico> &mecanicos, vector<Cliente> &clientes, vector<Ordem> &ordens){

    int opcao;
    string nome, senha,usuario;
    vector<User*> users;

    do{
        system("clear");
        cout << "*************\n";
        cout << "1. Administrador\n";
        cout << "2. Vendedor\n";
        cout << "3. Mecanico\n";
        cout << "*************\n";
        cin >> opcao;

        if(opcao != 1 && opcao != 2 && opcao != 3){
            cout << "Escolha uma opcao valida!\n";
            cin >> opcao;
        }
    }while(opcao != 1 && opcao != 2 && opcao != 3);
    cout<<"Usuario: ";
    cin>> usuario;
    cout << "Senha: ";
    cin >> senha;
        
    switch(opcao){  
        case 1: if(super.autenticar(senha)){
                    super.exibirOpcoes(vendedores, mecanicos);
                }else Menu(vendedores, mecanicos, super, clientes, ordens);
                break;
        case 2: 
                for(Vendedor vendedor : vendedores){
                    if(vendedor.getUsuario() == usuario){
                        if(vendedor.autenticar(senha)){
                            vendedor.exibirOpcoes(ordens, clientes);
                        }else{
                            Menu(vendedores, mecanicos, super, clientes, ordens);
                        }
                    }
                }
                break;
        case 3: 
                for(Mecanico mecanico : mecanicos){
                    if(mecanico.getUsuario() == usuario){
                        if(mecanico.autenticar(senha)){
                            mecanico.exibirOpcoes(ordens);
                        }else{
                            Menu(vendedores, mecanicos, super, clientes, ordens);
                        }
                    }
                }
                break;
        default:
                cout << "Error";
    }

    //cout << "Lista de Clientes: " << endl;
    /*for(Cliente cli : clientes){
        cout << cli;
    }*/

    Menu(vendedores, mecanicos, super, clientes, ordens);
}


