#include "headers/admin.h"
#include <iostream>

// Construtor da classe Admin, responsavel por inicializar os membros da classe.
Admin::Admin(string usuario, string senha, string nome) : User(usuario, senha, nome){}

// Metodo que permite que Admin edite os os dados de um objeto vendedor
void Admin::editarDadosVendedor(Vendedor &vendedor){
    char op;
    int id;
    string novo;

    //Comando switch responsavel por determinar qual metodo sera chamado para a edicao do respectivo dado do vendedor
    cout << "Qual dado deseja alterar?" << endl;
    cout << "1 - ID | 2 - Usuario | 3 - Senha | 4 - Nome" << endl;
    cin >> op;

    switch(op){
    case '1':
        cin >> id;
        vendedor.setId(id);
        break;
    case '2':
        cin >> novo;
        vendedor.setUsuario(novo);
        break;
    case '3':
        cin >> novo;
        vendedor.setSenha(novo);
        break;
    case '4':
        cin >> novo;
        vendedor.setNome(novo);
        break;
    default:
        cout << "Operação Inválida";
        break;
    }
    
}

// Metodo que permite que Admin edite os os dados de um objeto mecanico
void Admin::editarDadosMecanico(Mecanico &mecanico){
    char op;
    int id;
    string novo;

    cout << "Qual dado deseja alterar?" << endl;
    cout << "1 - ID | 2 - Usuario | 3 - Senha | 4 - Nome" << endl;
    cin >> op;

    //Comando switch responsavel por determinar qual metodo sera chamado para a edicao do respectivo dado do mecanico
    switch(op){
    case '1':
        cin >> id;
        mecanico.setId(id);
        break;
    case '2':
        cin >> novo;
        mecanico.setUsuario(novo);
        break;
    case '3':
        cin >> novo;
        mecanico.setSenha(novo);
        break;

    }

}


// Destrutor da classe Admin. É chamado quando um objeto Admin é destruido.
Admin::~Admin(){}

//Verifica se a senha e usuario do Admininstrador no momento do login estao corretas
bool Admin::autenticar(string senha) const{
    if(this->getSenha() == senha)
        return true;
    else if(this->getSenha() != senha){
        cout  << "Senha inválida!" << endl;
        return false; }

    return false;

}

void Admin::exibirOpcoes(vector<Vendedor> &vendedores, vector<Mecanico> &mecanicos){
    int opcao, id;
    bool validacao = false;
    cout << "Olá ADMINISTRADOR, o que deseja realizar?" << endl;

    do{
        cout << "*************\n";
        cout << "1. Editar dados de Vendedores\n";
        cout << "2. Editar dados de Mecanicos\n";
        cout << "*************\n";
        cin >> opcao;

        if (cin.fail()){
            cin.clear(); 
            // cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opcao = -1; 
        }

        if(opcao != 1 && opcao != 2){
            cout << "Escolha uma opcao valida!\n";
        }
    }while(opcao != 1 && opcao != 2);

    switch(opcao){
        case 1:
            /* editar dados de vendedores */
            do{
                cout << "Qual o ID do vendedor que você quer editar?"<<endl;
                for( const Vendedor &vendedor : vendedores){
                    cout<<"ID:"<< vendedor.getId()<<"| NOME:"<< vendedor.getNome()<<endl;
                }
                cin >> id;
                for(Vendedor& vendedor : vendedores){
                    if(vendedor.getId() == id){
                        editarDadosVendedor(vendedor);
                        validacao = true;
                    }
                }
                if(!validacao){
                    cout<<"ID errado! Por favor digite o ID certo\n";
                }
            }while(!validacao);
            break;
        case 2:
            do{
                cout << "\nQual o ID do mecânico que você quer editar?"<<endl;
                for( const Mecanico &mecanico : mecanicos){
                    cout<<"ID:"<< mecanico.getId()<<"| Nome:"<< mecanico.getNome()<<endl;
                }
                cin >> id;
                /* editar dados de mecanicos */
                for(Mecanico mecanico : mecanicos){
                    if(mecanico.getId() == id){
                        editarDadosMecanico(mecanico);
                        validacao = true;
                    }
                }
                if(!validacao){
                    cout<<"ID errado! Por favor digite o ID certo\n";
                }
            }while(!validacao);
            break;
        default:
            //error
            break;
        }
}