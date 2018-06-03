#include "Banco.h"

banco::Banco::Banco(const std::string& nomeBanco){
    this->nomeBanco = nomeBanco;
}

void banco::Banco::setDados(){
    std::ofstream arq("Dados.txt");
    ListaDeClientes::iterator it1;
    ListaDeContas::iterator it2;
    ListaDeMovimentacoes:: iterator it3;
    ListaDeMovimentacoes movimentacao;
    Cliente cliente;
    tm data;
    int dia,mes,ano;

    if (arq.is_open()){

        arq << "CLIENTES\n\n";

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
                data=it3->getDataMovimentacao();
                dia=data.tm_mday;
                mes=data.tm_mon+1;
                ano=data.tm_year+1900;
                if(it3->getDebitoCredito()=='D'){
                    arq << it3->getDescricao() << ", Valor = " << it3->getValor() << ", Debito, Data: " << dia << "/" << mes << "/" <<ano <<"\n";
                }else{
                    arq << it3->getDescricao() << ", Valor = " << it3->getValor() << ", Credito, Data: " << dia << "/" << mes << "/" <<ano <<"\n";
                }
            }
            arq << "\n";
        }

        arq.close();
    }
}

const ListaDeClientes  banco::Banco::getClientes(){
    return this->clientes;
}

const ListaDeContas banco::Banco::getContas(){
    return this->contas;
}

void banco::Banco::getDados(){
    int numeroConta=0,DIA,MES,ANO;
    double val,saldo;
    char DC;
    std::string linha,nome,cpfCnpj,endereco,telefone,descricao,valor,debitoCredito,data,dia,mes,ano;
    ListaDeClientes::iterator it;
    ListaDeMovimentacoes movimentacoes;

    Cliente cliente;
    std::ifstream arq("Dados.txt");

    if (arq.is_open()){
        while(!arq.eof()){
            std::getline(arq,linha);
            //cria a lista de clientes
            if(linha=="CLIENTES") {
                std::getline(arq,linha);
                while(linha!="CONTAS"){

                    if(linha.size()>0){
                    nome=linha.erase(0,6);
                        std::getline(arq,linha);
                        cpfCnpj=linha.erase(0,10);

                        std::getline(arq,linha);
                        endereco=linha.erase(0,11);

                        std::getline(arq,linha);
                        telefone=linha.erase(0,10);

                        cliente=Cliente(nome,cpfCnpj,endereco,telefone);
                        this->inserirCliente(cliente);
                    }
                    std::getline(arq,linha);
                }
            }
            //cria a lista de contas
            if(linha.size()>0 && linha!="CONTAS"){
                nome=linha.erase(0,9);

                std::getline(arq,linha);
                linha.erase(0,17);
                numeroConta=std::atoi(linha.c_str());

                std::getline(arq,linha);
                linha.erase(0,7);
                saldo=std::atof(linha.c_str());

                std::getline(arq,linha);//linha=MOVIMENTACOES
                std::getline(arq,linha);
                //tem movimentacoes
                while(linha.size()>0){
                    std::istringstream token(linha);

                    std::getline(token,descricao,',');
                    std::getline(token,valor,',');
                    std::getline(token,debitoCredito,',');
                    std::getline(token,data,',');

                    DC=debitoCredito[1];

                    valor.erase(0,9);
                    val=std::atof(valor.c_str());

                    std::istringstream token1(data);
                    std::getline(token1,dia,'/');
                    std::getline(token1,mes,'/');
                    std::getline(token1,ano,'/');
                    dia.erase(0,7);
                    DIA=std::atoi(dia.c_str());
                    MES=std::atoi(mes.c_str())-1;
                    ANO=std::atoi(ano.c_str())-1900;
                    tm dat={0,0,0,DIA,MES,ANO};
                    //cria lista de movimentacoes
                    Movimentacao movimentacao=Movimentacao(descricao,DC,val,dat);
                    movimentacoes.push_back(movimentacao);

                    std::getline(arq,linha);
                }

                for (it = this->clientes.begin(); it != this->clientes.end(); it++){
                    //Cliente encontrado
                    if(it->getNomeCliente()==nome){
                        cliente=*it;
                        Conta conta=Conta(cliente,numeroConta,numeroConta+1,saldo,movimentacoes);
                        this->contas.push_back(conta);
                    }
                }
                movimentacoes.clear();
            }
        }
        arq.close();
    }
}

