#include "headers/mecanico.h"
#include <iostream>

// Construtor da classe Mecanico.
Mecanico::Mecanico(string usuario, string nome, string senha, int id) : Funcionario(id, usuario, senha, nome){// Inicializa um objeto Mecanico com os valores fornecidos para usuario, nome, senha e id.
}
// Destrutor da classe Mecanico.
Mecanico::~Mecanico(){};

// Metodo para visualizar ordens de servico.
void Mecanico::visualizarOrdens(vector<Ordem> &ordens){// Recebe um vetor de objetos Ordem, imprime cada ordem e permite que o usuario escolha uma para editar.
    for(Ordem ordem : ordens){// Itera sobre o vetor de ordens e imprime cada ordem
        cout << ordem;
    } 
                                  
}

void Mecanico::executarOrdens(vector<Ordem> &ordens){
    cout << "Qual o id da ordem que deseja executar?\n\nOrdens executáveis:" << endl;
    int op;
    bool nenhumaOrdem = true;

    for(Ordem ordem : ordens){
        if(ordem.getOrcamento() && ordem.getAprovada() && ordem.getStatus() != executada)
        {
            cout << ordem.getIdOrdem() << endl;
            nenhumaOrdem = false;
        }
    }

    if (nenhumaOrdem)
    {
        cout << "Nenhuma ordem a ser executada." << endl;
        return;
    }

    cin >> op;
    for(Ordem ordem : ordens){
        if(op == ordem.getIdOrdem()){
            if (ordem.getAprovada())
            {
                ordem.setStatus(3);
                cout << "Ordem Executada!" << endl;
            }
            else
                cout << "Esta ordem ainda não foi aprovada!" << endl;
        }
    }
    sleep(2);
    system("clear");
}

void Mecanico::cadastrarServicosPecas(vector<Ordem> &ordens){
    int id;
    bool nenhumaOrdem = true;

    for(Ordem& ordem : ordens){// Itera sobre o vetor de ordens e imprime cada ordem aberta
        if ( (ordem.getStatus() == orcamento && !ordem.getAprovada()) || ordem.getStatus() == manutencao )
        {
            std::cout << ordem.getIdOrdem() << endl;
            nenhumaOrdem = false;
        }
    } 
    

    // Solicita ao usuario que escolha uma ordem pelo ID.
    
    if(nenhumaOrdem){
        std::cout << "Não há nenhuma ordem aberta" << endl;
        return;
    }
    
    std::cout << "Escolha o ID de uma ordem: " << endl;
    std::cin >> id;

    for(Ordem& ordem : ordens){ // Itera novamente sobre as ordens para encontrar a ordem com o ID escolhido.
        if(  ordem.getIdOrdem() == id && ( (ordem.getStatus() == orcamento && !ordem.getAprovada()) || ordem.getStatus() == manutencao )  ) // Verifica se o ID da ordem atual corresponde ao ID escolhido pelo usuario.
        {
            ordem.adicionarServico();
            ordem.adicionarPeca();
            ordem.calcularCusto();
            cout << "Peças e serviços cadastrados!" << endl;
            sleep(2);
            system("clear");
        }
    }

}

void Mecanico::exibirOpcoes(vector<Ordem> &ordens){
    int op = -1;

    system("clear");

    cout << "Olá " << this->getNome() << ", o que deseja realizar?";
    cout << endl << endl;

    cout << "\nDigite a opção que você quer executar: \n1 - Visualizar a ordem\n2 - Cadastrar serviços executados e peças utilizadas\n3 - Executar Ordens\n0 - Sair" << endl;
    cin >> op;
    
    while(op!=0){
        switch (op)
        {
        case 1:
            visualizarOrdens(ordens);
            break;
        case 2:
            cadastrarServicosPecas(ordens);
            break;
        case 3:
            executarOrdens(ordens);
            break;
        default:
            cerr << "Erro! Opção Inválida." << endl;
            break;
        }
        cout << "Digite a opção que você quer executar: \n1 - Visualizar a ordem\n2 - Cadastrar serviços executados e peças utilizadas\n3 - Executar Ordens\n0 - Sair" << endl;
        cin >> op;
    }

}