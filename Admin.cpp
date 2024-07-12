#include "Admin.h"

Admin :: Admin(string usuario, string senha) : User(usuario, senha) {
}
Admin :: ~Admin() {}

bool Admin :: editarFunc(Funcionario& funcionario, short operacao, string novo) {
/*  
    OPERAÇÕES SUPORTADAS

    0: Sair
    1: Editar nome
    2: Editar CPF
    3: Editar Salario
    4: Demitir
    5: Recontratar


    Retorna true se a operação foi um sucesso
    Retorna false se não foi possivel realizar a operação
*/

    switch (operacao)
    {
    case 0:
        break;

    case 1:
        // Editar nome
        return funcionario.setNome(novo);

    case 2:
        // Editar cpf
        return funcionario.setCpf(novo);

    case 3:
        // Editar salario
        return funcionario.setSalario(stod(novo));
    
    case 4:
        // Demite funcionario
        return funcionario.demite();

    case 5:
        // Recontrata funcionario
        return funcionario.demite(1);

    default:
        break;
    }

    return true;
}