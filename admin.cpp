#include "headers/admin.h"
#include <iostream>

int valida(string aux){
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

// Construtor da classe Admin, responsavel por inicializar os membros da classe.
Admin::Admin(string usuario, string senha, string nome) : User(usuario, senha, nome){}

// Metodo que permite que Admin edite os os dados de um objeto funcionario
void Admin::editarDadosFuncionario(Funcionario* funcionario){
    int op;
    int id;
    string novo, aux;

    //Comando switch responsavel por determinar qual metodo sera chamado para a edicao do respectivo dado do funcionario
    cout << "Qual dado deseja alterar?" << endl;
    cout << "1 - ID | 2 - Usuario | 3 - Senha | 4 - Nome" << endl;
    cin >> aux;

    op = valida(aux);

    switch(op){
        case 1:
            cout << "Digite o novo ID: " <<  endl;
            cin >> id;
            funcionario->setId(id);
            break;
        case 2:
            cout << "Digite o novo nome de usuário: " <<  endl;
            cin >> novo;
            funcionario->setUsuario(novo);
            break;
        case 3:
            cout << "Digite a nova senha: " << endl;
            cin >> novo;
            funcionario->setSenha(novo);
            break;
        case 4:
            cout << "Digite o novo nome: " << endl;
            cin >> novo;
            funcionario->setNome(novo);
            break;
        default:
            cout << "Operação Inválida";
            break;
    }
    
}

void Admin::exibirOpcoes(vector<User*> users){

    vector<Funcionario*> funcionarios;

    for (User* u : users)
    {
        Funcionario* f = dynamic_cast<Funcionario*> (u);

        if (f != nullptr)
            funcionarios.push_back(f);
    }

    string aux;
    int id;
    bool validacao = false;

    
    
    do {
        cout << "\nOlá ADMIN!\nQual o ID do Funcionario que você quer editar?\n"<<endl;
        for (const Funcionario* funcionario : funcionarios) {
            cout<<"ID:"<< funcionario->getId()<<"| Nome:"<< funcionario->getNome()<<endl;
        }
        cout << "\nOu, digite \"sair\" para deslogar.\n";

        cin >> aux;
        if (aux == "sair" || aux == "s")
            break;
        try
        {
            id = stoi(aux);
        }
        catch(const std::exception& e)
        {
            cout << "ID inválido! Por favor digite um número inteiro\n";
            continue;
        }
        
        /* editar dados de funcionarios */
        for(Funcionario* funcionario : funcionarios){
            if(funcionario->getId() == id){
                editarDadosFuncionario(funcionario);
                validacao = true;
            }
        }
        if(!validacao){
            cout<<"ID errado! Por favor digite o ID certo\n";
        }
    } while(true);
}


// Destrutor da classe Admin. É chamado quando um objeto Admin é destruido.
Admin::~Admin(){}