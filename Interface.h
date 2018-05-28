#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "Banco.h"
#include <iostream>

class Interface{
    public:
    int main();
    int menu(std::string nomeBanco); //Retorna opção escolhida
    void inserirCliente(Banco& banco);
    void inserirConta(Banco& banco);
    void excluirCliente(Banco& banco);
    void excluirConta(Banco& banco);
    void depositar(Banco& banco);
    void sacar(Banco& banco);
    void tranferir(Banco& banco);
    void cobrarTarifa(Banco& banco);
    void cobrarCPMF(Banco& banco);
    void saldo(Banco& banco);
    void extrato(Banco& banco);
    void listarClientes(Banco& banco);
    void listarContas(Banco& banco);
};
#endif // BANCO_H_INCLUDE