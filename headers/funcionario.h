#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "user.h"
#include <vector>
using namespace std;

class Funcionario : public User
{
    private:
        int idFuncionario;
    public:

        Funcionario(int id, string usuario, string senha, string nome);
        virtual bool autenticar(string senha) const = 0;  // Método virtual puro
        virtual ~Funcionario() = default;  // Destrutor virtual
        void setId(int id);
        int getId() const;              
};

#endif