#ifndef USER_H
#define USER_H

using namespace std;
#include <iostream>
#include <vector>

class User
{
    private:
        string usuario;
        string senha;
        string nome;
    public:
        User(string usuario = "usuario", string senha = "1234", string nome = " ");
        string getUsuario() const;
        string getSenha() const;
        string getNome() const;
        void setUsuario(string usuario);
        void setSenha(string senha);
        void setNome(string nome); 
        virtual bool autenticar(string senha) const = 0;  // Método virtual puro
        virtual ~User() = default;  // Destrutor virtual
};

#endif