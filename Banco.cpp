#include "Banco.h"

Banco::Banco(const std::string& nomeBanco){
    this->nomeBanco = nomeBanco;
}

const ListaDeClientes  Banco::getClientes(){        //retorna a lista de clientes do banco
    return this->clientes;
}

const ListaDeContas Banco::getContas(){             //retorna a lista de contas do banco
    return this->contas;
}

const int Banco::inserirCliente(const Cliente& cliente){
    auto it = std::find(this->clientes.begin(),this->clientes.end(),cliente);
    if(it == this->clientes.end()){     //cliente não existe no banco
        this->clientes.push_back(cliente);
        return 1;                       //sucesso
    }else{
        return 0;                       //cliente ja existe no banco, falha
    }
}

const int Banco::excluirCliente(const std::string& cpfCnpj){
    for (std::list<Cliente>::iterator it1 = this->clientes.begin(); it1 != this->clientes.end(); it1++){    //procura cliente na lista de clientes
        if(strcmp(it1.cpfCnpj,cpfCnpj)==0){          //cliente encontrado na lista
            for (std::list<Conta>::iterator it2 = this->contas.begin(); it2 != this->contas.end(); it2++){ //verifica se o cliente possui uma conta no banco
                if(it2.cliente==it1){    //cliente possui conta
                    std::cout<<"Cliente possui conta, falha ao exclui-lo. "<<'\n';
                    return 0;           //falha
                }
            }
             //Cliente nao possui conta
             this->clientes.erase(it1);     //exclui o cliente
             std::cout<<"O cliente foi excluido com sucesso."<<'\n';
             return 1;                      //sucesso
        }
    }
     std::cout<<"O cliente nao existe no banco."<<'\n';
     return 0;        //falha
}

void Banco::inserirConta(const Cliente& cliente){
    Conta conta = Conta(cliente);
    this->contas.push_back(conta);
}
