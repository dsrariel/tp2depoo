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
void Conta::debitar(const double valor, const std::string descricao){
    Movimentacao movimentacao(descricao, 'D', valor);
    this->movimentacoes.push_back(movimentacao);
}
void Conta::creditar(const double valor, const std::string descricao){
    Movimentacao movimentacao(descricao, 'C', valor);
    this->movimentacoes.push_back(movimentacao);
}
const ListaDeMovimentacoes Conta::extratoDatas(const std::string inicio, const std::string fim){
    
}
//const ListaDeMovimentacoes Conta::extratoMes();

int dataEntreInicioEFim(const std::string data, const std::string inicio, const std::string fim){}
