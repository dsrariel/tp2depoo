#ifndef CONTA_H 
#define CONTA_H

#include <string>
#include <list>
#include "Cliente.h"
#include "Movimentacao.h"

typedef std::list<Movimentacao> ListaDeMovimentacoes;

class Conta{
    private:
    int numeroConta;
    int proximoNumeroConta;
    double  saldo;
    Cliente cliente;
    ListaDeMovimentacoes movimentacoes;

    public:
    Conta(const int& numeroConta, const Cliente& Cliente);

    //Getters
    const int& getNumeroConta();
    const int& getProximoNumeroConta();
    const double& getSaldo();
    const Cliente& getCliente();
    const ListaDeMovimentacoes& getMovimentacoes();

    //Outras funções
    void debitar(const double& valor, const std::string& descricao);
    void creditar(const double& valor, const std::string& descricao);
    const ListaDeMovimentacoes& extratoDatas(const time_t& inicio, const time_t& fim);
    const ListaDeMovimentacoes& extratoMes();
};
#endif