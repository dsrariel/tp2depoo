#include "Banco.h"

Banco::Banco(const std::string& nomeBanco){
    this->nomeBanco = nomeBanco;
}

const ListaDeClientes  Banco::getClientes(){
    return this->clientes;
}

const ListaDeContas Banco::getContas(){        
    return this->contas;
}

bool Banco::inserirCliente(const Cliente& cliente){
    auto it = std::find(this->clientes.begin(), this->clientes.end(), cliente);
    if(it == this->clientes.end()){
        this->clientes.push_back(cliente);
        return 1;
    }
    else{
        return 0;
    }
}

bool Banco::excluirCliente(const std::string& cpfCnpj){
    ListaDeClientes::iterator it1;
    ListaDeContas::iterator it2;
    for (it1 = this->clientes.begin(); it1 != this->clientes.end(); it1++){
        //Cliente encontrado
        if(it1->getCpfCnpj == cpfCnpj){
            for (it2 = this->contas.begin(); it2 != this->contas.end(); it2++){    
                //Conta encontrada
                if(it2->getCliente==it1){
                    return 0;
                }
            }
            //Conta não encontrada
            this->clientes.erase(it1);    
            return 1;                
        }
    }
    //Cliente não encotrado
    return 0;
}

void Banco::inserirConta(const Cliente& cliente){
    Conta conta = Conta(cliente);
    this->contas.push_back(conta);
}
