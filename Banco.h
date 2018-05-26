#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED

#include <string>
#include <list>
#include <algorithm>
#include "Cliente.h"
#include "Conta.h"

typedef std::list<Cliente> ListaDeClientes;
typedef std::list<Conta> ListaDeContas;

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
    const ListaDeClientes getClientes();
    const ListaDeContas getContas();
    void getDados();
    const int getNovoNumeroConta(); //Gera novo número de conta para criação de conta

    //Outros
    bool inserirCliente(const Cliente& cliente); //Retorna True caso cliente não exista (sucesso) e False caso já exista (falha)
    bool excluirCliente(const std::string& cpfCnpj); //Retorna True caso cliente não possua conta (sucesso) e False caso possua (falha)
    void inserirConta(const Cliente& cliente);
    bool excluirConta (int numeroConta); //Retorna True caso conta exista (sucesso) e False caso não exista (falha)
    bool depositar (int numeroConta, double valor); //Retorna True caso conta exista (sucesso) e False caso não exista (falha)
    bool sacar (int numeroConta, double valor); //Retorna True caso conta exista (sucesso) e False caso não (falha)
    bool transferencia (int numeroContaOrigem, int numeroContaDestino, double valor); //Retorna True caso contas existam (sucesso) e False caso não (falha)
    void tarifa();//debita, caso tenha saldo suficiente, 15 reais de cada conta
    void cpmf();
    int saldoConta(int numeroConta); ////Retorna -1 caso conta não exista
    const ListaDeMovimentacoes extratoMes(int numeroConta); //Retorna o quê caso a conta não exista?
    const ListaDeMovimentacoes extratoDatas(int numeroConta , tm inicio, tm fim); //Retorna o quê caso a conta não exista?
};
#endif // BANCO_H_INCLUDE
