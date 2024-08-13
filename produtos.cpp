#include "headers/produtos.h"
#include <iostream>

// Construtor da classe Produtos
Produtos::Produtos(string descricao, float preco) 
:   descricao(descricao), 
    preco(preco) {}

// Destrutor da classe Produtos
Produtos::~Produtos(){}

// Metodo getter que retorna a descricao do determinado produto
string Produtos::getDescricao() const{
    return this->descricao;    
}
// Metodo getter que retorna o valor flutuante de preco do determinado produto 
float Produtos::getPreco() const{
    return this->preco;
}
// Metodo setter que armazena uma descricao para um determinado produto
void Produtos::setDescricao(string descricao){
    this->descricao = descricao;
}
// Metodo setter que armazena uma valor de preco para um determinado produto
void Produtos::setPreco(float preco){
    this->preco = preco;
}