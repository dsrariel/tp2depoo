#include <iostream>
#include "Movimentacao.h"

 using namespace std;

 int main(){
    Movimentacao A("Movimentacao de teste", 'D', 232.00);

    double valor;
    valor = A.getValor();
    valor += 30;

    cout << A.getDataMovimentacao() << " " << A.getDescricao() << " " << A.getDebitoCredito() << " " << valor << endl;

    return(0);
 }