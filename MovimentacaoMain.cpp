#include <iostream>
#include "Movimentacao.h"

 using namespace std;

 int main(){
    Movimentacao A("Movimentacao de teste", 'D', 232.00);

    double valor;
    valor = A.getValor();
    valor += 30;

    tm data = A.getDataMovimentacao();

    cout << data.tm_mday << "/" << data.tm_mon+1 << "/" << data.tm_year+1900 << " " << A.getDescricao() << " " << A.getDebitoCredito() << " " << valor << endl;

    return(0);
 }