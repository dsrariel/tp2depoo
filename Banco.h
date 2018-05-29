#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

#include <string>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Cliente.h"
#include "Conta.h"

typedef std::list<Cliente> ListaDeClientes;
typedef std::list<Conta> ListaDeContas;

class Banco{
    private:
    std::string  nomeBanco;
    ListaDeClientes clientes;
    ListaDeContas contas;

    public:
    Banco(const std::string& nomeBanco);

    //Setters
    void setDados();

    //Getters
    const ListaDeClientes getClientes();
    const ListaDeContas getContas();
    void getDados();
    const int getNovoNumeroConta(); //Gera novo número de conta para criação de conta

    //Outros
    bool inserirCliente(const Cliente& cliente); //Retorna True caso cliente não exista (sucesso) e False caso já exista (falha)
    int excluirCliente(const std::string& cpfCnpj); //Retorna 1 caso cliente não possua conta (sucesso), 0 caso possua uma conta e -1 caso não esteja cadastrado(falha)
    void inserirConta(const Cliente& cliente);
    bool excluirConta (int numeroConta); //Retorna True caso conta exista (sucesso) e False caso não exista (falha)
    bool depositar (int numeroConta, double valor); //Retorna True caso conta exista (sucesso) e False caso não exista (falha)
    int sacar (int numeroConta, double valor); //Retorna 1 caso conta exista e tenha saldo suficiente(sucesso),0 caso não tenha o saldo e -1 caso conta não exista (falha)
    bool transferencia (int numeroContaOrigem, int numeroContaDestino, double valor); //Retorna True caso contas existam (sucesso) e False caso não (falha)
    void tarifa();//debita, caso tenha saldo suficiente, 15 reais de cada conta
    void cpmf();
    double saldoConta(int numeroConta); //Retorna -1 caso conta não exista
    const ListaDeMovimentacoes extratoMes(int numeroConta); //Retorna o quê caso a conta não exista?
    const ListaDeMovimentacoes extratoDataInicial(int numeroConta, tm inicio); //Retorna o quê caso a conta não exista?
    const ListaDeMovimentacoes extratoDatas(int numeroConta, tm inicio, tm fim); //Retorna o quê caso a conta não exista?
};

#endif // BANCO_H_INCLUDE
