#include "Cliente.h"

Cliente::Cliente(const string& nomeCliente, const string& cpfCnpj, const string& endereco, const string& telefone){
    this->nomeCliente = nomeCliente;
    this->cpfCnpj = cpfCnpj;
    this->endereco = endereco;
    this->telefone = telefone;
}

void Cliente::setNomeCliente(const string& nomeCliente){
    this->nomeCliente = nomeCliente;
}
void Cliente::setCpfCnpj(const string& cpfCnpj){
    this->cpfCnpj = cpfCnpj;
}
void Cliente::setEndereco(const string& endereco){
    this->endereco = endereco;
}
void Cliente::setTelefone(const string& telefone){
    this->telefone = telefone;
}

const string& Cliente::getNomeCliente(){
    return this->nomeCliente;
}

const string& Cliente::getCpfCnpj(){
    return this->cpfCnpj;
}
const string& Cliente::getEndereco(){
    return this->endereco;
}
const string& Cliente::getTelefone(){
    return this->telefone;
}