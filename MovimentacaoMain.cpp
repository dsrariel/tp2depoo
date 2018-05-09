#include <iostream>
#include "Movimentacao.h"

 using namespace std;

 int main(){
    Movimentacao A("Movimentacao de teste", 'D', 232.00);

    cout << A.getDataMovimentacao() << " " << A.getDescricao() << " " << A.getDebitoCredito() << " " << A.getValor() << endl;

    return(0);
 }