#ifndef BANCO_H 
#define BANCO_H

#include <string>
#include <list>
#include "Cliente.h"
#include "Conta.h"

typedef std::list<Cliente> ListaDeClientes
typedef std::list<Conta> ListaDeContas

class Banco{
    private:
    std::string  nomeBanco;
    ListaDeClientes clientes;
    ListaDeContas contas;

    public:
    Banco(const std::string& nomeBanco);

    //Setters
    void setDados();

    //Getters
    const ListaDeCliente& getClientes();
    const ListaDeContas& getContas();
    void getDados();

    //Outros
    const int& inserirCliente(const Cliente& cliente); //Retorna 1 caso cliente não exista (sucesso) e 0 caso já exista (falha)
    const int& excluirCliente(const int& cpfCnpj); //Retorna 1 caso cliente não possua conta (sucesso) e 0 caso possua (falha)
    void inserirConta(const Cliente& cliente);
    const int& excluirConta (const int& numeroConta); //Retorna 1 caso conta exista (sucesso) e 0 caso não exista (falha)
    const int& depositar (const int& numeroConta, const double& valor); //Retorna 1 caso conta exista (sucesso) e 0 caso não exista (falha)
    const int& sacar (const int& numeroConta, const double& valor); //Retorna 1 caso conta exista (sucesso) e 0 caso não (falha)
    const int& transferencia (const int& numeroContaOrigem, const int& numeroContaDestino, const double& valor); //Retorna 1 caso contas existam (sucesso) e 0 caso não (falha)
    void tarifa();
    void cpmf();
    const int& saldoConta(const int& numeroConta); //Retorna o quê caso conta não exista?
    const ListaDeMovimentacoes& extratoMes(const int& numeroConta); //Retorna o quê caso a conta não exista?
    const ListaDeMovimentacoes& extratoDatas(const time_t& inicio, const time_t& fim); //Retorna o quê caso a conta não exista?
};
#endif