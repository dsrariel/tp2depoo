#ifndef MOVIMENTACAO_H 
#define MOVIMENTACAO_H

#include <string>
#include <time.h>

class Movimentacao{
    private:
    std::string  dataMovimentacao;
    std::string  descricao;
    char    debitoCredito;
    double  valor;

    public:
    Movimentacao(const std::string descricao, const char debitoCredito, const double valor);

    //Getters
    const std::string getDataMovimentacao();
    const std::string getDescricao();
    const char getDebitoCredito();
    const double getValor();
};
#endif