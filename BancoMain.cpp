#include "Banco.h"
#include <iostream>
using namespace std;
using namespace banco;

int main(){
	Banco bnc=Banco("Banco do Brasil");
	Cliente A("Jorge Silva", "053.160.443-80", "Rua 40, 14, Cohab Anil IV", "(31) 3244-3629");
	Cliente B("Fernandes Silveira", "156.120.763-43", "Rua 99, 12, Cohab Anil IV", "(31) 3232-6776");
	
	bnc.inserirCliente(A);
	bnc.inserirCliente(B);
	bnc.inserirConta(A);
	bnc.inserirConta(B);
	

	ListaDeClientes clientes=bnc.getClientes();
	ListaDeContas contas=bnc.getContas();
	ListaDeMovimentacoes m;

	ListaDeClientes::iterator it=clientes.begin();
	ListaDeContas::iterator it1=contas.begin(),it9=contas.begin();
	ListaDeMovimentacoes::iterator it2;
	it9++;
	
	cout<<it->getNomeCliente()<<"  "<<it->getCpfCnpj()<<"  "<<it->getEndereco()<<"  "<<it->getTelefone()<<endl;
	
	bnc.depositar(it1->getNumeroConta(),150);
	contas=bnc.getContas();
	it1=contas.begin();
	cout<<"saldo:"<<it1->getSaldo()<<endl;

	bnc.tarifa();
	cout << "saldo: "<<bnc.saldoConta(it1->getNumeroConta()) <<endl;

	bnc.sacar(it1->getNumeroConta(),50);
	cout << "saldo: "<<bnc.saldoConta(it1->getNumeroConta()) <<endl;
	
	bnc.cpmf();
	cout << "saldo: "<<bnc.saldoConta(it1->getNumeroConta()) <<endl;
	
	m=bnc.extratoMes(it1->getNumeroConta());
	cout<< "Extrato do Mes:"<<endl;
	for(it2=m.begin(); it2!=m.end();it2++){
		cout<<it2->getDescricao()<<", " << it2->getDebitoCredito() <<", valor: "<<it2->getValor() <<endl;
	}
	
	
	bnc.transferencia(it1->getNumeroConta(), it9->getNumeroConta(), 62);
	cout << "Saldo da primeira conta: "<<bnc.saldoConta(it1->getNumeroConta()) <<endl;
	cout << "Saldo da outra conta: "<<bnc.saldoConta(it9->getNumeroConta()) <<endl;
	
	bnc.setDados();
	bnc.excluirConta(it1->getNumeroConta());
	bnc.excluirCliente(A.getCpfCnpj());
	
	return 0;
}
