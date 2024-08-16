#ifndef USER_H
#define USER_H

using namespace std;
#include <iostream>
#include <vector>

class Vendedor;
class Mecanico;
class Ordem;
class Cliente;

class User
{
    private:
        string usuario;
        string senha;
        string nome;

    public:
        User(string usuario = "usuario", string senha = "1234", string nome = "");
        virtual ~User() = default;  // Destrutor virtual

        void setUsuario(string usuario);
        void setSenha(string senha);
        void setNome(string nome); 
        bool autenticar(string usuario, string senha);

        string getUsuario() const;
        string getNome() const;
};

#endif