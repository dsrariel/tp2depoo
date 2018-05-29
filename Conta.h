#ifndef CONTA_H 
#define CONTA_H

#include <string>
#include <list>
#include <iterator>
#include "Cliente.h"
#include "Movimentacao.h"

typedef std::list<Movimentacao> ListaDeMovimentacoes;

class Conta{ 
    private:
    int numeroConta;
    static int proximoNumeroConta;
    double saldo;
    Cliente cliente;
    ListaDeMovimentacoes movimentacoes;

    public:
    Conta(const Cliente &cliente);
    Conta(const Cliente &cliente,int numeroConta,int proximoNumeroConta, double saldo, const ListaDeMovimentacoes& movimentacoes);

    //Getters
    const int getNumeroConta();
    const int getProximoNumeroConta();
    const double getSaldo();
    const Cliente getCliente();
    const ListaDeMovimentacoes getMovimentacoes();

    //Outras funções
    bool debitar(const double valor, const std::string descricao); //Retorna 1 em caso de saldo suficiente e 0 caso não.
    void creditar(const double valor, const std::string descricao);
    const ListaDeMovimentacoes extratoDatas(const tm dataInicio, const tm dataFim);
    const ListaDeMovimentacoes extratoDataInicial(const tm dataInicio);
    const ListaDeMovimentacoes extratoMes();
};

//Função que determina se uma data está entre outras duas:
int dataEntreInicioEFim(const tm data, const tm inicio, const tm fim);
void dataMaisDias(tm* data, int dias);

#endif
