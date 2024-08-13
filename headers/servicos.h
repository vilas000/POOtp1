#ifndef SERVICOS_H
#define SERVICOS_H

#include <string>
#include <iostream> 
#include <vector>
using namespace std;

class Servicos{
    private:
        string descricao;
        float preco;
    public:
        Servicos(string descricao, float preco);
        ~Servicos();
        string getDescricao() const;
        float getPreco() const;
        void setDescricao(string descricao);
        void setPreco(float preco);
};

#endif