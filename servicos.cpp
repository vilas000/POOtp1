#include "headers/servicos.h"
#include <iostream>

// Construtor da classe Ordem, responsavel por inicializar os membros da Servicos
Servicos::Servicos(string descricao, float preco) 
:   descricao(descricao), 
    preco(preco) {}

// Destrutor da classe Servicos
Servicos::~Servicos(){
}

// Metodo getter que retorna a descricao de um determinado servico
string Servicos::getDescricao() const {
    return this->descricao;
}

// Metodo getter que retorna um valor flutuante correspondente ao preco de um determinado servico
float Servicos::getPreco() const {
    return this->preco;
}

// Metodo setter que armazena uma descricao para um determinado servico
void Servicos::setDescricao(string descricao) {
    this->descricao = descricao;
}

// Metodo setter que armazena um valor flutuante correspondente ao preco de um determinado servico
void Servicos::setPreco(float preco) {
    this->preco = preco;
}