#include "Conta.h"

Conta::Conta(const int numeroConta, const Cliente &cliente){
    this->numeroConta = numeroConta;
    this->proximoNumeroConta = numeroConta + 1;
    this->saldo = 0;
    this->cliente = cliente;
}

//Getters
const int Conta::getNumeroConta(){
    return this->numeroConta;
}
const int Conta::getProximoNumeroConta(){
    return this->proximoNumeroConta;
}
const double Conta::getSaldo(){
    return this->saldo;
}
const Cliente Conta::getCliente(){
    return this->cliente;
}
const ListaDeMovimentacoes Conta::getMovimentacoes(){
    return this->movimentacoes;
}

//Outras funções
//void Conta::debitar(const double valor, const std::string descricao);
//void Conta::creditar(const double valor, const std::string descricao);
//const Movimentacoes Conta::extratoDatas(const time_t inicio, const time_t fim);
//const Movimentacoes Conta::extratoMes();