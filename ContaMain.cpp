#include <iostream>
#include "Conta.h"

 using namespace std;

 int main(){
    Cliente A("Jorge Silva", "053.160.443-80", "Rua 40, 14, Cohab Anil IV", "(31) 3244-3629");
    Conta conta(1, A);

    cout << conta.getNumeroConta() << " " << conta.getProximoNumeroConta() << " " << conta.getSaldo() << endl;

    Cliente B = conta.getCliente();

    cout << B.getNomeCliente() << " " << B.getCpfCnpj() << " " << B.getEndereco() << " " << B.getTelefone() << endl;
    return(0);
 }