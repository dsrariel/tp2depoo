#include "Cliente.h"

banco::Cliente::Cliente(const std::string nomeCliente, const std::string cpfCnpj, const std::string endereco, const std::string telefone){
    this->nomeCliente = nomeCliente;
    this->cpfCnpj = cpfCnpj;
    this->endereco = endereco;
    this->telefone = telefone;
}

banco::Cliente::Cliente(const Cliente& original){
    this->nomeCliente = original.nomeCliente;
    this->cpfCnpj = original.cpfCnpj;
    this->endereco = original.endereco;
    this->telefone = original.telefone;
}

banco::Cliente& banco::Cliente::operator=(const Cliente& original){
    this->nomeCliente = original.nomeCliente;
    this->cpfCnpj = original.cpfCnpj;
    this->endereco = original.endereco;
    this->telefone = original.telefone;
}

void banco::Cliente::setNomeCliente(const std::string nomeCliente){
    this->nomeCliente = nomeCliente;
}
void banco::Cliente::setCpfCnpj(const std::string cpfCnpj){
    this->cpfCnpj = cpfCnpj;
}
void banco::Cliente::setEndereco(const std::string endereco){
    this->endereco = endereco;
}
void banco::Cliente::setTelefone(const std::string telefone){
    this->telefone = telefone;
}

std::string const banco::Cliente::getNomeCliente(){
    return this->nomeCliente;
}

std::string const banco::Cliente::getCpfCnpj(){
    return this->cpfCnpj;
}
std::string const banco::Cliente::getEndereco(){
    return this->endereco;
}
std::string const banco::Cliente::getTelefone(){
    return this->telefone;
}

bool banco::Cliente::operator==(Cliente& A){
    return ((A.getCpfCnpj()==this->getCpfCnpj())&&(A.getEndereco()==this->getEndereco())&&(A.getNomeCliente()==this->getNomeCliente())&&(A.getTelefone()==this->getTelefone()));
}
