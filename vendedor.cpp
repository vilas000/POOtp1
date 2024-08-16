#include "headers/vendedor.h"
#include "headers/cliente.h"
#include "headers/valida.h"
// Construtor da classe Funcionario
Vendedor::Vendedor(int idFuncionario, string usuario, string senha, string nome) : Funcionario(idFuncionario, usuario, senha, nome){}

// Destrutor da classe Funcionario
Vendedor::~Vendedor(){}


// Metodo responsavel por cadastrar um cliente, utilizando seu nome, telefone e cadastrando seu veiculo
bool Vendedor::cadastrarCliente(vector<Cliente> &clientes){
    string nome, telefone;
    cout << "Digite o Nome e o Telefone do cliente: " << endl;
    // pega o nome e o telefone do cliente
    cin >> nome >> telefone;

    // verifica se o cliente ja nao esta cadastrado
    for(Cliente cliente : clientes){
        if(cliente.getNome() == nome){
            cout << "Cliente já cadastrado!" << endl;
            sleep(2);
            return false;
        }
    }
    //Le os dados do veiculo do cliente
    cout <<  "Agora, entre com os dados do veículo: Placa | Modelo | Quilometragem" << endl;
    int km;
    string placa, modelo;
    cin >> placa >> modelo >> km;
    // sao declarados os objetos cliente e veiculo. O veiculo eh adicionado ao cliente, e o cliente eh adicionado ao vetor de clientes
    Cliente cliente {nome, telefone};
    Veiculo veiculo {placa, modelo, km};
    cliente.setVeiculo(veiculo);
    clientes.push_back(cliente);
    cout << "Cliente cadastrado!" << endl;
    sleep(1);
    return true;
}

// Metodo responasavel por gerar a ordem de servico, utilizando informacoes do veiculo e quais servicos foram necessarios
Ordem Vendedor::gerarOrdemServico(Cliente & cliente){
    int idOrdem;
    string motivo,aux;
    int status;
    string placa;
    bool encontrado = false;

    // eh buscado o vetor de veiculos do clientee
    vector<Veiculo> veiculos = cliente.getVeiculo();
    // ponteiro auxiliar para veiculo
    Veiculo *veiculoEscolhido = nullptr;
    try {
        veiculoEscolhido = new Veiculo;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Falha na alocação de memória para Veiculo: " << e.what() << std::endl;
    }

    Cliente *pCliente = nullptr; // ponteiro auxiliar para cliente
    try {
        pCliente = new Cliente;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Falha na alocação de memória para Cliente: " << e.what() << std::endl;
        
    }
    *pCliente = cliente; 

    system("clear");

    // define o status da ordem (manutencao ou orcamento)
    do{
        cout << "Digite o status da Ordem: 1 - Manutenção | 2 - Orçamento " << endl;
        cin >> aux;
        status = valida(aux);
        if((status != 1) && (status != 2)){
            cout << "Opção invalida! Digita uma opção valida\n";
        }
    }while((status != 1) && (status != 2));

    // define o motivo da abertura da ordem
    cout << "Digite o motivo: ";
    cin >> motivo;

    // itera pelas placas registradas para o cliente ate que o usuario entre uma valida
    do{
        cout << "Entre com a placa do veículo que necessita do serviço: " << endl;
        for(Veiculo veiculo : veiculos){
            cout << veiculo.getPlaca() << endl;
        }
        cin >> placa;

        for(Veiculo veiculo : veiculos){
            if(veiculo.getPlaca() == placa){
                *veiculoEscolhido = veiculo; //atribui ao ponteiro auxiliar o veiculo escolhido
                encontrado = true;
            }
        }
        if (!encontrado) { //se a placa entrada nao for valida, fica em loop ate que se entre uma placa valida
            cout << "Veículo com a placa " << placa << " não encontrado." << endl; 
        }
    }while(!encontrado);
    
    //o id gerado para a nova ordem eh aleatorio. Por motivos de praticidade para testagem nossa e do professor, nao inicializamos o rand com uma seed 
    idOrdem = rand()%100+1; 
    // um novo objeto ordem eh gerado
    Ordem ordem {pCliente, veiculoEscolhido, motivo, status, idOrdem, (status == 1)? true : false, false, 0};
    // Obs.: se status for de manutenção e não de orçamento, logo a ordem nao precisa de passar por aprovação do cliente
    cout << "Ordem gerada com sucesso!" << endl;
    
    sleep(1);
    system("clear");
    return ordem;
}


