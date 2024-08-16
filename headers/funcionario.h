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
        virtual ~Funcionario() = default;  // Destrutor virtual
        bool setId(string id);
        void setId(int id);
        int getId() const;    
                

};

#endif