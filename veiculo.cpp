#include "headers/veiculo.h"
#include <iostream>

// Construtor da classe Veiculo
Veiculo::Veiculo(string placa, string modelo, int km){
    this->placa = placa;
    this->modelo = modelo;
    this->km = km;
}

// Destrutor da classe Veiculo
Veiculo::~Veiculo(){}

// Metodo getter responsavel por retornar a placa do veiculo
string Veiculo::getPlaca() const{
    return this->placa;
}

// Metodo getter responsavel por retornar o modelo do veiculo
string Veiculo::getModelo() const{
    return this->modelo;
}

// Metodo getter responsavel por retornar a quilometragem do veiculo
int Veiculo::getKm() const{
    return this->km;
}

// Metodo setter responsavel por armazenar um valor de quilometragem para o veiculo
void Veiculo::setKm(int km){
    this->km = km;
}