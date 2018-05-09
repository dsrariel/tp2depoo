#ifndef CLIENTE_H 
#define CLIENTE_H

#include <iostream>
#include <string>
using namespace std;

class Cliente{
    private:
    string  nomeCliente;
    string  cpfCnpj;
    string  endereco;
    string  telefone;

    public:
    Cliente(const string& nomeCliente, const string& cpfCnpj, const string& endereco, const string& telefone);

    //Setters
    void setNomeCliente(const string& nomeCliente);
    void setCpfCnpj(const string& cpfCnpj);
    void setEndereco(const string& endereco);
    void setTelefone(const string& telefone);

    //Getters
    const string& getNomeCliente();
    const string& getCpfCnpj();
    const string& getEndereco();
    const string& getTelefone();
};
#endif