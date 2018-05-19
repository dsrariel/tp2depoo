#ifndef CONTA_H 
#define CONTA_H

#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
#include "Movimentacao.h"

typedef std::vector<Movimentacao> Movimentacoes;

class Conta{
    private:
    int numeroConta;
    int proximoNumeroConta;
    double  saldo;
    Cliente cliente;
    Movimentacoes movimentacoes;

    public:
    Conta(const Cliente& Cliente);

    //Getters
    const int& getNumeroConta();
    const int& getProximoNumeroConta();
    const double& getSaldo();
    const Cliente& getCliente();
    const Movimentacoes& getMovimentacoes();

    //Outras funções
    void debitar(const double& valor, const std::string& descricao);
    void creditar(const double& valor, const std::string& descricao);
    const Movimentacoes& extratoDatas(const time_t& inicio, const time_t& fim);
    const Movimentacoes& extratoMes();
};
#endif