#include "Cliente.h"

Cliente::Cliente(const std::string& nomeCliente, const std::string& cpfCnpj, const std::string& endereco, const std::string& telefone){
    this->nomeCliente = nomeCliente;
    this->cpfCnpj = cpfCnpj;
    this->endereco = endereco;
    this->telefone = telefone;
}

void Cliente::setNomeCliente(const std::string& nomeCliente){
    this->nomeCliente = nomeCliente;
}
void Cliente::setCpfCnpj(const std::string& cpfCnpj){
    this->cpfCnpj = cpfCnpj;
}
void Cliente::setEndereco(const std::string& endereco){
    this->endereco = endereco;
}
void Cliente::setTelefone(const std::string& telefone){
    this->telefone = telefone;
}

const std::string& Cliente::getNomeCliente(){
    return this->nomeCliente;
}

const std::string& Cliente::getCpfCnpj(){
    return this->cpfCnpj;
}
const std::string& Cliente::getEndereco(){
    return this->endereco;
}
const std::string& Cliente::getTelefone(){
    return this->telefone;
}