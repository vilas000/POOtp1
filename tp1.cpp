#include <iostream>
#include <string>
#include <limits>

using namespace std;

void login();
void administradorLogin(const string &nome, const string &senha);
void vendedorLogin(const string &nome, const string &senha);
void mecanicoLogin(const string &nome, const string &senha);
void cadastroCliente();

/* SISTEMA DE GERENCIAMENTO DE 
- SERVICOS 
- VENDAS DE PECAS EM UMA OFICINA MECANICA

TEMOS
- FUNCIONARIOS (vendedores ou mecanicos)
- CLIENTES
- VEICULOS DOS CLIENTES
- ITENS DE SERVICO E PRODUTOS DE VENDA

SERA GERADA UMA ORDEM DE SERVICO QUE DEVE APRESENTAR:
- MOTIVO DA MANUTENCAO
- OUTRAS INFORMACOES DO VEICULO
- O SISTEMA DEVERA ESTAR APTO A GERAR TODO O HISTORICO DE 
MANUTENCOES DO VEICULO
*/
class Funcionario{
    protected:
        string nome;
        string senha;
    public:
        Funcionario(string nome, string senha) : nome(nome), senha(senha) {}

        void setNome(const string &nome) {
            this->nome = nome;
        }

        void setSenha(const string &senha) {
            this->senha = senha;
        }

        string getNome() const {
            return nome;
        }

        string getSenha() const {
            return senha;
        }
            
        void display() const {
            cout << "Nome: " << nome << ", Senha: " << senha << endl;
        }
};

class Administrador : public Funcionario{
    public:
        Administrador(string nome, string senha) : Funcionario(nome, senha) {}

        void editarMecanico(Mecanico mecanico){
            char opcao;
            string tempNome = mecanico.getNome();
            string tempSenha = mecanico.getSenha();

            cout << "Deseja alterar o nome do mecanico " << tempNome << "?" << endl;

            do{
                cout << "1. Sim\n";
                cout << "2. Nao\n";
                cin >> opcao;

                if (cin.fail()){
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    opcao = -1; 
                }

                if(opcao != 1 && opcao != 2){
                    cout << "Escolha uma opcao valida!\n";
                }
            }while(opcao != 1 && opcao != 2);

            if(opcao == 1){
                string novoNome;
                cout << "Insira o novo nome desejado: ";
                cin >> novoNome;
                mecanico.setNome(novoNome);
            }

            cout << "Deseja alterar a senha do mecanico " << tempNome << "?" << endl;

            do{
                cout << "1. Sim\n";
                cout << "2. Nao\n";
                cin >> opcao;

                if (cin.fail()){
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    opcao = -1; 
                }

                if(opcao != 1 && opcao != 2){
                    cout << "Escolha uma opcao valida!\n";
                }
            }while(opcao != 1 && opcao != 2);

            if(opcao == 1){
                string novaSenha;
                cout << "Insira a nova senha desejada: ";
                cin >> novaSenha;
                mecanico.setSenha(novaSenha);
            }

        }    

        void editarVendedor(Vendedor vendedor){
            char opcao;
            string tempNome = vendedor.getNome();
            string tempSenha = vendedor.getSenha();

            cout << "Deseja alterar o nome do vendedor " << tempNome << "?" << endl;

            do{
                cout << "1. Sim\n";
                cout << "2. Nao\n";
                cin >> opcao;

                if (cin.fail()){
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    opcao = -1; 
                }

                if(opcao != 1 && opcao != 2){
                    cout << "Escolha uma opcao valida!\n";
                }
            }while(opcao != 1 && opcao != 2);

            if(opcao == 1){
                string novoNome;
                cout << "Insira o novo nome desejado: ";
                cin >> novoNome;
                vendedor.setNome(novoNome);
            }

            cout << "Deseja alterar a senha do vendedor " << tempNome << "?" << endl;

            do{
                cout << "1. Sim\n";
                cout << "2. Nao\n";
                cin >> opcao;

                if (cin.fail()){
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    opcao = -1; 
                }

                if(opcao != 1 && opcao != 2){
                    cout << "Escolha uma opcao valida!\n";
                }
            }while(opcao != 1 && opcao != 2);

            if(opcao == 1){
                string novaSenha;
                cout << "Insira a nova senha desejada: ";
                cin >> novaSenha;
                vendedor.setSenha(novaSenha);
            }
        }
};

class Mecanico : public Funcionario{
    public:
        Mecanico(string nome, string senha) : Funcionario(nome, senha) {}
        
};

class Vendedor : public Funcionario{
    public:
        Vendedor(string nome, string senha) : Funcionario(nome, senha) {}

