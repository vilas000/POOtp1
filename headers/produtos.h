#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <iostream>
#include <vector>
using namespace std;

class Produtos{
    private:
        string descricao;
        float preco;
    public:
        Produtos(string descricao, float preco);
        ~Produtos();
        string getDescricao() const;
        float getPreco() const;
        void setDescricao(string descricao);
        void setPreco(float preco);
};

#endif