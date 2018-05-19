#ifndef CLIENTE_H 
#define CLIENTE_H

#include <iostream>
#include <string>

class Cliente{
    private:
    std::string  nomeCliente;
    std::string  cpfCnpj;
    std::string  endereco;
    std::string  telefone;

    public:
    Cliente(const std::string& nomeCliente, const std::string& cpfCnpj, const std::string& endereco, const std::string& telefone);

    //Setters
    void setNomeCliente(const std::string& nomeCliente);
    void setCpfCnpj(const std::string& cpfCnpj);
    void setEndereco(const std::string& endereco);
    void setTelefone(const std::string& telefone);

    //Getters
    const std::string& getNomeCliente();
    const std::string& getCpfCnpj();
    const std::string& getEndereco();
    const std::string& getTelefone();
};
#endif