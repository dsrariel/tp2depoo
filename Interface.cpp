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
    std::string nomeBanco = "NU Banco";
    Banco banco(nomeBanco);
    banco.getDados();
    int opcao = this->menu(nomeBanco);

    while (opcao != 14){
        switch (opcao){
            case 1:
                this->inserirCliente(banco);
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

    bool sucesso = banco.inserirCliente(cliente);
    if (sucesso)
        std::cout << "\nCliente inserido com sucesso! ";
    else
        std::cout << "\nO cliente já existe. ";
    
    std::cout << "Pressione enter para voltar ao menu. " << std::endl;
    std::getline(std::cin, entrada);
    return;
}
//void Interface::inserirConta(Banco& banco){}
//void Interface::excluirCliente(Banco& banco){}
//void Interface::excluirConta(Banco& banco){}
//void Interface::depositar(Banco& banco){}
//void Interface::sacar(Banco& banco){}
//void Interface::tranferir(Banco& banco){}
//void Interface::cobrarTarifa(Banco& banco){}
//void Interface::cobrarCPMF(Banco& banco){}
//void Interface::saldo(Banco& banco){}
//void Interface::extrato(Banco& banco){}
//void Interface::listarClientes(Banco& banco){}
//void Interface::listarContas(Banco& banco){}