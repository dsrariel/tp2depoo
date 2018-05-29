#include "Interface.h"

int Interface::menu(std::string nomeBanco){
    std::string entrada = "";
    int opcao = 15;
    while((opcao > 14)||(opcao < 1)){
        std::cout << std::string(50, '\n');
        std::cout << "Bem-vindo ao " << nomeBanco << "! O que deseja fazer?" << std::endl;
        std::cout << "01.\t" << "Cadastrar novo cliente." << std::endl;
        std::cout << "02.\t" << "Criar nova conta." << std::endl;
        std::cout << "03.\t" << "Excluir cliente." << std::endl;
        std::cout << "04.\t" << "Excluir conta." << std::endl;
        std::cout << "05.\t" << "Deposito." << std::endl;
        std::cout << "06.\t" << "Saque." << std::endl;
        std::cout << "07.\t" << "Transferencia entre contas." << std::endl;
        std::cout << "08.\t" << "Cobrar tarifa." << std::endl;
        std::cout << "09.\t" << "Cobrar CPMF." << std::endl;
        std::cout << "10.\t" << "Obter saldo." << std::endl;
        std::cout << "11.\t" << "Obter extrato." << std::endl;
        std::cout << "12.\t" << "Listar clientes." << std::endl;
        std::cout << "13.\t" << "Listar contas." << std::endl;
        std::cout << "14.\t" << "Sair." << std::endl;
        std::cout << "Insira um numero valido: ";
        std::getline(std::cin, entrada);
        std::stringstream stream(entrada);
        stream >> opcao;
    }
    return opcao;
}

int Interface::main(){
    std::string nomeBanco = "Banco da COG";
    Banco banco(nomeBanco);
    banco.getDados();
    int opcao = this->menu(nomeBanco);

    while (opcao != 14){
        switch (opcao){
            case 1:
                this->inserirCliente(banco);
                break;
            case 2:
                this->inserirConta(banco);
                break;
            case 3:
                this->excluirCliente(banco);
                break;
            case 4:
                this->excluirConta(banco);
                break;
            case 5:
                this->depositar(banco);
                break;
            case 6:
                this->sacar(banco);
                break;
            case 8:
                this->cobrarTarifa(banco);
                break;
            case 9:
                this->cobrarCPMF(banco);
                break;
            case 10:
                this->saldo(banco);
                break;
            case 11:
                this->extrato(banco);
                break;
            case 12:
                this->listarClientes(banco);
                break;
            case 13:
                this->listarContas(banco);
                break;
        }

        opcao = this->menu(nomeBanco);
    }

    banco.setDados();
    return 0;
}

