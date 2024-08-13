#include "headers/mecanico.h"
#include <iostream>

// Construtor da classe Mecanico.
Mecanico::Mecanico(string usuario, string nome, string senha, int id) : Funcionario(id, usuario, senha, nome){// Inicializa um objeto Mecanico com os valores fornecidos para usuario, nome, senha e id.
}
// Destrutor da classe Mecanico.
Mecanico::~Mecanico(){};

// Metodo para visualizar ordens de servico.
void Mecanico::visualizarOrdens(vector<Ordem> &ordens){// Recebe um vetor de objetos Ordem, imprime cada ordem e permite que o usuario escolha uma para editar.
    for(Ordem ordem : ordens){// Itera sobre o vetor de ordens e imprime cada ordem.
        cout << ordem;
    } 
                                  
}

void Mecanico::executarOrdens(vector<Ordem> &ordens){
    cout << "Qual o id da ordem que deseja executar?: " << endl;
    int op;
    for(Ordem ordem : ordens){
        if(ordem.getStatus() == manutencao || (ordem.getStatus() == orcamento && ordem.getAprovada()))
            cout << ordem.getIdOrdem() << endl;
    }
    cin >> op;
    for(Ordem ordem : ordens){
        if(op == ordem.getIdOrdem()){
            ordem.setStatus(3);
            cout << "Ordem Executada!" << endl;
        }
    }
}

void Mecanico::cadastrarServicosPecas(vector<Ordem> &ordens){
    int id;

    for(Ordem& ordem : ordens){// Itera sobre o vetor de ordens e imprime cada ordem.
        cout << ordem.getIdOrdem() << endl;
    } 
    

    // Solicita ao usuario que escolha uma ordem pelo ID.
    
    if(ordens.empty()){
        cout << "Não há ordens cadastradas" << endl;
        return;
    }
    
    cout << "Escolha o ID de uma ordem: " << endl;
    cin >> id;
    for(Ordem& ordem : ordens){ // Itera novamente sobre as ordens para encontrar a ordem com o ID escolhido.
        if(ordem.getIdOrdem() == id){// Verifica se o ID da ordem atual corresponde ao ID escolhido pelo usuario.
            if((ordem.getStatus() == manutencao)){// Se o motivo da ordem for "orcamento" e ela estiver aprovada, ou se o motivo for "manutencao",o mecanico pode adicionar um servico e uma peca à ordem.
                ordem.adicionarServico();
                ordem.adicionarPeca();
            }else if(ordem.getStatus() == orcamento && !ordem.getAprovada()){
                cout << "Gerando Orçamento: " << endl;
                ordem.adicionarServico();
                ordem.adicionarPeca();
                ordem.setOrcamentoTrue();
                ordem.calcularCusto();
                cout << "Valor orcamento: " << ordem.getCusto() << endl;
                cout << "Orçamento gerado? " << ordem.getOrcamento() << endl;
            }
               
               
        }

        cout << "LISTANDO SERVIÇOS" << endl << "---------------------------------" << endl;
        for(Servicos* servico : ordem.getServicos()){
            cout << servico->getDescricao() << " " << servico->getPreco() << endl << endl;
        }

        cout << "LISTANDO PEÇAS" << endl << "---------------------------------" << endl;
        for(Produtos* peca : ordem.getPecas()){
            cout << peca->getDescricao() << " " << peca->getPreco() << endl << endl;
        }

        cout << "FIM DA LISTAGEM" << "----------------------------------------" << endl;
    
    }

}

// Metodo para autenticar um mecanico.
bool Mecanico::autenticar(string senha) const{
    if(this->getSenha() == senha) return true;
    else{
        cout << "Senha incorreta";
    }
    return false;
}

void Mecanico::exibirOpcoes(vector<Ordem> &ordens){
    int op = -1;

    system("clear");

    cout << "Olá " << this->getNome() << ", o que deseja realizar?";
    cout << endl << endl;

    cout << "Digite a opção que você quer executar: \n1 - Visualizar a ordem\n2 - Cadastrar serviços executados e peças utilizadas\n3 - Executar Ordens\n0 - Sair" << endl;
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

