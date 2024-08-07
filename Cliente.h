#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente {


    string usuario, senha;

public:

    

    bool autentica(string senha);

    string getUsuario() const;
    
};

#endif