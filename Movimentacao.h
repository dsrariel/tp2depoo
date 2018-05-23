#ifndef MOVIMENTACAO_H 
#define MOVIMENTACAO_H

#include <string>
#include <time.h>

class Movimentacao{
    private:
    tm dataMovimentacao;
    std::string  descricao;
    char    debitoCredito;
    double  valor;

    public:
    Movimentacao(const std::string descricao, const char debitoCredito, const double valor);

    //Getters
    const tm getDataMovimentacao();
    const std::string getDescricao();
    const char getDebitoCredito();
    const double getValor();
};
#endif