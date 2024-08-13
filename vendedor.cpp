#include "headers/vendedor.h"
#include "headers/cliente.h"

// Construtor da classe Funcionario
Vendedor::Vendedor(int idFuncionario, string usuario, string senha, string nome) : Funcionario(idFuncionario, usuario, senha, nome){}

// Destrutor da classe Funcionario
Vendedor::~Vendedor(){}

// Metodo responsavel por cadastrar um cliente, utilizando seu nome, telefone e cadastrando seu veiculo
bool Vendedor::cadastrarCliente(vector<Cliente> &clientes){
    string nome, telefone;
    cout << "Digite o Nome e o Telefone do cliente: " << endl;
    cin >> nome >> telefone;
    for(Cliente cliente : clientes){
        if(cliente.getNome() == nome) return false;
    }
    cout <<  "Agora, entre com os dados do veículo: Placa | Modelo | Quilometragem" << endl;
    int km;
    string placa, modelo;
    cin >> placa >> modelo >> km;
    Cliente cliente {nome, telefone};
    Veiculo veiculo {placa, modelo, km};
    cliente.setVeiculo(veiculo);
    clientes.push_back(cliente);
    return true;
}

// Metodo responasavel por gerar a ordem de servico, utilizando informacoes do veiculo e quais servicos foram necessarios
Ordem Vendedor::gerarOrdemServico(Cliente & cliente){
    int idOrdem;
    string motivo;
    int status;
    string placa;
    bool encontrado = false;

    vector<Veiculo> veiculos = cliente.getVeiculo();
    Veiculo *veiculoEscolhido = nullptr;
    try {
        veiculoEscolhido = new Veiculo;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Falha na alocação de memória para Veiculo: " << e.what() << std::endl;
    }

    Cliente *pCliente = nullptr;
    try {
        pCliente = new Cliente;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Falha na alocação de memória para Veiculo: " << e.what() << std::endl;
        
    }
    *pCliente = cliente;

    system("clear");

    cout << "Digite o status da Ordem: 1 - Manutenção | 2 - Orçamento " << endl;
    cin >> status;
    cout << "Digite o motivo: ";
    cin >> motivo;

    do{
        cout << "Entre com a placa do veículo que necessita do serviço: " << endl;
        for(Veiculo veiculo : veiculos){
            cout << veiculo.getPlaca() << endl;
        }
        cin >> placa;

        for(Veiculo veiculo : veiculos){
            if(veiculo.getPlaca() == placa){
                *veiculoEscolhido = veiculo;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "Veículo com a placa " << placa << " não encontrado." << endl; 
        }
    }while(!encontrado);
    idOrdem = rand()%100+1;
    Ordem ordem {pCliente, veiculoEscolhido, motivo, status, idOrdem, false, false, 0};
    cout << "Ordem gerada com sucesso!" << endl;
    
    sleep(1);
    system("clear");
    return ordem;
}

// Metodo responsavel por determinar se uma ordem sera aprovada 
void Vendedor::visualizarAprovar(vector<Ordem> &ordens){
    int op;
    system("clear");
    cout << "Ordens pendentes de aprovação" << endl;
    for(Ordem ordem : ordens){
        cout << ordem.getStatus() << endl;
        if(ordem.getStatus() == orcamento && !ordem.getAprovada()){
            cout << ordem;
            if((ordem.getOrcamento()) == true){
                cout << ordem.getCliente()->getNome() << ", gostaria de aprovar o orçamento de R$" << ordem.getCusto() << " do serviço do seu veículo?" << endl;
                cout << "1. Sim" << endl << "2. Não" << endl;
                cin >> op;
                if(op == 1){
                    ordem.setAprovada(true);
                    cout << ordem.getAprovada() << endl; }
                if(op == 2)
                    ordem.setStatus(encerrada);
            ;}
            else{
                cout << "Orçamento ainda não realizado!" << endl;
            }
        }
    }
}

// Metodo responsavel por visualizar ordens ja executadas
void Vendedor::visualizarOrdensExecutadas(vector<Ordem> &ordens){
    system("clear");
    
    for (auto ordens_Iter = ordens.begin(); ordens_Iter != ordens.end(); /* incremento dentro do loop */) {
        cout << ordens_Iter->getStatus() << endl;  // Use a desreferenciação aqui se status for um ponteiro
        
        if (ordens_Iter->getStatus() == executada || ordens_Iter->getStatus() == encerrada) {
            cout << *ordens_Iter << endl;
            ordens_Iter = ordens.erase(ordens_Iter);  // Atualiza o iterador para o próximo elemento após a remoção
        } else {
            ++ordens_Iter;  // Só incrementa se não remover
        }
    }

    sleep(1);
}


// Metodo responsavel por exibir opcoes para os clientes
void Vendedor::exibirOpcoes(vector<Ordem> &ordens, vector<Cliente> &clientes){
    int op = -1;
    string nomeCliente;

    system("clear");

    cout << "Olá " << this->getNome() << ". ";

    cout << "Digite a opção que você quer executar: \n\n1 - Cadastrar cliente e veículo\n2 - Gerar Ordem de Serviço\n3 - Visualizar ordens pendentes de aprovação e contatar o cliente\n4 - Visualizar ordens de serviço executadas e realizar o fechamento\n0 - Sair" << endl;
    cin >> op;

    while(op !=0){
        switch (op)
        {
        case 1:
            cadastrarCliente(clientes);
            break;
        case 2:
            imprimeClientes(clientes);
            cout << "Qual o nome do cliente da nova ordem de serviço? " << endl;
            cin >> nomeCliente;
            for(Cliente cliente : clientes){
                if(cliente.getNome() == nomeCliente){
                    ordens.push_back(gerarOrdemServico(cliente));
                }
            }
            break;
        case 3:
            visualizarAprovar(ordens);
            break;
        
        case 4:
            visualizarOrdensExecutadas(ordens);
            break;
        default:
            cerr << "Erro! Opção Inválida." << endl;
            break;
        }
        cout << "Digite a opção que você quer executar: \n\n1 - Cadastrar cliente e veículo\n2 - Gerar Ordem de Serviço\n3 - Visualizar ordens pendentes de aprovação\n4 - Visualizar ordens de serviço executadas e realizar o fechamento\n0 - Sair" << endl;
        cin >> op;
    };
    return;
}

// Metodo responsavel por realizar a impressao dos nomes dos clientes presentes no vetor
void Vendedor::imprimeClientes(vector<Cliente>& clientes){
    for(Cliente cliente : clientes){
        cout << cliente.getNome() << endl;
    }
}

// Metodo responsavel por verificar se a senha inserida pelo vendedor esta correta
bool Vendedor::autenticar(string senha) const{
    if(this->getSenha() == senha) return true;
    else{
        cout << "Senha incorreta";
    }
    return false;
}