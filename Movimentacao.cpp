#include "Movimentacao.h"

banco::Movimentacao::Movimentacao(const std::string descricao, const char debitoCredito, const double valor){
    time_t agora = time(NULL);
    tm* dataAtual = localtime(&agora);
    
    tm data = {0, 0, 0, dataAtual->tm_mday, dataAtual->tm_mon, dataAtual->tm_year};

    this->dataMovimentacao = data;
    this->descricao = descricao;
    this->debitoCredito = debitoCredito;
    this->valor = valor;
}
banco::Movimentacao::Movimentacao(const std::string descricao, const char debitoCredito, const double valor, const tm data){
    this->descricao = descricao;
    this->debitoCredito = debitoCredito;
    this->valor = valor;
    this->dataMovimentacao = data;
}
const tm banco::Movimentacao::getDataMovimentacao(){
    return this->dataMovimentacao;
}
const std::string banco::Movimentacao::getDescricao(){
    return this->descricao;
}
const char banco::Movimentacao::getDebitoCredito(){
    return this->debitoCredito;
}
const double banco::Movimentacao::getValor(){
    return this->valor;
}
