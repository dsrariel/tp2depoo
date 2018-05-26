#ifndef CLIENTE_H 
#define CLIENTE_H

#include <string>

class Cliente{
    private:
    std::string  nomeCliente;
    std::string  cpfCnpj;
    std::string  endereco;
    std::string  telefone;

    public:
    Cliente(const std::string nomeCliente = "", const std::string cpfCnpj = "", const std::string endereco = "", const std::string telefone = "");
    Cliente(const Cliente& original);
    Cliente& operator=(const Cliente& original);
    bool operator==(Cliente& A);

    //Setters
    void setNomeCliente(const std::string nomeCliente);
    void setCpfCnpj(const std::string cpfCnpj);
    void setEndereco(const std::string endereco);
    void setTelefone(const std::string telefone);

    //Getters
    std::string const getNomeCliente();
    std::string const getCpfCnpj();
    std::string const getEndereco();
    std::string const getTelefone();
};

#endif