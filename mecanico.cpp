#include "headers/mecanico.h"
#include "headers/valida.h"
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
    int op;
    bool nenhumaOrdem = true,ordemEncontrada;
    string aux;
    while(true){
        cout << "Qual o id da ordem que deseja executar?\n\nOrdens executáveis:" << endl;
        // itera o vetor de ordens, imprimindo todas as que estao com: orcamento realizado, aprovadas pelos clientes e nao executadas
        // veja que nesse caso as ordens com status de manutencao sempre iniciam como aprovadas pelo cliente, pois nao necessitam da aprovacao posterior
        for(Ordem ordem : ordens){
            if(ordem.getOrcamento() && ordem.getAprovada() && ordem.getStatus() != executada)
            {
                cout << ordem.getIdOrdem() << endl;
                nenhumaOrdem = false;
            }
        }

        // nao ha nenhuma ordem a ser executada na lista de ordens executadas, entao encerra a funcao
        if (nenhumaOrdem)
        {
            cout << "Nenhuma ordem a ser executada!" << endl;
            sleep(2);
            system("clear");
            return;
        }

        // le o valor da ordem que deve ser executada
        cin >> aux;
        op = valida(aux);
        ordemEncontrada = false;
        //busca no vetor de ordens a que corresponde à ordem requisitada
        for(Ordem ordem : ordens){
            if(op == ordem.getIdOrdem()){
                if (ordem.getAprovada()) // se a ordem ja foi aprovada, ela eh executada pelo mecanico e o seu status eh atualizado
                {
                    ordem.setStatus(3);
                    cout << "Ordem Executada!" << endl;
                    ordemEncontrada = true;
                }
                else{ // se o usuario tentar executar uma ordem ainda nao aprovada ele eh avisado que ainda deve ser feita a aprovacao
                    cout << "Esta ordem ainda não foi aprovada!" << endl;
                    ordemEncontrada = true;
                }
                break;
            }
        }
        // a ordem nao foi encontrada. Pede um novo ID e tenta novamente
        if (!ordemEncontrada) {
            cout << "Ordem com ID " << op << " não encontrada. Por favor, insira um ID válido." << endl;
        } else {
            break;  // Saia do loop se uma ordem válida foi encontrada e processada
        }
    }
    sleep(2);
    system("clear");
}

void Mecanico::cadastrarServicosPecas(vector<Ordem> &ordens){
    int id;
    string aux;
    bool idValido = false;
    bool nenhumaOrdem = true;
    for(Ordem& ordem : ordens){// Itera sobre o vetor de ordens e imprime cada ordem aberta que ainda nao foi aprovada ou que eh manutencao
        if ( (ordem.getStatus() == orcamento && !ordem.getAprovada()) || ordem.getStatus() == manutencao )
        {
            std::cout << ordem.getIdOrdem() << endl;
            nenhumaOrdem = false;
        }
    } 
    

    // nenhuma ordem aberta para ser mostrada, a funcao eh encerrada
    if(nenhumaOrdem){
        std::cout << "Não há nenhuma ordem aberta" << endl;
        return;
    }
    
    // Solicita ao usuario que escolha uma ordem pelo ID. O programa fica em loop ate que se entre uma ordem valida
    do{
        std::cout << "Escolha o ID de uma ordem: " << endl;
        std::cin >> aux;
        id = valida(aux);
        for(Ordem& ordem : ordens){
            if(id==ordem.getIdOrdem()){
                idValido = true;
                break;
            }
        }
        if(!idValido){
            cout<<"ID invalido! Digite um id valido!\n";
        }
    }while (!idValido);
    
    
    for(Ordem& ordem : ordens){ // Itera novamente sobre as ordens para encontrar a ordem com o ID escolhido.
        if(  ordem.getIdOrdem() == id && ( (ordem.getStatus() == orcamento && !ordem.getAprovada()) || ordem.getStatus() == manutencao )  ) // Verifica se o ID da ordem atual corresponde ao ID escolhido pelo usuario.
        {
            // encontrada a ordem, sao adicionados os servicos e pecas a ela
            ordem.adicionarServico();
            ordem.adicionarPeca();
            ordem.calcularCusto();
            cout << "Peças e serviços cadastrados!" << endl;
            sleep(2);
            system("clear");
        }
    }

}

// menu de opcoes do mecanico. O programa fica em loop ate que seja entrada uma opcao valida. Todas as funcoes chamadas pela exibirOpcoes retornam
// a essa funcao depois que seus fluxos se encerram
void Mecanico::exibirOpcoes(vector<Ordem> &ordens){
    int op = -1;
    string aux;
    system("clear");

    // A frase de boas-vindas eh impressa com o nome do funcionario
    cout << "Olá " << this->getNome() << ", o que deseja realizar?";
    cout << endl << endl;

    cout << "\nDigite a opção que você quer executar: \n1 - Visualizar a ordem\n2 - Cadastrar serviços executados e peças utilizadas\n3 - Executar Ordens\n0 - Sair" << endl;
    cin >> aux;
    
    op = valida(aux);

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
        cin >> aux;
        op = valida(aux);
    }

    // a escolha de op = 0 encerra o fluxo e volta pra funcao anterior (a funcao de login)

}