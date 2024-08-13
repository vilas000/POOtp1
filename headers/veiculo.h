#ifndef ORDEM_HEADER
#define ORDEM_HEADER
#include "ordem.h"
#endif


#ifndef VEICULO_H
#define VEICULO_H


#include <vector>
using namespace std;

class Veiculo
{
    private:
        string placa;
        string modelo;
        int km;
        vector<Ordem> historico;
    public:
        Veiculo(string placa = " ", string modelo = " ", int km = 0);
        ~Veiculo();
        string getPlaca() const;
        string getModelo() const;
        int getKm() const;
        void setKm(int km);

};

#endif