void Interface::inserirCliente(Banco& banco){
    Cliente cliente;
    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "01.\t" << "Cadastrar novo cliente." << std::endl;

    std::cout << "Nome: ";
    std::getline(std::cin, entrada);
    cliente.setNomeCliente(entrada);

    std::cout << "CPF/CNPJ [xxx.xxx.xxx-xx]: ";
    std::getline(std::cin, entrada);
    cliente.setCpfCnpj(entrada);

    std::cout << "Endereco: ";
    std::getline(std::cin, entrada);
    cliente.setEndereco(entrada);

    std::cout << "Telefone [(xx)xxxxx-xxxx]: ";
    std::getline(std::cin, entrada);
    cliente.setTelefone(entrada);

    if((cliente.getNomeCliente() == "") || (cliente.getCpfCnpj() == "") || (cliente.getEndereco() == "") || (cliente.getTelefone()  == "")){
        std::cout << "\nInsira informações válidas. ";
        std::cout << "Pressione enter para voltar ao menu. " << std::endl;
        std::getline(std::cin, entrada);
        return;
    }

    bool sucesso = banco.inserirCliente(cliente);
    if (sucesso)
        std::cout << "\nCliente inserido com sucesso! ";
    else
        std::cout << "\nO cliente já existe. ";

    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::inserirConta(Banco& banco){
    Cliente cliente;
    ListaDeClientes clientes;
    ListaDeClientes::iterator it;

    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "02.\t" << "Criar nova conta." << std::endl;

    std::cout << "CPF/CNPJ [xxx.xxx.xxx-xx]: ";
    std::getline(std::cin, entrada);


    clientes=banco.getClientes();

    for (it = clientes.begin(); it != clientes.end(); it++){
        //encontrou o cliente
        if(entrada==it->getCpfCnpj()){
            cliente=*it;
            banco.inserirConta(cliente);
            std::cout << "\nConta criada com sucesso! ";
            std::cout << "Pressione enter para voltar ao menu. " << std::endl;
            std::getline(std::cin, entrada);
            return;
        }
    }
    std::cout << "\nCliente ainda nao pertence ao Banco, insira o cliente para poder criar uma conta. ";
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::excluirCliente(Banco& banco){
    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "03.\t" << "Excluir cliente." << std::endl;

    std::cout << "CPF/CNPJ [xxx.xxx.xxx-xx]: ";
    std::getline(std::cin, entrada);

    int acao=banco.excluirCliente(entrada);
    //nao possui conta
    if(acao==1){
        std::cout << "\nCliente excluído com sucesso! ";
    }else if(acao==0){
        std::cout << "\nCliente possui conta, não é possivel excluí-lo. ";
    }else{
        std::cout << "\nCliente não é cadastrado no Banco. ";
    }
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::excluirConta(Banco& banco){
    int numeroConta,acao;

    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "04.\t" << "Excluir conta." << std::endl;

    std::cout << "Insira o numero da conta: ";
    std::getline(std::cin, entrada);

    numeroConta=std::atoi(entrada.c_str());
    acao=banco.excluirConta(numeroConta);

    if(acao==1){
        std::cout << "\nConta excluída com sucesso! ";
    }else{
        std::cout << "\nConta inválida. ";
    }
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::depositar(Banco& banco){
    int numeroConta,acao;
    double valor;

    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "05.\t" << "Deposito." << std::endl;

    std::cout << "Insira o numero da conta: ";
    std::getline(std::cin, entrada);
    numeroConta=atoi(entrada.c_str());

    std::cout << "\nInsira o valor do deposito: ";
    std::getline(std::cin, entrada);
    valor=atof(entrada.c_str());

    acao=banco.depositar(numeroConta,valor);

    if(acao==1){
        std::cout << "\nDeposito realizado com sucesso! ";
    }else{
        std::cout << "\nConta inválida. ";
    }
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::sacar(Banco& banco){
    int numeroConta,acao;
    double valor;
    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "06.\t" << "Saque." << std::endl;

    std::cout << "Insira o numero da conta: ";
    std::getline(std::cin, entrada);
    numeroConta=atoi(entrada.c_str());

    std::cout << "\nInsira o valor do saque: ";
    std::getline(std::cin, entrada);
    valor=atof(entrada.c_str());

    acao=banco.sacar(numeroConta,valor);

    if(acao==1){
        std::cout << "\nSaque realizado com sucesso! ";
    }else if(acao==0){
        std::cout << "\nSaldo insuficiente. ";
    }else{
        std::cout << "\nConta inválida. ";
    }
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;

}

void Interface::transferir(Banco& banco){
    int ContaO,ContaD,valor,acao;
    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "07.\t" << "Transferencia entre contas." << std::endl;

    std::cout << "Insira o numero da conta de origem: ";
    std::getline(std::cin, entrada);
    ContaO=atoi(entrada.c_str());

    std::cout << "Insira o numero da conta de destino: ";
    std::getline(std::cin, entrada);
    ContaD=atoi(entrada.c_str());

    std::cout << "\nInsira o valor da transferência: ";
    std::getline(std::cin, entrada);
    valor=atof(entrada.c_str());

    acao=banco.transferencia(ContaO,ContaD,valor);

    if(acao==1){
        std::cout << "\nTransferência realizada com sucesso! ";
    }else{
        std::cout << "\nConta inválida. ";
    }

    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::cobrarTarifa(Banco& banco){
    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "08.\t" << "Cobrar tarifa." << std::endl;

    banco.tarifa();

    std::cout << "Tarifa cobrada com sucesso! ";
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::cobrarCPMF(Banco& banco){
    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "09.\t" << "Cobrar CPMF." << std::endl;

    banco.cpmf();

    std::cout << "CPMF cobrada com sucesso! ";
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::saldo(Banco& banco){
    int numeroConta;
    double saldo;

    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "10.\t" << "Obter saldo." << std::endl;

    std::cout << "Insira o numero da conta: ";
    std::getline(std::cin, entrada);
    numeroConta=atoi(entrada.c_str());

    saldo=banco.saldoConta(numeroConta);
    if(saldo==-1){
        std::cout << "\nConta inválida. ";
    }else{
        std::cout << "\nO saldo atual é: "<<saldo<< " reais. ";
    }
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::extrato(Banco& banco){
    int opcao=4,achou=0, numeroConta,DIA,MES,ANO;
    ListaDeMovimentacoes movimentacoes;
    ListaDeMovimentacoes::iterator it;
    ListaDeContas contas;
    ListaDeContas::iterator it1;

    std::string entrada = "",data,dia,mes,ano;
    std::cout << std::string(50, '\n');
    std::cout << "11.\t" << "Obter extrato.\n" << std::endl;

    std::cout << "Insira o numero da conta: ";
    std::getline(std::cin, entrada);
    numeroConta=atoi(entrada.c_str());

    contas=banco.getContas();

    for(it1= contas.begin();it1 != contas.end();it1++){
        if(it1->getNumeroConta() == numeroConta){
            achou=1;
        }
    }

    if(achou==1){
        while((opcao > 3)||(opcao < 1)){
            std::cout << std::string(50, '\n');
            std::cout << "Selecione o extrato desejado." << std::endl;
            std::cout << "11-01.\t" << "Extrato do mês." << std::endl;
            std::cout << "11-02.\t" << "Extrato a partir de uma data inicial." << std::endl;
            std::cout << "11-03.\t" << "Extrato entre datas específicas." << std::endl;

            std::getline(std::cin, entrada);
            std::stringstream stream(entrada);
            stream >> opcao;
        }

        if(opcao==1){
            movimentacoes=banco.extratoMes(numeroConta);
        }else if(opcao==2){
            std::cout << std::string(50, '\n');
            std::cout << "11-02.\t" << "Extrato a partir de uma data inicial." << std::endl;
            std::cout << "Insira a data inicial [ xx xx xxxx ]: ";
            std::getline(std::cin, data);

            std::istringstream token(data);
            std::getline(token,dia,' ');
            std::getline(token,mes,' ');
            std::getline(token,ano,' ');

            DIA=std::atoi(dia.c_str());
            MES=std::atoi(mes.c_str())-1;
            ANO=std::atoi(ano.c_str())-1900;

            tm dataI = {0,0,0,DIA,MES,ANO};
            movimentacoes=banco.extratoDataInicial(numeroConta,dataI);
        }else{
            std::cout << std::string(50, '\n');
            std::cout << "11-03.\t" << "Extrato entre datas específicas." << std::endl;
            std::cout << "Insira a data inicial [ xx xx xxxx ]: ";
            std::getline(std::cin, data);

            std::istringstream token(data);
            std::getline(token,dia,' ');
            std::getline(token,mes,' ');
            std::getline(token,ano,' ');

            DIA=std::atoi(dia.c_str());
            MES=std::atoi(mes.c_str())-1;
            ANO=std::atoi(ano.c_str())-1900;

            tm dataI = {0,0,0,DIA,MES,ANO};

            std::cout << "Insira a data final [ xx xx xxxx ]: ";
            std::getline(std::cin, data);

            std::istringstream token1(data);
            std::getline(token1,dia,' ');
            std::getline(token1,mes,' ');
            std::getline(token1,ano,' ');

            DIA=std::atoi(dia.c_str());
            MES=std::atoi(mes.c_str())-1;
            ANO=std::atoi(ano.c_str())-1900;

            tm dataF = {0,0,0,DIA,MES,ANO};
            movimentacoes=banco.extratoDatas(numeroConta,dataI,dataF);
        }
        std::cout << std::string(50, '\n');

        std::cout << "Movimentaçoes:\n" << std::endl;
        for(it = movimentacoes.begin(); it != movimentacoes.end(); it++){
            tm dat=it->getDataMovimentacao();
            DIA=dat.tm_mday;
            MES=dat.tm_mon+1;
            ANO=dat.tm_year+1900;
            if(it->getDebitoCredito()=='D'){
                std::cout << it->getDescricao() << ", Valor = " << it->getValor() << ", Debito, Data: " << DIA << "/" << MES << "/" << ANO <<"\n";
            }else{
                std::cout << it->getDescricao() << ", Valor = " << it->getValor() << ", Credito, Data: " << DIA << "/" << MES << "/" << ANO <<"\n";
            }
        }
    }else{
        std::cout << "Conta inválida." << std::endl;
         std::cout << "Pressione enter para voltar ao menu. " << std::endl;
        std::getline(std::cin, entrada);
        return;
    }

    double saldo=banco.saldoConta(numeroConta);
    std::cout << "\nO saldo atual é: "<<saldo<< " reais. ";

    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::listarClientes(Banco& banco){
    ListaDeClientes clientes;
    ListaDeClientes::iterator it;

    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "12.\t" << "Listar clientes.\n" << std::endl;

    clientes=banco.getClientes();

    for (it = clientes.begin(); it != clientes.end(); it++){
        std::cout << "Nome: " << it->getNomeCliente() << "\n";
        std::cout << "CPF/CPNJ: " << it->getCpfCnpj() << "\n";
        std::cout << "Endereço: " << it->getEndereco() << "\n";
        std::cout << "Telefone: " << it->getTelefone() << "\n\n";
    }

    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}

void Interface::listarContas(Banco& banco){
    ListaDeContas contas;
    ListaDeContas::iterator it;
    Cliente cliente;

    std::string entrada = "";
    std::cout << std::string(50, '\n');
    std::cout << "13.\t" << "Listar contas.\n" << std::endl;

    contas=banco.getContas();

    for(it = contas.begin(); it != contas.end(); it++){
        cliente=it->getCliente();
        std::cout << "Numero da Conta: " << it->getNumeroConta() << "\n";
        std::cout << "Cliente: " << cliente.getNomeCliente() << ", "<<cliente.getCpfCnpj() <<"\n";
        std::cout << "Saldo: " << it->getSaldo() << "\n\n";
    }

    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}
