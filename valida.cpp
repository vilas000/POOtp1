#include "headers/valida.h"


int valida(string aux){
    int opcao;
    try
    {// Tenta converter a string `aux` em um numero inteiro usando `stoi`
        opcao = stoi(aux);
    }
    catch(const std::exception& e)
    { // Se a conversao falhar (por exemplo, se a string contiver letras ou caracteres invalidos stoi lancara uma excecao. Neste caso, a funcao retorna -1 para indicar uma entrada invalida.
        return -1;
    }
    // Se a conversao for bem-sucedida, a funcao retorna o numero convertido
    return opcao;
}