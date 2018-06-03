#include "Conta.h"

int banco::Conta::proximoNumeroConta = 0;

banco::Conta::Conta(const Cliente &cliente){
    this->numeroConta = proximoNumeroConta;
    this->proximoNumeroConta++;
    this->saldo = 0;
    this->cliente = cliente;
}

banco::Conta::Conta(const Cliente &cliente,int numeroConta,int proximoNumeroConta, double saldo, const ListaDeMovimentacoes& movimentacoes){
    this->numeroConta = numeroConta;
    this->proximoNumeroConta = proximoNumeroConta;
    this->saldo = saldo;
    this->cliente = cliente;
    this->movimentacoes = movimentacoes;
}

//Getters
const int banco::Conta::getNumeroConta(){
    return this->numeroConta;
}
const int banco::Conta::getProximoNumeroConta(){
    return this->proximoNumeroConta;
}
const double banco::Conta::getSaldo(){
    return this->saldo;
}
const Cliente banco::Conta::getCliente(){
    return this->cliente;
}
const ListaDeMovimentacoes banco::Conta::getMovimentacoes(){
    return this->movimentacoes;
}

//Outras funções
bool banco::Conta::debitar(const double valor, const std::string descricao){
    Movimentacao movimentacao(descricao, 'D', valor);
    if (this->saldo >= valor){
        this->saldo -= valor;
        this->movimentacoes.push_back(movimentacao);
        return true;
    }
    else
        return false;
}
void banco::Conta::creditar(const double valor, const std::string descricao){
    Movimentacao movimentacao(descricao, 'C', valor);
    this->saldo += valor;
    this->movimentacoes.push_back(movimentacao);
}

const ListaDeMovimentacoes banco::Conta::extratoDatas(const tm dataInicio, const tm dataFim){  
    ListaDeMovimentacoes movimentacoesDoPeriodo;
    ListaDeMovimentacoes::iterator  iterador = this->movimentacoes.begin(), 
                                    fimLista = this->movimentacoes.end();
    int inclusa;
    tm data;

    //Itera pela lista até achar primeira data inclusa no período ou até que chegue ao fim da lista    
    while(iterador != fimLista){
        data = iterador->getDataMovimentacao();
        inclusa = banco::dataEntreInicioEFim(data, dataInicio, dataFim);
        if (inclusa)
            break;
        iterador++;
    }

    //Como as movimentações são inseridas em ordem cronológica, assim que a movimentação não estiver mais inclusa no período,
    //não haverá mais movimentações a serem adicionadas
    while(iterador != fimLista){
        data = iterador->getDataMovimentacao();
        inclusa = banco::dataEntreInicioEFim(data, dataInicio, dataFim);
        if (!inclusa) 
            break;
        movimentacoesDoPeriodo.push_back(*iterador);
        iterador++;
    }
    
    return movimentacoesDoPeriodo;
}

const ListaDeMovimentacoes banco::Conta::extratoDataInicial(const tm dataInicio){
    time_t agora = time(NULL);
    tm* dataAtual = localtime(&agora);
     
    tm dataFim = {dataAtual->tm_sec,dataAtual->tm_min,dataAtual->tm_hour,dataAtual->tm_mday,dataAtual->tm_mon,dataAtual->tm_year};

    return this->extratoDatas(dataInicio, dataFim);
}

const ListaDeMovimentacoes banco::Conta::extratoMes(){
    time_t agora = time(NULL);
    tm* dataAtual = localtime(&agora);
    
    tm dataInicio = {0,0,0,1,dataAtual->tm_mon,dataAtual->tm_year};
    tm dataFim = dataInicio;

    int numeroDeDiasDoMes;
    switch (dataFim.tm_mon)
    {
        case 0:
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11:
            numeroDeDiasDoMes = 31;
            break;
        case 1:
            if(dataFim.tm_year%4 == 0)
                numeroDeDiasDoMes = 29;
            else
                numeroDeDiasDoMes = 28;
            break;
        default:
            numeroDeDiasDoMes = 30;
            break;
    }
    
    banco::dataMaisDias(&dataFim, numeroDeDiasDoMes);
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

void dataMaisDias(tm* data, int dias){
    time_t diasEmSegundos = 24*60*60*dias;
    time_t dataEmSegundos = mktime(data) + diasEmSegundos;
    *data = *localtime(&dataEmSegundos);
}