        void cadastroCliente(){
                            
        }
};

class Cliente{
    public:
        string nome;

        class Veiculo{
            public:
                float quilometragem;
                string modelo;
                int ano;
        };
};

int main(){

    int opcao;

    do{
        cout << "1. Login\n"; 
        cout << "2. Sair do sistema\n";
        cin >> opcao;

        if (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opcao = -1; 
        }

        if(opcao != 1 && opcao != 2){
            cout << "Escolha uma opcao valida!\n";
        }
    }while(opcao != 1 && opcao != 2);

    if(opcao == 2)
        return 0;

    login();

    return 0;
}

void login(){

    int opcao;
    string nome, senha;

    do{
        cout << "*************\n";
        cout << "1. Administrador\n";
        cout << "2. Vendedor\n";
        cout << "3. Mecanico\n";
        cout << "*************\n";
        cin >> opcao;

        if (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opcao = -1; 
        }

        if(opcao != 1 && opcao != 2 && opcao != 3){
            cout << "Escolha uma opcao valida!\n";
        }
    }while(opcao != 1 && opcao != 2 && opcao != 3);

    cout << "Nome: ";
    cin >> nome; 
    cout << "Senha: ";
    cin >> senha;

    switch(opcao){
        case 1: 
                administradorLogin(nome, senha);
                break;
        case 2: 
                vendedorLogin(nome, senha);
                break;
        case 3: 
                mecanicoLogin(nome, senha);
                break;
        default:
                cout << "Error";
    }
}

void administradorLogin(const string &nome, const string &senha){

    //testes
    Vendedor vendedor1("Vilas", "senha123");
    Vendedor vendedor2("Thiago", "senha123");
    Vendedor vendedor3("Yasmin", "senha123");
    Mecanico mecanico1("Yann", "senha123");
    Mecanico mecanico2("Marcelo", "senha123");

    Administrador administrador(nome, senha);

    int opcao;

    do{
        cout << "*************\n";
        cout << "1. Editar dados de Vendedores\n";
        cout << "2. Editar dados de Mecanicos\n";
        cout << "*************\n";
        cin >> opcao;

        if (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opcao = -1; 
        }

        if(opcao != 1 && opcao != 2){
            cout << "Escolha uma opcao valida!\n";
        }
    }while(opcao != 1 && opcao != 2);

    switch(opcao){
        case 1:
            /* editar dados de vendedores */
            administrador.editarVendedor(vendedor1);
            break;
        case 2:
            /* editar dados de mecanicos */
            administrador.editarMecanico(mecanico1);
            break;
        default:
            //error
            break;
        }
}  

void vendedorLogin(const string &nome, const string &senha){
    Vendedor vendedor(nome, senha);
    int opcao;

    do{
        cout << "*************\n";
        cout << "1. Cadastrar cliente e veículo\n";
        cout << "2. Gerar ordem de serviço\n";
        cout << "3. Visualizar ordens de serviço de orçamento pendentes de aprovação do cliente e marcar como aprovadas\n";
        cout << "4. Visualizar ordens de serviço executadas e realizar o fechamento\n";
        cout << "*************\n";
        cin >> opcao;

        if (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opcao = -1; 
        }

        if(opcao < 1 || opcao > 4){
            cout << "Escolha uma opcao valida!\n";
        }
    }while(opcao != 1 && opcao != 2 && opcao != 3);

    switch(opcao){
        case 1:
            /* Cadastrar cliente e veículo */
            vendedor.cadastroCliente();
            break;
        case 2:
            /*  */
            break;
        case 3:
            /*  */
            break;
        case 4:
            /*  */
            break;
        default:
            //error
            break;
        }
}

void mecanicoLogin(const string &nome, const string &senha){
    Mecanico mecanico(nome, senha);
    int opcao;

    do{
        cout << "*************\n";
        cout << "1. Visualizar ordens de serviço abertas\n";
        cout << "2. Cadastrar serviços executados e peças utilizadas\n";
        cout << "*************\n";
        cin >> opcao;

        if (cin.fail()){
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opcao = -1; 
        }

        if(opcao != 1 && opcao != 2){
            cout << "Escolha uma opcao valida!\n";
        }
    }while(opcao != 1 && opcao != 2);

    switch(opcao){
        case 1:
            /* Visualizar ordens de serviço abertas */
            impressaoOrdensServico(/*incluir vetor com servicos*/); 
            break;
        case 2:
            /* Cadastrar serviços executados e peças utilizadas */
            cadastroOrdensServico(/*incluir vetor com servicos*/);
            break;
        default:
            //error
            break;
        }
}