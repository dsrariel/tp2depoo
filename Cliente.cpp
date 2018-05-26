#include "Cliente.h"

Cliente::Cliente(const std::string nomeCliente, const std::string cpfCnpj, const std::string endereco, const std::string telefone){
    this->nomeCliente = nomeCliente;
    this->cpfCnpj = cpfCnpj;
    this->endereco = endereco;
    this->telefone = telefone;
}

Cliente::Cliente(const Cliente& original){
    this->nomeCliente = original.nomeCliente;
    this->cpfCnpj = original.cpfCnpj;
    this->endereco = original.endereco;
    this->telefone = original.telefone;
}

Cliente& Cliente::operator=(const Cliente& original){
    this->nomeCliente = original.nomeCliente;
    this->cpfCnpj = original.cpfCnpj;
    this->endereco = original.endereco;
    this->telefone = original.telefone;
}

void Cliente::setNomeCliente(const std::string nomeCliente){
    this->nomeCliente = nomeCliente;
}
void Cliente::setCpfCnpj(const std::string cpfCnpj){
    this->cpfCnpj = cpfCnpj;
}
void Cliente::setEndereco(const std::string endereco){
    this->endereco = endereco;
}
void Cliente::setTelefone(const std::string telefone){
    this->telefone = telefone;
}

std::string Cliente::getNomeCliente(){
    return this->nomeCliente;
}

std::string Cliente::getCpfCnpj(){
    return this->cpfCnpj;
}
std::string Cliente::getEndereco(){
    return this->endereco;
}
std::string Cliente::getTelefone(){
    return this->telefone;
}

bool Cliente::operator==(Cliente& A){
    return ((A.getCpfCnpj()==this->getCpfCnpj())&&(A.getEndereco()==this->getEndereco())&&(A.getNomeCliente()==this->getNomeCliente())&&(A.getTelefone()==this->getTelefone()));
}
