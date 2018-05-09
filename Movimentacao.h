#ifndef MOVIMENTACAO_H 
#define MOVIMENTACAO_H

#include <iostream>
#include <string>
using namespace std;

class Movimentacao{
    private:
    string  dataMovimentacao;
    string  descricao;
    char    debitoCredito;
    double  valor;

    public:
    Movimentacao(const string& descricao, const char& debitoCredito, const double& valor);

    //Getters
    const string& getDataMovimentacao();
    const string& getDescricao();
    const char& getDebitoCredito();
    const double& getValor();
};
#endif