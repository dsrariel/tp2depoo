#include "Conta.h"

int Conta::proximoNumeroConta = 0;

Conta::Conta(const Cliente &cliente){
    this->numeroConta = proximoNumeroConta;
    this->proximoNumeroConta++;
    this->saldo = 0;
    this->cliente = cliente;
}

//Getters
const int Conta::getNumeroConta(){
    return this->numeroConta;
}
const int Conta::getProximoNumeroConta(){
    return this->proximoNumeroConta;
}
const double Conta::getSaldo(){
    return this->saldo;
}
const Cliente Conta::getCliente(){
    return this->cliente;
}
const ListaDeMovimentacoes Conta::getMovimentacoes(){
    return this->movimentacoes;
}

//Outras funções
void Conta::debitar(const double valor, const std::string descricao){
    Movimentacao movimentacao(descricao, 'D', valor);
    this->movimentacoes.push_back(movimentacao);
}
void Conta::creditar(const double valor, const std::string descricao){
    Movimentacao movimentacao(descricao, 'C', valor);
    this->movimentacoes.push_back(movimentacao);
}

const ListaDeMovimentacoes Conta::extratoDatas(const tm dataInicio, const tm dataFim){  
    ListaDeMovimentacoes movimentacoesDoPeriodo;
    ListaDeMovimentacoes::iterator  iterador = this->movimentacoes.begin(), 
                                    fimLista = this->movimentacoes.end();
    int inclusa;
    tm data;

    //Itera pela lista até achar primeira data inclusa no período ou até que chegue ao fim da lista    
    while(iterador != fimLista){
        data = iterador->getDataMovimentacao();
        inclusa = dataEntreInicioEFim(data, dataInicio, dataFim);
        if (inclusa)
            break;
        iterador++;
    }

    //Como as movimentações são inseridas em ordem cronológica, assim que a movimentação não estiver mais inclusa no período,
    //não haverá mais movimentações a serem adicionadas
    while(iterador != fimLista){
        data = iterador->getDataMovimentacao();
        inclusa = dataEntreInicioEFim(data, dataInicio, dataFim);
        if (!inclusa) 
            break;
        movimentacoesDoPeriodo.push_back(*iterador);
        iterador++;
    }
    
    return movimentacoesDoPeriodo;
}

const ListaDeMovimentacoes Conta::extratoMes(){
    time_t agora = time(NULL);
    tm* dataAtual = localtime(&agora);
    
    tm dataInicio = {0,0,0,1,dataAtual->tm_mon,dataAtual->tm_year};
    tm dataFim = {0,0,0,31,dataAtual->tm_mon,dataAtual->tm_year};

    return this->extratoDatas(dataInicio, dataFim);
}

int dataEntreInicioEFim(const tm data, const tm inicio, const tm fim){
        tm data_aux = data, inicio_aux = inicio, fim_aux = fim;
        time_t  time_inicio = mktime(&inicio_aux), 
                time_fim = mktime(&fim_aux),
                time_data = mktime(&data_aux);

        if ((difftime(time_data, time_inicio) >= 0)&&(difftime(time_fim, time_data) >= 0)){
            return 1;
        }
        else{
            return 0;
        }
}
