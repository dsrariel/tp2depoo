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
    static int proximoNumeroConta;
    double saldo;
    Cliente cliente;
    ListaDeMovimentacoes movimentacoes;

    public:
    Conta(const Cliente &cliente);

    //Getters
    const int getNumeroConta();
    const int getProximoNumeroConta();
    const double getSaldo();
    const Cliente getCliente();
    const ListaDeMovimentacoes getMovimentacoes();

    //Outras funções
    void debitar(const double valor, const std::string descricao);
    void creditar(const double valor, const std::string descricao);
    const ListaDeMovimentacoes extratoDatas(const std::string inicio, const std::string fim);
    const ListaDeMovimentacoes extratoMes();
};

//Função que determina se uma data está entre outras duas:
int dataEntreInicioEFim(const std::string data, const std::string inicio, const std::string fim);

#endif