bool banco::Banco::inserirCliente(const Cliente& cliente){
    ListaDeClientes::iterator it;
    Cliente clt=cliente;
    for (it = this->clientes.begin(); it != this->clientes.end(); it++){
        if(*it==clt){
            return 0;
        }
    }
        this->clientes.push_back(cliente);
        return 1;
}

int banco::Banco::excluirCliente(const std::string& cpfCnpj){
    ListaDeClientes::iterator it1;
    ListaDeContas::iterator it2;
    Cliente clt1,clt2;

    for (it1 = this->clientes.begin(); it1 != this->clientes.end(); it1++){
        //Cliente encontrado
        if(it1->getCpfCnpj() == cpfCnpj){
            for (it2 = this->contas.begin(); it2 != this->contas.end(); it2++){
                //Conta encontrada
		clt1=*it1;
		clt2=it2->getCliente();
                if(clt1==clt2){
                    return 0;
                }
            }
            //Conta não encontrada
            this->clientes.erase(it1);
            return 1;
        }
    }
    //Cliente não encontrado
    return -1;
}

void banco::Banco::inserirConta(const Cliente& cliente){
    Conta conta = Conta(cliente);
    this->contas.push_back(conta);
}

bool banco::Banco::excluirConta (int numeroConta){
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

bool banco::Banco::depositar (int numeroConta, double valor){
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

int banco::Banco::sacar (int numeroConta, double valor){
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
    return -1;
}

bool banco::Banco::transferencia (int numeroContaOrigem, int numeroContaDestino, double valor){
    ListaDeContas::iterator it,contaO,contaD;
    std::string descricao;
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
        //conta de origem com saldo suficiente, transferencia realizada
        if(contaO->getSaldo()>=valor){
	    descricao="Transferencia para conta " + std::to_string(numeroContaDestino);
	    contaO->debitar(valor,descricao);
            descricao="Transferencia da conta " + std::to_string(numeroContaOrigem);
            contaD->creditar(valor,descricao);
            return 1;
        }

    }
    return 0;

}

void banco::Banco::tarifa(){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
	//cobra tarifa caso tenha saldo suficiente
	if(it->getSaldo()>=15)
		it->debitar(15,"Cobranca de Tarifa");
    }
}

void banco::Banco::cpmf(){
    ListaDeContas::iterator itC;
    ListaDeMovimentacoes movimetacoesDaSemana;
    ListaDeMovimentacoes:: iterator itM;
    double Cpmf=0;

    time_t agora = time(NULL);
    tm* dataAtual = localtime(&agora);

    tm dataInicio = {0,0,0,dataAtual->tm_mday,dataAtual->tm_mon,dataAtual->tm_year};
    tm dataFim = {dataAtual->tm_sec,dataAtual->tm_min,dataAtual->tm_hour,dataAtual->tm_mday,dataAtual->tm_mon,dataAtual->tm_year};
    dataMaisDias(&dataInicio, -7);

    //percorre a lista de contas
    for(itC= this->contas.begin();itC != this->contas.end();itC++){
        movimetacoesDaSemana=itC->extratoDatas(dataInicio,dataFim);
        //soma todos os valores das movimentacoes de debito
        for(itM=movimetacoesDaSemana.begin();itM != movimetacoesDaSemana.end();itM++){
            if(itM->getDebitoCredito()=='D'){
               Cpmf=Cpmf+itM->getValor();
            }
        }
	Cpmf=Cpmf*0.0038;
        //debita 0.38% da conta
        if(itC->getSaldo()>=Cpmf){
            itC->debitar(Cpmf,"Cobranca de CPMF");
        }
    Cpmf=0;
    }
}

double banco::Banco::saldoConta(int numeroConta){
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

const ListaDeMovimentacoes banco::Banco::extratoMes(int numeroConta){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
         if(it->getNumeroConta() == numeroConta){
            return it->extratoMes();
         }
    }
}

const ListaDeMovimentacoes banco::Banco::extratoDataInicial(int numeroConta, tm inicio){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
         if(it->getNumeroConta() == numeroConta){
            return it->extratoDataInicial(inicio);
         }
    }
}

const ListaDeMovimentacoes banco::Banco::extratoDatas(int numeroConta, tm inicio, tm fim){
    ListaDeContas::iterator it;
    for(it= this->contas.begin();it != this->contas.end();it++){
        //conta encontrada
         if(it->getNumeroConta() == numeroConta){
            return it->extratoDatas(inicio,fim);
         }
    }
}
