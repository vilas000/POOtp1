#include "headers/cliente.h"
#include "headers/veiculo.h"
#include "headers/ordem.h"

// Construtor da classe Ordem, responsavel por inicializar os membros da Ordem.
// Ordem::Ordem(Cliente *cliente_, Veiculo *veiculo_, string motivo, int status, int idOrdem, bool aprovada, bool orcamentoGerado)
// : cliente(cliente_), veiculo(veiculo_), motivo(motivo), status(status), idOrdem(idOrdem), aprovada(aprovada), orcamentoGerado(orcamentoGerado) {}

// Ordem::Ordem(Cliente *cliente_, Veiculo *veiculo_, string motivo, int status, int idOrdem, bool aprovada, bool orcamentoGerado)
// : cliente(cliente_), veiculo(veiculo_), motivo(motivo), status(status), idOrdem(idOrdem), aprovada(aprovada), orcamentoGerado(orcamentoGerado) {}

Ordem::Ordem(Cliente *cliente_, Veiculo *veiculo_, string motivo, int status, int idOrdem, bool aprovada, bool orcamentoGerado, float custo)
:   cliente(new Cliente (*cliente_)), 
    veiculo(new Veiculo (*veiculo_)), 
    motivo(motivo), 
    status(new int(status)), 
    idOrdem(idOrdem), 
    aprovada(new bool (aprovada)), 
    orcamentoGerado(orcamentoGerado),
    custoTotal(custo) {}

Ordem::Ordem(const Ordem& outro)
:   cliente(new Cliente (*outro.cliente)), 
    veiculo(new Veiculo (*outro.veiculo)), 
    motivo(outro.motivo), 
    status(outro.status), 
    idOrdem(outro.idOrdem), 
    aprovada(outro.aprovada), 
    orcamentoGerado(outro.orcamentoGerado),
    custoTotal(outro.custoTotal){} 

// Destrutor da classe Ordem
Ordem::~Ordem(){
    delete(cliente);
    delete(veiculo);
    for(Servicos* servico : servicos){
        delete(servico);
    }
    for(Produtos* produto : pecas){
        delete(produto);
    }
}

// Metodo responsavel por calcular e retornar o custo total de determinada ordem. Sendo a soma do valor de servico com o valor das pecas
void Ordem::calcularCusto(){
    custoTotal = 0;
    
    cout << endl << "Calculando custos dos seguintes serviços e peças: " << endl;

    cout << custoTotal << endl;

    if(servicos.empty()){
        cout << "SERVICOS VAZIO";
    }
    if(pecas.empty()){
        cout << "PECAS VAZIO";
    }

    for(Servicos* servico : servicos){
        cout << servico->getDescricao() << " R$: "<< servico->getPreco() << endl;
        custoTotal += static_cast<float>(servico->getPreco());
    }

    for(Produtos* peca : pecas){
        cout << peca->getDescricao() << peca->getPreco() << endl;
        custoTotal += static_cast<float>(peca->getPreco());
    }
    
    cout << "Custo custoTotal" << endl;
    cout << custoTotal << endl;

}

// Metodo responsavel por adicionar um novo servico a ser realizado, utilizando a descricao do servico e o seu preco
void Ordem::adicionarServico(){
    int op = 1;

    cout << "Deseja adicionar algum serviço?\n1 - Sim\n2- Não" << endl;
    cin >> op;

    if(op == 2) return; 

    string descricao;
    float preco;
    cout << "Qual o serviço a ser realizado? ";
    cin >> descricao;
    cout << "Informe o valor do serviço: ";
    cin >> preco;

    Servicos* novoServico = new Servicos{descricao, preco};
    this->servicos.push_back(novoServico);
}

// Metodo responsavel por adicionar uma nova peca a ser utilizada e comprada, utilizando a descricao do servico e o seu preco
void Ordem::adicionarPeca(){
    int op = 1;

    cout << "Deseja adicionar alguma peça?\n1 - Sim\n2 - Não" << endl;
    cin >> op;

    if(op == 2) return; 

    string descricao;
    float preco;
    cout << "Qual a peça a ser utilizada? ";
    cin >> descricao;
    cout << "Informe o valor da peça: ";
    cin >> preco;
    
    Produtos* novaPeca = new Produtos{descricao, preco};
    this->pecas.push_back(novaPeca);
}

// Metodo setter que armazena um valor booleano que determina se o servico foi aprovado ou nao
void Ordem::setAprovada(bool decisao){
    *aprovada = decisao;
}

// Metodo responsavel por declarar um servico como encerrado
void Ordem::encerrarOrdem(){
    *status = encerrada;
}

// Metodo getter que retorna um valor inteiro correspondente ao ID da determinada ordem
int Ordem::getIdOrdem() const{
    return this->idOrdem;
}

// Metodo getter que retorna o um valor booleano que determina se o servico foi aprovado ou nao
bool Ordem::getAprovada() const{
    return *aprovada;
}

// Metodo getter que retorna o um valor inteiro que determina o status do servico, declarado numa estrutura enumerada
int Ordem::getStatus() const{
    return *status;
}

bool Ordem::getOrcamento() const{
    return orcamentoGerado;
}

const vector<Servicos*>& Ordem::getServicos() const{
    return servicos;
}

const vector<Produtos*>& Ordem::getPecas() const{
    return pecas;
}

Cliente* Ordem::getCliente() const{
    return cliente;
}

// Metodo setter responsavel por armazenar um valor de status do servico
void Ordem::setStatus(int stat){
    *status = stat;
}

void Ordem::setOrcamentoTrue(){
    orcamentoGerado = true;
}

Veiculo* Ordem::getVeiculo() const{
    return this->veiculo;
}

ostream& operator<<(ostream& out, const Ordem& ordem) {
    out << "ID da ordem: " << ordem.idOrdem << endl;
    out << "Motivo: " << ordem.motivo << endl;
    out << boolalpha << "Valor Orçamento: " << ordem.getOrcamento() << endl;
      
    if (ordem.getCliente() && ordem.getVeiculo()) {  // Verifique se os ponteiros não são nulos
        out << "Nome do cliente: " << ordem.getCliente()->getNome() << endl;
        out << "Modelo do veículo: " << ordem.getVeiculo()->getModelo() << endl;
    } else {
        out << "Cliente ou veículo não disponíveis." << endl;
    }

    out << boolalpha << "Aprovada: " << ordem.getAprovada() << endl;
    
    out << "--------------------------------------------" << endl;

    return out;
}


string Ordem::getMotivo() const{
    return motivo;
}

float Ordem::getCusto() const{
    return custoTotal;
}