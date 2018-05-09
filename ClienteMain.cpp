#include <iostream>
#include "Cliente.h"

 using namespace std;

 int main(){
    Cliente A("Jorge Silva", "053.160.443-80", "Rua 40, 14, Cohab Anil IV", "(31) 3244-3629");

    cout << A.getNomeCliente() << " " << A.getCpfCnpj() << " " << A.getEndereco() << " " << A.getTelefone() << endl;

    A.setNomeCliente("Adriana Silveira");
    A.setCpfCnpj("297.342.403-82");
    A.setEndereco("Rua Joao Fernandes, 121, Liberdade");
    A.setTelefone("(98) 3244-7615");

    cout << A.getNomeCliente() << " " << A.getCpfCnpj() << " " << A.getEndereco() << " " << A.getTelefone() << endl;
    return(0);
 }