// Metodo responsavel por determinar se uma ordem sera aprovada 
void Vendedor::visualizarAprovar(vector<Ordem> &ordens){
    int op, id;
    bool nenhumaOrdem = true, idInvalido;

    system("clear");

    // sao listadas as ordens que sejam orcamento e que ainda nao foram aprovadas
    for(Ordem ordem : ordens){
        // cout << ordem.getStatus() << endl;
        if(ordem.getStatus() == orcamento && !ordem.getAprovada()){
            cout << ordem;
            nenhumaOrdem = false;
        }
        
    }

    // nao ha nenhuma ordem para ser aprovada
    if (nenhumaOrdem){
        cout << "Não há nenhuma ordem pendente de aprovação." << endl;
    }
    else
    {
        cout << "\nEscolha uma ordem para a aprovação do cliente.\nID: ";
        cin >> id;

        for (Ordem ordem : ordens) 
        {   // verifica se a ordem eh do tipo orcamento, nao aprovada e com orcamento ja gerado
            if ((ordem.getStatus() == orcamento && !ordem.getAprovada() && ordem.getOrcamento()) && (id == ordem.getIdOrdem()))
            {
                idInvalido = false;
                // contacta o cliente para pergunta se ele aprova o orcamento
                cout << ordem.getCliente()->getNome() << ", gostaria de aprovar o orçamento de R$" << ordem.getCusto() << " do serviço do seu veículo?" << endl;
                cout << "1. Sim" << endl << "2. Não" << endl;
                cin >> op;
                // o cliente aprova o orcamento, sua flag de aprovada eh ativada
                if(op == 1)
                {
                    ordem.setAprovada(true);
                    cout << "Ordem aprovada" << endl;
                }
                // o cliente nao aprova o orcamento. A ordem recebe o status de encerrada
                if(op == 2)
                    ordem.setStatus(encerrada);
            }
            else if((ordem.getStatus() == orcamento && !ordem.getAprovada() && !ordem.getOrcamento()) && (id == ordem.getIdOrdem()))
                cout << "Orçamento dessa ordem não gerado. Contate um mecânico." << endl;
            
        }

        // o ID fornecido nao eh valido para nenhuma ordem pendente de aprovacao
        if(idInvalido)
            cout << "O ID fornecido não corresponde a uma ordem pendente de aprovação do cliente." << endl;
    }

    sleep(2);
    system("clear");
}

// Metodo responsavel por visualizar ordens ja executadas
void Vendedor::visualizarOrdensExecutadas(vector<Ordem> &ordens){
    bool nenhumaOrdem = true, idValido;
    int id;
    string aux2;
    vector<Ordem> aux; // Vetor auxiliar que armazena as ordens válidas para fechamento

    system("clear");

    do{
        for (Ordem ordem : ordens)
        {   // verifica se existem ordens executadas para serem mostradas
            if (ordem.getStatus() == executada) {
                nenhumaOrdem = false;
                aux.push_back(ordem);
                cout << ordem << endl;
            }
        }

        if (nenhumaOrdem){
            cout << "Nenhuma ordem a ser exibida" << endl;
            return;
        }
        else
        {
            cout << "Informe o ID da ordem que foi fechada (devidamente entregue e paga): ";
            cin >> aux2;
            id = valida(aux2);

            idValido = false;

            for (Ordem ordem : aux)
            {
                if (ordem.getIdOrdem() == id)
                {
                    // o status da ordem eh atualizado para encerrada e ela não aparece mais nas listagens
                    ordem.setStatus(encerrada);
                    cout << "Ordem encerrada" <<  endl;
                    idValido = true;
                    break;
                }
            }
        }
        // o ID inserido eh invalido. O codigo permanece em loop ate a entrada de um ID valido
        if (!idValido) {
            system("clear");
            cout << "ID inválido. Tente novamente." << endl;
        }  
    }while(!idValido);
    sleep(1);
    system("clear");
}

// Metodo responsavel por exibir opcoes do vendedor para os clientes
void Vendedor::exibirOpcoes(vector<Ordem> &ordens, vector<Cliente> &clientes){
    int op = -1;
    string nomeCliente,aux;
    bool nomeValido;


    system("clear");

    //cout << "Olá " << this->getNome() << ". ";

    cout << "Digite a opção que você quer executar: \n\n1 - Cadastrar cliente e veículo\n2 - Gerar Ordem de Serviço\n3 - Visualizar ordens pendentes de aprovação e contatar o cliente\n4 - Visualizar ordens de serviço executadas e realizar o fechamento\n0 - Sair" << endl;
    cin >> aux;
    
    op = valida(aux);
    while(op !=0){
        nomeValido = false;
        switch (op)
        {
        case 1:
            cadastrarCliente(clientes);
            break;
        case 2:
            do{
                imprimeClientes(clientes);
                cout << "Qual o nome do cliente da nova ordem de serviço? " << endl;
                cin >> nomeCliente;
                for(Cliente cliente : clientes){
                    if(cliente.getNome() == nomeCliente){
                        ordens.push_back(gerarOrdemServico(cliente));
                        nomeValido = true;
                    }
                }
                if(!nomeValido){
                    cout<< "Nome não identificado!\n";
                }
            }while(!nomeValido);
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
        cout << "\nDigite a opção que você quer executar: \n\n1 - Cadastrar cliente e veículo\n2 - Gerar Ordem de Serviço\n3 - Visualizar ordens pendentes de aprovação e contatar o cliente\n4 - Visualizar ordens de serviço executadas e realizar o fechamento\n0 - Sair" << endl;
        cin >> aux;
        op = valida(aux);

    };
    return;
}

// Metodo responsavel por realizar a impressao dos nomes dos clientes presentes no vetor
void Vendedor::imprimeClientes(vector<Cliente>& clientes){
    for(Cliente cliente : clientes){
        cout << cliente.getNome() << endl;
    }
}

