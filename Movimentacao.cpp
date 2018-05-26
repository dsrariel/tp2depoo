#include "Movimentacao.h"

Movimentacao::Movimentacao(const std::string descricao, const char debitoCredito, const double valor){
    time_t agora = time(NULL);
    tm* dataAtual = localtime(&agora);
    
    tm data = {0, 0, 0, dataAtual->tm_mday, dataAtual->tm_mon, dataAtual->tm_year};

    this->dataMovimentacao = data;
    this->descricao = descricao;
    this->debitoCredito = debitoCredito;
    this->valor = valor;
}

tm Movimentacao::getDataMovimentacao(){
    return this->dataMovimentacao;
}
std::string Movimentacao::getDescricao(){
    return this->descricao;
}
char Movimentacao::getDebitoCredito(){
    return this->debitoCredito;
}
double Movimentacao::getValor(){
    return this->valor;
}

