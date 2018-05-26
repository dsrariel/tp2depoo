#include "Banco.h"

Banco::Banco(const std::string& nomeBanco){
    this->nomeBanco = nomeBanco;
}

void Banco::setDados(){
    std::ofstream arq("Dados.txt");
    ListaDeClientes::iterator it1;
    ListaDeContas::iterator it2;
    ListaDeMovimentacoes:: iterator it3;
    ListaDeMovimentacoes movimentacao;
    Cliente cliente;
    if (arq.is_open()){

        arq < "CLIENTES \n\n";

        for (it1 = this->clientes.begin(); it1 != this->clientes.end(); it1++){
            arq << "Nome: " << it1->getNomeCliente() << "\n";
            arq << "CPF/CPNJ: " << it1->getCpfCnpj() << "\n";
            arq << "Endereço: " << it1->getEndereco() << "\n";
            arq << "Telefone: " << it1->getTelefone() << "\n\n";
        }
        arq << "CONTAS\n\n";

        for (it2 = this->contas.begin(); it2 != this->contas.end(); it2++){
            cliente=it2->getCliente();
            arq << "Cliente: " << cliente.getNomeCliente() << "\n";
            arq << "Numero da Conta: " << it2->getNumeroConta() << "\n";
            arq << "Saldo: " << it2->getSaldo() << "\n";
            arq << "MOVIMENTAÇOES\n";
            movimentacao=it2->getMovimentacoes();
            for(it3 = movimentacao.begin(); it3 != movimentacao.end() ; it3++){
                if(it3->getDebitoCredito()=='D'){
                    arq << it3->getDescricao() << ", Valor = " << it3->getValor() << ", Debito, data: " << it3->getDataMovimentacao() << "\n";
                }else{
                    arq << it3->getDescricao() << ", Valor = " << it3->getValor() << ", Credito, data: " << it3->getDataMovimentacao() << "\n";
                }
            }
            arq << "\n";
        }

        arq.close();
    }
}

const ListaDeClientes  Banco::getClientes(){
    return this->clientes;
}

const ListaDeContas Banco::getContas(){
    return this->contas;
}

const int getNovoNumeroConta(){
    return this->contas.begin().proximoNumeroConta;
}

bool Banco::inserirCliente(const Cliente& cliente){
    ListaDeClientes::iterator it = std::find(this->clientes.begin(), this->clientes.end(), cliente);
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
        if(it1->getCpfCnpj() == cpfCnpj){
            for (it2 = this->contas.begin(); it2 != this->contas.end(); it2++){
                //Conta encontrada
                if(it2->getCliente()==it1){
                    return 0;
                }
            }
            //Conta não encontrada
            this->clientes.erase(it1);
            return 1;
        }
    }
    //Cliente não encontrado
    return 0;
}

void Banco::inserirConta(const Cliente& cliente){
    Conta conta = Conta(cliente);
    this->contas.push_back(conta);
}

bool Banco::excluirConta (int numeroConta){
    ListaDeContas::iterator it;
    for (it = this->contas.begin(); it != this->contas.end(); it++){
        //Conta encontrada
        if(it->getNumeroConta() == numeroConta){
            this->contas.erase(it);
            return 1;
        }
    }
    //Conta não encontrada
    return 0;
}

bool Banco::depositar (int numeroConta, double valor){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
        if(it->getNumeroConta() == numeroConta){
            it->creditar(valor,"Deposito");
            return 1;
        }
    }
    //conta nao encontrada
    return 0;
}

bool Banco::sacar (int numeroConta, double valor){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
        if(it->getNumeroConta() == numeroConta){
            //saldo insuficiente
            if(it->getSaldo()<valor){
                return 0;
            }else{      //saldo suficiente
                it->debitar(valor,"Saque");
                return 1;
            }
        }
    }
    //conta nao encontrada
    return 0;
}

bool Banco::transferencia (int numeroContaOrigem, int numeroContaDestino, double valor){
    ListaDeContas::iterator it,contaO,contaD;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //encontrou conta de origem
        if(it->getNumeroConta() == numeroContaOrigem){
            contaO=it;
        }
        //encontrou conta de destino
        if(it->getNumeroConta() == numeroContaDestino){
            contaD=it;
        }
    }
    //as duas contas existem
    if((contaO->getNumeroConta()==numeroContaOrigem) && (contaD->getNumeroConta()==numeroContaDestino)){
        std::string descricao,str1,str2;
        descricao="Transferencia para conta " + std::to_string(numeroContaDestino);
        //conta de origem com saldo suficiente, transferencia realizada
        if(contaO->debitar(valor,descricao)){
            descricao="Transferencia da conta " + std::to_string(numeroContaOrigem);
            contaD->creditar(valor,descricao);
            return 1;
        }

    }
    return 0;

}

void Banco::tarifa(){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        it->debitar(15,"Cobranca de Tarifa.");
    }
}

void Banco::cpmf(){
    ListaDeContas::iterator itC;
    ListaDeMovimentacoes movimetacoesDaSemana;
    ListaDeMovimentacoes:: iterator itM;
    double Cpmf=0;
    //percorre a lista de contas
    for(itC= this->contas.begin();itC != this->contas.end();itC++){
        movimetacoesDaSemana=itC->extratoDatas(inicio,fim);
        //soma todos os valores das movimentacoes de debito
        for(itM=movimetacoesDaSemana.begin();itM != movimetacoesDaSemana.end();itM++){
            if(itM->getDebitoCredito()=='D'){
               Cpmf=Cpmf+itM->getValor();
            }
        }
        //debita 0.38% da conta
        if(Cpmf!=0){
            Cpmf=Cpmf*0,0038;
            itC->debitar(Cpmf,"Cobranca de CPMF.");
        }

    }
}

int Banco::saldoConta(int numeroConta){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
         if(it->getNumeroConta() == numeroConta){
            return it->getSaldo();
         }
    }
    //conta nao encontrada
    return -1;
}

const ListaDeMovimentacoes Banco::extratoMes(int numeroConta){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
         if(it->getNumeroConta() == numeroConta){
            return it->extratoMes();
         }
    }
}

const ListaDeMovimentacoes Banco::extratoDatas(int numeroConta, tm inicio, tm fim){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
         if(it->getNumeroConta() == numeroConta){
            return it->extratoDatas(inicio,fim);
         }
    }
}
