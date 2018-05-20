#include "Movimentacao.h"

Movimentacao::Movimentacao(const std::string& descricao, const char& debitoCredito, const double& valor){
    time_t agora;
    char data[20];
    agora = time(NULL);
    strftime(data, sizeof(data), "%d/%m/%Y", localtime(&agora));

    this->dataMovimentacao = data;
    this->descricao = descricao;
    this->debitoCredito = debitoCredito;
    this->valor = valor;
}

const std::string& Movimentacao::getDataMovimentacao(){
    return this->dataMovimentacao;
}
const std::string& Movimentacao::getDescricao(){
    return this->descricao;
}
const char& Movimentacao::getDebitoCredito(){
    return this->debitoCredito;
}
const double& Movimentacao::getValor(){
    return this->valor;
}

