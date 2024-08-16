#include "headers/menu.h"

Menu::Menu() {
    // Constrói o Menu já populando os vetores dinamicamente

    users.push_back(new Admin("super", "2024", ""));
    users.push_back(new Vendedor(01, "vendedor1", "0001", "Fernando"));
    users.push_back(new Vendedor(02, "vendedor2", "0002", "Bruna"));
    users.push_back(new Vendedor(03, "vendedor3", "0003", "Marcelo"));
    users.push_back(new Vendedor(04, "vendedor4", "0004", "Nicole"));
    users.push_back(new Vendedor(05, "vendedor5", "0005", "Carlos"));
    users.push_back(new Vendedor(00, "v", "1", "Manuel Debug"));
    users.push_back(new Mecanico("mecanico1", "Hugo", "0011", 11));
    users.push_back(new Mecanico("mecanico2", "Paula", "0012", 12));
    users.push_back(new Mecanico("mecanico3", "Jadson", "0013", 13));
    users.push_back(new Mecanico("mecanico4", "Marina", "0014", 14));
    users.push_back(new Mecanico("mecanico5", "Luis", "0015", 15));
    users.push_back(new Mecanico("m", "Manuelito Debug", "1", 10));

    clientes.push_back({"Roberto", "3434", 143, "fox", "AB88"});
    clientes.push_back({"Sabrina", "2030", 2856, "celta", "NK20"});
    clientes.push_back({"Marcia", "1978", 9865, "corsa", "AT67"});
    clientes.push_back({"Claudio", "8742", 0, "creta", "HJ54"});
    clientes.push_back({"Medusa", "1111", 111, "ranger", "Z3US"});
}

Menu::~Menu() {
    for (User* u : users)
        delete u;
}

string Menu::login () {
    string senha, usuario;
    
    cout << "\nUsuario: ";
    cin>> usuario;
    cout << "Senha: ";
    cin >> senha;

    for (User* user : users)
        if (user->autenticar(usuario, senha)) {
            return exibirOpcoes(user);
        }

    return "Credenciais invalidas\n";
}

string Menu::exibirOpcoes(User* u) {
    Admin* a; Vendedor* v; Mecanico* m;

    a = dynamic_cast<Admin*> (u);
    v = dynamic_cast<Vendedor*> (u);
    m = dynamic_cast<Mecanico*> (u);

    if (a != nullptr)
        a->exibirOpcoes(users);
    else if (v != nullptr)
        v->exibirOpcoes(ordens, clientes);
    else if (m != nullptr)
        m->exibirOpcoes(ordens);
    else
        return "Erro de downcasting\n";

    return "";
        
}