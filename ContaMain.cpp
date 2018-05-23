#include <iostream>
#include "Conta.h"

 using namespace std;

 int main(){
    Cliente A("Jorge Silva", "053.160.443-80", "Rua 40, 14, Cohab Anil IV", "(31) 3244-3629");
    Conta conta(A), outraConta(A), maisUmaConta(A);

    cout << conta.getNumeroConta() << " " << conta.getProximoNumeroConta() << " " << conta.getSaldo() << endl;
    cout << outraConta.getNumeroConta() << endl;
    cout << maisUmaConta.getNumeroConta() << endl;

    Cliente B = conta.getCliente();

    cout << B.getNomeCliente() << " " << B.getCpfCnpj() << " " << B.getEndereco() << " " << B.getTelefone() << endl;

    conta.creditar(1000, "Salario");
    conta.debitar(132.75, "Luz");

    ListaDeMovimentacoes extratoDatas;

    tm  a = {0,0,0,20,4,118}, //20 de maio de 2018
        b = {0,0,0,31,4,118}; //31 de maio de 2018
    
    extratoDatas = conta.extratoDatas(a, b);

    ListaDeMovimentacoes::iterator iterator = extratoDatas.begin();

    cout << "\n============DATAS============" << endl;
    while (iterator != extratoDatas.end()){
        char buffer[80];
        tm data = iterator->getDataMovimentacao();
        strftime (buffer, 80, "%d/%m/%Y", &data);
        cout << buffer << "\t" << iterator->getDebitoCredito() << "\t" << iterator->getDescricao() << "\t" << iterator->getValor() << endl;
        iterator++;
    }

    ListaDeMovimentacoes extratoMes;
    extratoMes = conta.extratoMes();
    iterator = extratoMes.begin();

    cout << "\n============MES============" << endl;
    while (iterator != extratoMes.end()){
        char buffer[80];
        tm data = iterator->getDataMovimentacao();
        strftime (buffer, 80, "%d/%m/%Y", &data);
        cout << buffer << "\t" << iterator->getDebitoCredito() << "\t" << iterator->getDescricao() << "\t" << iterator->getValor() << endl;
        iterator++;
    }

    return(0);
 }